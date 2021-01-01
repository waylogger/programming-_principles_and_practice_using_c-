#include <std_lib_facilities.h>

ifstream read_file(const string& s)
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


double read_double (ifstream& ist)
{
	double d =0;
	ist >> d;
	return d;
}

void write_double (ofstream& ost, double& d)
{
ost << scientific << setprecision (8) << setw(20) << d << ' '; 
}


ifstream& operator >> (ifstream& ist, double& d)
{
	
	string oname = "D:\\Programms\\Ch11\\ex\\15\\data\\2.txt";
	ofstream ost = write_file(oname);
	int i = 0;
	while (d=read_double(ist))
	{
	++i;
	write_double (ost,d);
	if (i==4) {ost << '\n'; i=0;}
	}
	return ist;
}

int main ()
try
{
	string iname = "D:\\Programms\\Ch11\\ex\\15\\data\\1.txt";
	ifstream ist = read_file(iname);
	double d = 0;
	ist >> d;

	
	//keep_window_open();
	
}

catch (exception& e)
{
	cerr << e.what() << '\n';
	keep_window_open("~~");
}





















