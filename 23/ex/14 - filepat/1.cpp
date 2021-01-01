#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>

using namespace std;



class Pattern_from_file{
	
	public:
	Pattern_from_file(const string&,const string&,const string&); //pat_in,input,output
	ifstream init_ifstream(const string&);
	ofstream init_ofstream(const string&);
};

ifstream Pattern_from_file::init_ifstream(const string& s){
	ifstream ifs{s};
		if (!ifs){
			cout << "Cant open file\n";
			char c; cin >> c;
			 exit(1);
		}

	return ifs;
}

ofstream Pattern_from_file::init_ofstream(const string& s){
	ofstream ofs{s};
		if (!ofs){
			cout << "Cant open file\n";
			char c; cin >> c;
			 exit(1);
		}

	return ofs;
}


Pattern_from_file::Pattern_from_file(const string& pat_l, const string& rock, const string& out){
	ifstream pat_stream = init_ifstream(pat_l);
	ifstream in_stream 	= init_ifstream(rock);
	ofstream output 	= init_ofstream(out);

	string pat;
	for (char c; pat_stream.get(c);){
		pat += c;
	}
			
	string buf;
	for (char c; in_stream.get(c);){
		buf += c;
	}
			
	smatch sm;
	regex reg;
	try{
		reg = {pat};
	}
	catch(regex_error& r){
		cout << "Bad pattern\n";
		char c;
		cin >> c;
		exit(1);
	};
	
		if (regex_search(buf,sm,reg))
			cout << *sm.begin();
		else
			cout << "Empty line\n";
	
	 
	
	
	
};


int main(){
	
	string pat = R"(C:\Data\pat\pat.txt)";
	string in = R"(C:\Data\pat\in.txt)";
	string out = R"(C:\Data\pat\res.txt)";
	Pattern_from_file pff (pat,in,out);
	
	
	
	
	
	
	
	char c;
	cin >> c;
}