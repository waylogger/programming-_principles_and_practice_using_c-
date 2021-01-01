#include <std_lib_facilities.h>

int main ()
{
	double d = 1234567.89;
	cout << defaultfloat << d << '\t';
	cout << fixed << d << '\t';
	cout << scientific << d << '\t';
	keep_window_open();
}