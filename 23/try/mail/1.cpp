#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>

using namespace std;


using Line_iter = vector<string>::const_iterator;

class Message
{
	Line_iter first;
	Line_iter last;
	
public:
	
	Message(Line_iter p1, Line_iter p2) : first{p1}, last{p2} {}
	Line_iter begin() 	const	{return first;}
	Line_iter end()		const	{return last;}
	
	
};


typedef vector<Message>::const_iterator Mess_iter;

struct Mail_file{
	string name;
	vector<string>lines;
	vector<Message>m;
	Mail_file(const string& n);
	Mess_iter begin()	const {return m.begin();}
	Mess_iter end() 	const {return m.end();}
	
};

struct File_except{
	string s;
		
	File_except(const string& ss) : s{ss} {}
};

void file_handle_error(const string &s) try {
	throw File_except{s};
}
catch(File_except& e){
	cerr << e.s << '\n'; 
	char c;
	std::cin >> c;
	exit(1);
};


Mail_file::Mail_file(const string& n){
	
	ifstream in{n};

	if (!in)
		file_handle_error("Cant find the file - " + n);
	
	for (string s; getline(in,s); )
		lines.push_back(s);
	
	auto first = lines.begin();
	for (auto p = lines.begin(); p != lines.end(); ++p){
		if (*p == "----"){
			m.push_back(Message(first,p));
			first = p + 1;
		}
		else if (p == lines.end()-1 && *p != "----")
			file_handle_error("Message should finished by ----");
	}
}

int is_prefix(const string& s, const string& p){
	int n = p.size();
	
	if (string(s,0,n) == p) return n; 
	
	
	return 0;
}


bool find_from_addr(const Message* m, string& s) {
 for (const auto& x : *m){
	 if (int n = is_prefix(x, "From: ")){
		  s = string(x,n);
		  return true;
		}
	 
	}
	return false;
}

string find_subject(const Message* m) {
	
	for (const auto& x : *m){
		if (int n = is_prefix(x, "Subject: "))
			return string(x,n);
	}
	return "";
};


int main(){
	Mail_file mfile = {"D:\\data\\mail.txt"};
	
	
	multimap<string, const Message*> sender;
	for (const auto& m : mfile)
	{
		string s;
		if (find_from_addr(&m,s))
			sender.insert(make_pair(s,&m));
	}
	
	
	auto pp = sender.equal_range("John Doe <jdoe@machine.example>");
	
	for (auto p = pp.first; p != pp.second; ++p)
		cout << find_subject(p->second) << '\n';
	
	
	char c =0;
	cin >> c;

}











