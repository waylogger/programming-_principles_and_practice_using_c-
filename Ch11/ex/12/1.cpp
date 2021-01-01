#include <std_lib_facilities.h>
const string adress_for_read = "D:\\Programms\\Ch11\\ex\\12\\data\\1.txt";
const string fstream_error = "Cant open file";

fstream read_file()
{
	fstream ist {adress_for_read, ios_base::in};
	if (!ist) error (fstream_error);
	return ist;
}

fstream write_file()
{
	fstream ost {adress_for_read, ios_base::out};
	if (!ost) error (fstream_error);
	return ost;
}

fstream& operator >> (fstream& ist, string& s)
{
	string box;
	while (true)
	{
		getline(ist,s);
		for (int i = s.size()-1; i < s.size() && i > 0;--i) box+=s[i];
		if (ist.eof()) break;
	}
	
	return ist;
}

int main ()
try
{
	string s;
	fstream ist = read_file();
	ist >> s;
	fstream ost = write_file();
	ost << s;
}

catch (exception& e)
{
	cerr << e.what () << '\n';
	keep_window_open("~~");	
}