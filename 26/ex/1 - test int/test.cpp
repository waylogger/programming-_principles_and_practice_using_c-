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

struct Test{
	string label;
	int val;
	vector<int>seq;
	bool res;


	void init_seq(const string& s);
};


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


void Test::init_seq( const string & s ){
	
	
	string raw_material = s;
	
	regex reg {R"((\d+) ?)"};
	
	smatch match;
	
	while ( regex_search ( raw_material, match, reg ) ) {
			//cout 			<< match[0] 		<< '\n';
			seq.push_back( from_string_to< int > ( match[0] ) );
			raw_material 	= match.suffix();	
	}
	
	
}


//-----------------------------------------------------------------


istream& operator >> ( istream & ist, Test & t ){
	
	string				pat 		= R"(\{	(\w+)	(\d+)	\{	([\d ]*)	\}	(\d+)	\}$)"; 
	regex 				reg 		{ pat };
	smatch 				match;
	string 				buf;
	getline				(ist,buf);
	
	if ( regex_match ( buf,match,reg ) ){
		t.label 		= match[1];
		t.val 			= from_string_to< int >( match[2] );
	
		t.init_seq		( match[3] ); //convert seq "\d " to vector<int>
			
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


//-----------------------------------------------------------------


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
			cout << "\t\t\t\t\tTest if failed\n";		
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


void make_big_positive_test(vector< Test >& tests){
	Test big_test;
	
	for ( int i = 0; i < 10'000'000; ++i){
		big_test.seq.push_back(i);
	}
	
	big_test.label = "big_test9";
	big_test.val = 21022;
	big_test.res = true;
	
	tests.push_back(big_test);
}


//----------------------------------------------------------------------------

void make_big_negative_test(vector < Test >& tests){
	
	Test big_test2;
	
	for ( int i = 0; i < 10'000'000; ++i){
		if (i != 21022) 
			big_test2.seq.push_back(i);
	}
	
	big_test2.label = "big_test9";
	big_test2.val = 21022;
	big_test2.res = false;
	
	tests.push_back(big_test2);
	
}

//----------------------------------------------------------------------------

vector<int> make_randsize_seq(){
	vector<int>seq;
	int r = rand();
	for ( int i = 0; i < r; ++i ){
		seq.push_back(i);
	}
	return seq;
}

//----------------------------------------------------------------------------

void make_ten_randsize_seq(vector< Test >& tests){
	for (int i = 0; i < 10; ++i){
	Test t;
	string label = "test" + to_string_from<int>(tests.size());
	t.label = label;
	t.val = rand();
	t.seq = make_randsize_seq();
	t.res = false;
	for ( int i = 0; i < t.seq.size(); ++i ){
		if (t.seq[i] == t.val){
			t.res = true;
		}		
	}
	tests.push_back(t);
	}
	
	
}

//----------------------------------------------------------------------------

vector<int> make_rand_seq_size(const int n){
	vector<int> seq;
	
	for ( int i = 0; i < n; ++i ){
		seq.push_back(rand());
	}
	if (seq.size() != 0)
	sort(seq.begin(),seq.end());

	return seq;
}

//---------------------------------------------------

void make_ten_rand_seq(vector < Test >& tests){
	for (int i = 0; i < 10; ++i){
	Test t;
	string label = "test" + to_string_from<int>(tests.size());
	t.label = label;
	t.val = rand();
	t.seq = make_rand_seq_size(i);
	t.res = false;
	for ( int j = 0; j < t.seq.size(); ++j ){
		if (t.seq[j] == t.val){
			t.res = true;
		}		
	}
	tests.push_back(t);
	}
	
	
}



int main(){
	
	vector< Test >		tests 		= tests_from_file( R"(C:\Data\tests.txt)" );
	
	for (int i = 0; i < 10; ++i){
		
	make_big_positive_test(tests);
	make_big_negative_test(tests);
	
	make_ten_randsize_seq(tests);
	
	make_ten_rand_seq(tests);
	//testing(tests);
	cout << "Count of error: " << count_of_error(tests) << '\n';
	}
	char end;
	cin >> end;
	
}