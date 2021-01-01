#include<std_lib_facilities.h>

int main () 
{
	while (true)
	{
	string s = "";
	cin >> s;
	if(s=="in") {int i =0; cout << i+1 <<'\n';}
	if(s=="from")
	{
		ifstream ist {"D:\\Programms\\Ch10\\try\\alternat\\data\\input.txt"};
		ofstream ost {"D:\\Programms\\Ch10\\try\\alternat\\data\\output.txt"};
		int i = 0;
		ist >> i;
		ost << i+546 << '\n';
	}
	}
	keep_window_open();
}