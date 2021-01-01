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

bool find_w(string& s, string& target)
{
	string extraction;

	for (int ii =0; ii<s.size();++ii) 
		{
		if (s[ii]!=' ') extraction+=s[ii];
		if (extraction==target) {return true;}
		if (s[ii]==' ') extraction.clear();
		}
		return false;
}


ifstream& operator >> (ifstream&ist, string& target)
{
	setlocale(0,"");
	cout << "Цель\n";
	cin >> target;
	
	string s = "";
	int i = 0;

	while (true)
	{
	getline(ist,s);
	++i;
	if (find_w(s, target)) cout << s <<  " - "<< i << '\n'; 
	if (ist.eof()) break;
	} 
	
	return ist;
}




int main ()
{
	string ss = "D:\\Programms\\Ch11\\ex\\2\\data\\1.txt";
	string target = "";
	ifstream ist = read_file(ss);
	while (true)
	{
		ist >> target;
		if (ist.eof()) break;
	}
	
	cout << '\n';
	keep_window_open();

	
}