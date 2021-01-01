#include <std_lib_facilities.h>

ifstream read_file (string&s)
{
	ifstream ist {s};
	if (!ist) error ("Cant open file");
	return ist;
}

ofstream write_file (string& s)
{
	ofstream ost {s};
	if (!ost) error ("Cant open file");
	return ost;
} 


ifstream& operator >> (ifstream& ist,string&s)
{
	getline(ist,s);
	string b;
	for (char ch : s) {ch=tolower(ch); b+=ch;}
	s=b;

	return ist;
}


void to_low(string& s)
{
	for (char& ch : s) {ch=tolower(ch);}
	
}
int main ()
{
	string ss = "D:\\Programms\\Ch11\\ex\\1\\data\\1.txt";
	string bb = "D:\\Programms\\Ch11\\ex\\1\\data\\2.txt";
	ifstream ist = read_file(ss);
	ofstream ost = write_file(bb);
	string s;
	ist >> s;
	
	ost << s << '\n';
	
}