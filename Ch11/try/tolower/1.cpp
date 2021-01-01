#include <std_lib_facilities.h>

void to_low(string& s)
{
	for (char&c: s) c = tolower(c);
}

int main ()
{
	string a = "KOLOBOK";
	to_low(a);
	cout << a << '\n';
	keep_window_open();
}