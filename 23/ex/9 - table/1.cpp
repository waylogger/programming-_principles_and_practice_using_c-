#include <regex>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>

using namespace std;

const int its_header = -8360020;
const string& bad_header 	= "bad_header";
const string& bad_line 		= "bad_line";


template<typename T>
T from_string(const string& s){
	T t;
	ostringstream ost;
	ost << s;
	istringstream ist {ost.str()};
	ist >> t;
	return t;	
	
}


class Table{
	string lab;
	int fst;
	int sed;
	int total;
	string hdr;
	public:
	//-------------------------------
	Table(const string& h) 
		: hdr{h}, lab {"title"}, fst{its_header}, sed{its_header}, total{its_header}
		{	}
		
	void init_line(const string& h, const string& l, const int f, const int s, const int t){
		lab = {l}; fst = {f}; sed = {s}; total = {t}; hdr = {h};
	}
	//-------------------------------
	string lable() 			const {return lab;}
	string header() 		const {return hdr;}
	const int first() 		const {return fst;}
	const int second() 		const {return sed;}
	const int sum() 		const {return total;}
	//-------------------------------
	
	bool operator == (const Table& b) {return lab[0] == b.lab[0];}
	bool operator != (const Table& b) {return !(*this == b);}
	
	void set_label(const string& s) {lab = s;}
	
	Table operator+ (const Table& b) {
		fst = fst + b.fst;
		sed = sed + b.sed;
		total = total + b.total;
		return *this;
		}
	
};
ostream& operator << (ostream& ost, const Table& t) {
	if (t.sum() == its_header) 
		return 	ost << t.header();
	else return ost 	<< t.lable() << "\t\t" << t.first() << "\t\t"
						<< t.second() << "\t\t" << t.sum();
}



class Table_from_file{
	vector<Table>tab;
	public:
	Table_from_file(const string& s);
	ifstream init_stream();
	Table get_header(ifstream& ifs, const regex& s);
	Table get_line(ifstream& ifs, const regex& s);
	void print(ostream& ost, const vector<Table>&tab);
	void accumulate( Table& t, vector<Table>& target);
	vector<Table> unit();
	vector<Table> get_main_sequence () const {return tab;}
	
	
 	
};

ifstream Table_from_file::init_stream(){
	ifstream ifs{R"(D:\\data\\table.txt)"};

if (!ifs){
	cout << "Cant open file\n";
	char p;
	cin >> p;
	exit(1);
}

return ifs;

}
Table Table_from_file::get_header(ifstream& ifs, const regex& pat){
	
	string line;
	smatch match_head;
	if (getline(ifs,line) && regex_match(line,match_head,pat))
		return Table{line};
	
	return Table{bad_header};
	}
Table Table_from_file::get_line(ifstream& ifs, const regex& row){
	
	string line;
	smatch match;
	if (tab.size() == 0)
		Table{bad_line};
	
	if (getline(ifs,line) && regex_match(line,match,row)) {
		Table t = {tab[0]};
		
		int f = from_string<int>(match[2]);
		int s = from_string<int>(match[3]);
		int tot = from_string<int>(match[4]);
		
		t.init_line(t.header(),match[1],f,s,tot);
		
		if (match[1] == "ALLE KLASSER")
			ifs.setstate(ios_base::eofbit);
		
		return t;
	}
	
	
	return Table{bad_line};
}
Table_from_file::Table_from_file(const string& s){
	
	ifstream ifs = init_stream();
	regex header {R"(^[\w ]+(\t+[\w ]+)*$)"};
	regex row {R"((^[\w ]+)(\t+\d+)(\t+\d+)(\t+\d+)$)"};
	
	tab.push_back(get_header(ifs,header));
	
	if (tab[0].header() == "bad_table(header)"){
		cout << "Expected header\n";
		char c; cin >> c; exit(1);
	}
	
	while (ifs){
		Table t = get_line(ifs,row);
		if (t.header() != bad_header && t.header() != bad_line)
			tab.push_back(t);
	}
		
	 
}
void Table_from_file::accumulate( Table& t, vector<Table>& target){
	
	auto a = find(target.begin(),target.end(),t);
	if (a == target.end()){
		target.push_back(t);
		return;
	}
		
	for (int i =0; i < target.size(); ++i){
		string s;
		s += target[i].lable()[0];
		target[i].set_label(s);
		if (target[i] == t) {
			target [i] = target[i] + t;
			t.set_label(s);
		}	
	}	
}



vector<Table> Table_from_file::unit(){
	for (int i = 0; i < tab.size(); ++i){
			if (!isdigit(tab[i].lable()[0]))
			tab.erase(tab.begin()+i);
	}
	for (int i = 0; i < tab.size(); ++i){
			if (!isdigit(tab[i].lable()[0]))
			tab.erase(tab.begin()+i);
	}
		
	
	vector<Table>newtab;
	for (auto t : tab){
		accumulate(t,newtab);
	}
	
	sort(tab.begin(),tab.end(),[](Table a, Table b){return a.lable() < b.lable();});
	return newtab;
}



void Table_from_file::print(ostream& ost, const vector<Table>&tabl){
	
	
	
	for (auto t : tabl)
		ost << t << '\n';
}
	



int main(){


Table_from_file tff {R"(D:\data\table.txt)"};

vector<Table> ns = tff.unit();

tff.print(cout,ns);


char c;
cin >> c;

}