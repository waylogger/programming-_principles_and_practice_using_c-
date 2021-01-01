#include <std_lib_facilities.h>

int main ()
{
	string iname, iname2,oname;
	
	cin >> iname >> iname2 >> oname;
	ifstream  ist {iname};
	ifstream  ist2 {iname2};
	ofstream ost {oname};
	for (string s; ist >> s;) ost << s << '\n';
	for (string s; ist2 >> s;) ost << s << '\n';
	
}