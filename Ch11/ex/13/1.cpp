#include <std_lib_facilities.h>

vector<string> read_file(const string&s)
{
	ifstream ist {s};
	if (!ist) error ("Cant open file");
	
	vector<string>vs;
	for (string ss; ist >> ss;) vs.push_back(ss);
	
	return vs;
 }
 
 void write_file_back (vector<string>&vs, const string& s)
 {
	 ofstream ost {s};
	 if (!ost) error ("Cant open file");
	
	 
	 for (int i = vs.size()-1;i>=0;--i) ost << vs[i] << ' ';

	 
 }
 
int main ()
{
	string iname = "D:\\Programms\\Ch11\\ex\\13\\data\\1.txt";
	string oname = "D:\\Programms\\Ch11\\ex\\13\\data\\2.txt";
	
	
	vector<string>vs = read_file(iname);
	write_file_back(vs,oname);
	
}