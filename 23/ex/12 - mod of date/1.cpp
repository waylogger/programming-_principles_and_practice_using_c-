#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <windows.h>
#include <algorithm>
#include <cctype>

using namespace std;


const int not_month = -1;
class Date{
	int y = 0;
	int m = 0;
	int d = 0;
	public:
	Date(int yy, int mm, int dd) : y{yy}, m{mm}, d{dd} {}
	Date() {}

	int day() 	const {return d;}
	int month() const {return m;}
	int year() 	const {return y;}

	bool operator == (const Date& dd) 
		{return (y == dd.y)&&(m == dd.m)&&(d == dd.d);}
		
	bool operator != (const Date& dd)
		{return !(*this == dd);}


	};

const Date bad_date {-1111,-1,-1};

ostream& operator << (ostream& ost, const Date& d){
	ost << d.year() << '-';
	if (d.month() < 10) ost << '0';
	ost << d.month() << '-';
	if (d.day() < 10) ost << '0';
	ost << d.day();
	return ost;
};


template <typename T>
T from_string(const string& val){
	ostringstream ost {val};
	
	T t;
	istringstream ist {ost.str()};
	ist >> t;
	return t;

}

template <typename A, typename B>
B to_smt(const A& from){
	B to;
	ostringstream ost;
	ost << from;
	
	istringstream ist {ost.str()};
	ist >> to;
	
	return to;
}




class Text_from_file{
	vector<string>text;
	public:
	Text_from_file(const string&);
	ifstream init_ifstream(const string&);
	ofstream init_ofstream(const string&);
	int correction(string&,const smatch&);
	Date dd_mm_yy(string&,const smatch&);
	Date mm_dd_yy(string&,const smatch&);
	
};

ifstream Text_from_file::init_ifstream(const string&s){
	ifstream ifs {s};
	
	if (!ifs){
		cout << "Cant open file\n";
		char c;
		cin >> c;
		exit(1);
	}	
	return ifs;
};
ofstream Text_from_file::init_ofstream(const string& s){
	ofstream ofs {s};
	
	if (!ofs){
		cout << "Output: Cant open file\n";
		char c;
		cin >> c;
		exit(1);
	}
	return ofs;
}

int month_converter(const string& s){

	if 			(s == "January" 	|| s == "Jan" || s == "january" 	|| s == "jan")
		return 1;
	else if 	(s == "February" 	|| s == "Feb" || s == "february" 	|| s == "feb")
		return 2;
	else if 	(s == "March" 		|| s == "Mar" || s == "march" 		|| s == "mar")
		return 3;
	else if 	(s == "April" 		|| s == "Apr" || s == "april" 		|| s == "apr")
		return 4;
	else if 	(s == "May" 		|| s == "May" || s == "may" 		|| s == "may")
		return 5;
	else if 	(s == "June" 		|| s == "Jun" || s == "june" 		|| s == "jun")
		return 6;
	else if 	(s == "Jule" 		|| s == "Jul" || s == "jule" 		|| s == "jul")
		return 7;
	else if 	(s == "August" 		|| s == "Aug" || s == "august" 		|| s == "aug")
		return 8;
	else if 	(s == "September" 	|| s == "Sep" || s == "september" 	|| s == "sep")
		return 9;
	else if 	(s == "October" 	|| s == "Oct" || s == "october" 	|| s == "oct")
		return 10;
	else if 	(s == "November" 	|| s == "Nov" || s == "november" 	|| s == "nov")
		return 11;
	else if 	(s == "December" 	|| s == "Dec" || s == "december" 	|| s == "dec")
		return 12;
	
	else 
		return not_month;
	
}

Date Text_from_file::dd_mm_yy(string& rock,const smatch& match){
	
	int dd = 0, mm = 0, yy = 0;
	string month = match[2];
	dd = from_string<int>(match[1]);
	yy = from_string<int>(match[3]);
	if (isdigit(month[0])) 
		mm = from_string<int>(match[2]);
	else if (isalpha(month[0])){
		int m = month_converter(month);
		if (m == not_month){
			return bad_date;
		}
		mm = m;
	}
	
	return Date{yy,mm,dd};
}


Date Text_from_file::mm_dd_yy(string& rock,const smatch& match){
	int dd = 0, mm = 0, yy = 0;
	mm = month_converter(match[1]);
	if (mm == not_month)
		return bad_date;
	
	dd = from_string<int>(match[2]);
	yy = from_string<int>(match[3]);
	
	return Date{yy,mm,dd};
}


int Text_from_file::correction(string& rock, const smatch& match){
	
	string res = *match.begin();
	int inx = rock.find(res);
	
	Date date;
	string m = match[1];
	if (isdigit(m[0])) date = dd_mm_yy(rock,match);
	else if (isalpha(m[0])) date = mm_dd_yy(rock,match);
	else
		return -1;
		
	if (date == bad_date) 
		return -1;
	
		
	string cor = to_smt<Date,string>(date);
	
	rock.erase(rock.begin()+inx,rock.begin()+inx+res.size());
	string s1 = string(rock,0,inx);
	string s2 = string(rock,inx,rock.size()-1);
	
	rock = s1 + ' ' + cor + ' ' + s2;
	
	return 0;
}

Text_from_file::Text_from_file(const string& s){
	
	ifstream ifs = init_ifstream(s);
	string os;
	for (int i =0; s[i] != '.' && i < s.size(); ++i)
		os += s[i];
	
	ofstream ofs = init_ofstream(os + string("- mod.txt"));
	
	for (string s; getline(ifs,s);)
		text.push_back(s);
	
	//D01012001
	//D01 01 2001
	//D 01-01-2001
	//D-01-01-2001
	//D 01-01-2001
	//01-.\/ 01-.\/ 2001
	//03 March(Mar,march,mar) 2003
	
	regex reg_d_m {R"(\s*D?[\-\s\./\\]*(\d{1,2})[\-\s\./\\]+(\d{1,2}|\w+)[\-\s\./\\]+(\d{4})\s*)"};
	smatch sm;
	for (auto& q : text) 
		while (regex_search(q,sm,reg_d_m)){ //find
			int z = correction(q,sm); //change
			if (z != 0) {break;} //первый Не-форматный объект прекращает анализ строки(недостаток)
		}
		
	regex reg_m_d {R"( *(\w+)[ \\\-\.,\|/](\d{1,2})[ \\\-\.,\|/]+(\d{4}) *)"};
	for (auto& q : text) 
		while (regex_search(q,sm,reg_m_d)){ //find
			int z = correction(q,sm); //change
			if (z != 0) {break;} //первый Не-форматный объект прекращает анализ строки(недостаток)
		}
	
	for (auto q : text)
		ofs << q << '\n';
		
};


int main (){
	Text_from_file tff {R"(C:\Data\dt.txt)"};
	
	char c;
	cin >> c;
	
	
}