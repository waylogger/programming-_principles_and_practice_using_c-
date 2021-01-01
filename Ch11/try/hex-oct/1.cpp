#include<std_lib_facilities.h>

int main () 
{
	cout << showbase <<dec << 30 << '\t' << 9 << '\t' << 1991 << '\t' << 25 << "\t(decimal)\n";
	cout << showbase << hex << 30 << '\t' << 9 << '\t' << 1991 << '\t' << 25 << "\t(hexadecimal)\n";
	cout << showbase << oct << 30 << '\t' << 9 << '\t' << 1991 << '\t' << 25 << "\t(octal)\n";
	keep_window_open();
}