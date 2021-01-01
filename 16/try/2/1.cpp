#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>

void calc ()
{
	string s;
	ostringstream ist {s};
	string ss = "igor";
	ist << ss;
	char c;
	string m = ist.str();
	
	for (int i =0; i < m.size(); ++i)
	{
		c = m[i];
		
		cout << c << '\n';
	}
}


int main () try {

calc();
keep_window_open();


}
catch (exception& e){
	cerr << e.what() << '\n';
	keep_window_open();
}
catch (...){
	cerr << "Unknown error" << '\n';
	keep_window_open();
}