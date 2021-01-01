#include <std_lib_facilities.h>

vector<char>ch = {'a','e','i','o','y','u'};

ifstream read_doc (string& s)
{
	ifstream ist {s};
	if (!ist) error ("Cant open file");
	return ist;
}

ofstream write_doc(string& s)

{
	ofstream ost {s};
	if (!ost) error ("Cant open file");
	return ost;
}


void translate (string& s)
{
	for (int i = 0; i<s.size();++i) 
		for (char& c : ch) if (s[i]==c) s.erase(s.begin()+i);
} 
int main ()
try
{
	string iname = "D:\\Programms\\Ch11\\ex\\3\\data\\1.txt";
	ifstream ist = read_doc(iname);
	string s;
	getline(ist,s);
	translate(s);
	
	ofstream ost = write_doc(iname);
	ost << s;
	
}
catch (exception& e)
{
	cerr << e.what() << '\n';
	keep_window_open();
}