#include <std_lib_facilities.h>

int main ()
{
	string s = "D:\\Programms\\Ch11\\try\\files\\data\\1.txt";
	string ss = "";
	fstream fs (s,ios_base::out|ios_base::trunc);
	//ofstream fs {s};
	while (true)
	{
		
		cin >> ss;
		fs << ss;
		if (ss=="stop") break;
	}
	
		
	//keep_window_open();
}