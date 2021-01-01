#include <std_lib_facilities.h>


int main ()
{
int a;
int b;
int c;
int d;
cin.unsetf(ios::dec);
cin.unsetf(ios::hex);
cin.unsetf(ios::dec);
cin >> a >> b  >> c >> d;
cout << a  << '\t' << b << '\t' << c << '\t' << d << '\n'; 
keep_window_open();
}