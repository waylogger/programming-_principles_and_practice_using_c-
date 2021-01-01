#include <std_lib_facilities.h>

ifstream input_file (string s)
{
	ifstream ist {s};
	if(!ist) error ("Cant open file");
	return ist;
}

ofstream output_file(string s)
{
	ofstream ost {s};
	if(!ost) error ("Cant open file");
	return ost;
}

double get (ifstream& ist)
{
	char c;
	ist.get(c);
	switch (c)
	{
		case '.':		case '0':
		case '1':		case '2':
		case '3':		case '4':
		case '5':		case '6':
		case '7':		case '8':
		case '9':
		{
		ist.putback(c);
		double d = 0;
		ist >> d;
		return d;
		}
	}
	return 0;
}


int main ()
try
{
ifstream ist = input_file("D:\\GD\Storage\\Programming\\Practice\\C++\\Ch10\\ex\\11\\data\\in.txt");
ofstream ost = output_file("D:\\GD\Storage\\Programming\\Practice\\C++\\Ch10\\ex\\11\\data\\out.bat");
int sum = 0;
while (true)
{
	sum+=get(ist);
	cout << sum << ' ';
	if (ist.eof()) break;
}



keep_window_open();
}

catch (exception& e)
{
	cerr << e.what() << '\n';
	keep_window_open("~~");
}
catch (...)
{
	cerr << "Unknown exception" << '\n';
	keep_window_open("~~");
}