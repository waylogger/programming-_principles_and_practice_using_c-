#include <std_lib_facilities.h>

int main ()
{
/* 	int birth_year = 1234;
	cout << showbase << dec << birth_year << "(decimal)" <<'\t';
	cout << showbase << oct << birth_year << "(hex)" <<'\t';
	cout << showbase << hex << birth_year << "(oct)" <<'\t';
	cout << '\n';
	cout << dec << 24 << '\n'; */
	
	int a =0;
	int b =0;
	int c =0;
	int d =0;
	cin >> dec >> a >> oct >> b >> hex >> c >> d;
	cout << a << '\t';
	cout << b << '\t';
	cout << c << '\t' << d << '\n';
	
	keep_window_open();
}