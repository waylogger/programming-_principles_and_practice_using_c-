#include<std_lib_facilities.h>

int main ()
{
	int a;
	char b;
	
	cin >> a;
	if (!cin) {cin.clear();
	cin >> a;
	//cin.putback(a);
	//cin >> b;
	cout << a << '\n';
	keep_window_open();
}