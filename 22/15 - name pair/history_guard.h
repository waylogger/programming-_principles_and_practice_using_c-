#ifndef HISTORY_GUARD
#define HISTORY_GUARD


#include <string>
#include <iostream>

namespace lang_history {

using std::string;
using std::cerr;

//----------------------------------------------------
	
class Bad_primary{
	string c = "In stream bad primary - ";
	public:
	string what() {return c;} 
	
	Bad_primary(const char cc) {
		
	
			c = c + '\'' + cc + '\'';
		}
};

//----------------------------------------------------



class Destroyed_expectations {
	string c = "Expect - ";
	public:
	string what() {return c;} 
	
	Destroyed_expectations(const char expect) {
		
			c = c + '\'' + expect + '\'';
		}
		
	Destroyed_expectations(const string expect) {
		
			c = c + '\'' + expect + '\'';
		}
};


//----------------------------------------------------


void exception_primary(const char c);
		
//----------------------------------------------------

void destroyed_expectations(const char expect);

//----------------------------------------------------

void destroyed_expectations(const string expect);


} // end of namespace

#endif