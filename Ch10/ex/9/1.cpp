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

int main ()
try
{

ifstream ist = input_file ("D:\\Programms\\Ch10\\ex\\9\\data\\1.txt");
ifstream ist2 = input_file ("D:\\Programms\\Ch10\\ex\\9\\data\\2.txt");
ofstream ost = output_file ("D:\\Programms\\Ch10\\ex\\9\\data\\3.txt");
string s1, s2;


while (true)
{
while (ist >> s1 && ist2 >> s2)
{
if (s1<s2) cout << s1 << ' ';
if (s1>=s2) cout << s2 << ' ';
}
if(ist.eof() || ist2.eof()) break;

}

cout << '\n';
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