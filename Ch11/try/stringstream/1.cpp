#include<std_lib_facilities.h>

int string_to_int (string s)
{
	int i = 0;
	istringstream iss {s};
	iss >> i;
	return i;
}


int main ()
{
	string s = "864";
	int i = string_to_int(s);
	cout << i << '\n';
	ostringstream oss;
	oss << i;
	
	cout << oss.str().c_str() << '\n';
	keep_window_open();
}