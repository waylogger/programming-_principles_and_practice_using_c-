#include <regex>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <chrono>
#include <unordered_map>


using namespace std;

using Line_iter = vector<string>::iterator;

class Message{
	Line_iter first;
	Line_iter last;
	public:
	Message(Line_iter a, Line_iter b) : first {a}, last{b} {}
	
	Line_iter begin() const {return first;}
	Line_iter end() const {return last;}
	
};

typedef vector<Message>::const_iterator Mess_iter;

struct Mail_file{
	
	vector<string>lines;
	vector<Message>m;
	Mail_file(const string& s);
	
	
	bool address_analys(const string& s);
	bool subject_analys(const string&s);
	void corrections();
	void place_deviders();
	Mess_iter begin() 	const 	{return m.begin();}
	Mess_iter end()		const {return m.end();}
		
};

bool Mail_file::address_analys(const string& s){
	regex pat {R"(From:.*)"}; 
	return regex_match(s,smatch{},pat);
}
bool Mail_file::subject_analys(const string& s){
	regex pat {R"(Subject:.*)"}; 
	return regex_match(s,smatch{},pat);
}
Mail_file::Mail_file(const string& s) {
	ifstream ifs {s};
	if (!ifs){
		cout << "Cant open file\n";		char c;		cin >> c;		exit(1);
	}
	for (string s; getline(ifs,s);){
		lines.push_back(s);
	}
	corrections();
	
	auto pp = lines.begin();
	for (auto p = lines.begin(); p != lines.end(); ++p){
		if (*p == "----"){
			m.push_back(Message(pp,p));
			pp = p + 1;
		}
	}
	
	
}
void Mail_file::place_deviders(){
	if (*(lines.end()-1) != "----")	lines.push_back("----");
	if (*(lines.begin()) != "----") lines.insert(lines.begin(),"----");
	
	int index = 0;
	for (auto b = lines.begin(); b != lines.end(); ++b, ++index){
		if (address_analys(*b)){
			lines.insert(b,"----");
			b = lines.begin() + index;
			++b; ++index;
		}
	}
	index = 0;
	for (auto b = lines.begin(); b != lines.end(); ++b, ++index){
		if (subject_analys(*b) && !address_analys(*(b-1))){
			lines.insert(b,"----");
			b = lines.begin() + index;
			++b; ++index;
		}
	}
}
void Mail_file::corrections(){
	place_deviders();
	bool new_message = false;
	int index = 0;
	for (auto b = lines.begin(); b != lines.end(); ++b, ++index){
			if (new_message){
				if (!address_analys(*b)) {
					lines.insert(b,R"(From: Unknown sender <Unknown address>)");
					b = lines.begin()+index;
				}
				++b; ++index;
				if (subject_analys(*b)){
					if (b+1 != lines.end() && subject_analys(*(b+1)))	{
						lines.insert(b+1,"----");
						b = lines.begin()+index;
					}
				}
				else {
					lines.insert(b,R"(Subject: Unknown subject)");
					b = lines.begin()+index;
				}
				new_message = false;	
				}
		if (*b == "----")	{
		while (b+1 != lines.end() && *(b+1) == "----")
			lines.erase(b+1);
			new_message = true;
		}	
	}
}
int is_prefix(const string&s, const string& p){
	int prf = p.size();
	
	if (string(s,0,prf) == p)
		return prf;
	
	return 0;
}
string find_sender(const Message* m){
	
	smatch sm;
	regex pat {R"(From:\s*)"};
	for (const auto& a : *m){
		if (regex_search(a,sm,pat))
			return sm.suffix();
	}
	
	return "";
}


string find_subject(const Message* m){
	regex pat {R"(Subject:\s*)"};
	smatch sm;
	
	for (const auto& a : *m){
		if (regex_search(a,sm,pat)){
			return sm.suffix();
		}
	}
	
	return "";
}


void read_to_multimap(){
	Mail_file mf{"D:\\data\\tm.txt"};
	
	
	multimap<string,const Message*> sender;
	
	for (const auto& a : mf){
		string s = find_sender(&a);
		
		if (s != "")
			sender.insert(make_pair(s,&a));
		}
		
	multimap<string,const Message*> sub;
	
	for (auto& a : mf){
		string s = find_subject(&a);
		if (s != "")
		sub.insert(make_pair(s,&a));
	}
	
	string q = "Wiki";
	for (auto e : sender){
		if (q == e.first)
			for (const auto& a : *e.second){
				//cout << a << '\n';
			}
	}
	
}

void read_to_unordered_multimap(){
	Mail_file mf{"D:\\data\\tm.txt"};
	
	
	unordered_multimap<string,const Message*> sender;
	
	for (const auto& a : mf){
		string s = find_sender(&a);
		
		if (s != "")
			sender.insert(make_pair(s,&a));
		}
		
	unordered_multimap<string,const Message*> sub;
	
	for (auto& a : mf){
		string s = find_subject(&a);
		if (s != "")
		sub.insert(make_pair(s,&a));
	}
	
	string q = "Wiki";
	for (auto e : sender){
		if (q == e.first)
			for (const auto& a : *e.second){
				//cout << a << '\n';
			}
	}
	
}

int main()
{
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	
	
	int n = 10;
	
	for (int i =0; i < n; ++i){
		auto t1 = chrono::system_clock::now();
	read_to_multimap();
	auto t2 = chrono::system_clock::now();
	cout << chrono::duration_cast<chrono::milliseconds>(t2-t1).count() << '\n';
	
	auto t3 = chrono::system_clock::now();
	
	read_to_unordered_multimap();
	auto t4 = chrono::system_clock::now();
	cout << chrono::duration_cast<chrono::milliseconds>(t4-t3).count() << '\n';
	}
	
	char c;
	cin >> c;
	
	
	
		
	
	
	
}