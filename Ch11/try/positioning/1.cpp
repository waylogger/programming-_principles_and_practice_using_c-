#include <std_lib_facilities.h>

int main ()
{
	string name = "D:\\Programms\\Ch11\\try\\positioning\\data\\1.txt";
	fstream fs {name};
	
	fs.seekg(5);
	char ch;
	fs >> ch;
	cout << ch << '\n';
	
	fs.seekp(6);
	fs << 'y';
	keep_window_open();
}