/*
Antonyuk I.V. 29/04/2018

Stariy Oskol

PPP C+++ B.Stroustrup

tasks ch.26

bases of testing
test.cpp
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <cctype>
#include <C:\\Programms\\26\\task\\binary.h>
#include <list>
#include <chrono>
using namespace std;

//-----------------------------------------------------------------


template <typename T>
T from_string_to(const string& source){
	T dest;
	ostringstream ost {source};
	istringstream ist {ost.str()};
	ist >> dest;
	return dest;
}

//-----------------------------------------------------------------

template <typename T>
string to_string_from(const T& t){
	string dest;
	ostringstream ost;
	ost << t;
	istringstream ist {ost.str()};
	ist >> dest;
	return dest;
	
}


//-----------------------------------------------------------------


struct Test{
	string label;
	string val;
	vector<string>seq;
	bool res;


	void init_seq(const string& s);
};


//-------------------------------------------------------------------


void Test::init_seq( const string & s ){
	
	
	string raw_material = s;
	
	regex reg {R"((\w+) ?)"};
	
	smatch match;
	
	while ( regex_search ( raw_material, match, reg ) ) {
			//cout 			<< match[0] 	<< " a"	<< '\n';		
			seq.push_back( match[1] );
			raw_material 	= match.suffix();	
	}
	
	sort(seq.begin(),seq.end());
	
	
}


//-----------------------------------------------------------------


istream& operator >> ( istream & ist, Test & t ){
	
	string				pat 		= R"(\{	(\w+)	(\w+)	\{	([\w ]*)	\}	(\d+)	\}$)"; 
	regex 				reg 		{ pat };
	smatch 				match;
	string 				buf;
	getline				(ist,buf);
	
	if ( regex_match ( buf,match,reg ) ){
		t.label 		= match[1];
		t.val 			= match[2];
	
		t.init_seq		( match[3] ); //convert seq "\w " to vector<string>]
			
		int match4 		= from_string_to< int >( match[4] );
		if ( match4 != 0 )
			t.res 		= true;
		else
			t.res 		= false;

	}
	else
		cout			<< "Cant build test\n";
	

return ist;	
}


//-----------------------------------------------------------------


ostream& operator << (ostream& ost, const Test& t){

	ost <<	'{'	<< '\t' << t.label << '\t' << t.val << '\t' << '{' << '\t';
	
	
	for ( int i =0; i < t.seq.size(); ++i )
		ost << t.seq[i] << ' ';
	
	ost << '\t' << '}' << '\t' << t.res << '\t' << '}';
	return ost;
}



vector<Test> tests_from_file( const string& s ){
	
	vector< Test >	tests;
	ifstream		ifs				{s};
	
	if(!ifs){
					cerr << "I cant open file\n";
					return tests;
					
	}
	
	string			raw_material;
	
	
	while( getline( ifs,raw_material ) ){
		tests.push_back( from_string_to< Test > ( raw_material ) );
	}
	
	return			tests;
}


void testing(const vector<Test>& tests){
	
	for ( auto& t : tests ){
		cout << "--------------------------------------------------------\n";
		
		cout 	<< "Testname: " << t.label << '\n' << "looking: " << t.val << '\n'
				<< "in sequence:\n";
		if (t.seq.size() < 50)
		for ( auto& t2 : t.seq ){
				cout << t2 << ' ';
		}
		else
			cout << "with: " << t.seq.size() << " elem";
		cout	<< "\nexpection result: ";
		if ( t.res )
			cout << "true\n";
		else 
			cout << "false\n";
		cout << "--------------------------------------------------------\n";
		
		
		if (MY::binary_search(t.seq.begin(),t.seq.end(),t.val) == t.res) {
			cout << "\t\t\t\t\tTest is complete\n";
		}
		else
			cout << "\t\t\t\t\tTest is failed\n";		
	}
}

//----------------------------------------------------------------------------

int count_of_error(const vector<Test>& tests){
	
	int error = 0;
	for ( auto& t : tests ){
		
		if (MY::binary_search(t.seq.begin(),t.seq.end(),t.val) != t.res) {
			++error;
		}
				
	}
	
	return error;
}

//----------------------------------------------------------------------------



int main(){
	
	vector<Test> tests = tests_from_file(R"(C:\Data\tests.txt)");

	testing(tests);
	char end;
	cin >> end;
	
}