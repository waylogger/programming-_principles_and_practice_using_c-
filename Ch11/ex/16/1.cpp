#include <std_lib_facilities.h>

class Numbers 
{
	public:
	double digit;
	int duplic;
	Numbers(double d, int i) : digit(d), duplic (i) {}
	Numbers(double d) : digit(d), duplic (0) {}
};


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

void sorting_vec (vector<Numbers>& num)
{
	double min =97878744877548;
	vector<Numbers>buf = num;
	num.clear();
	int ix =0;
	int size = buf.size();
	
	
	
	for (int i2 = 0; i2 < size;++i2)
	{
		min=97878744877548;
	for (int i =0; i<buf.size();++i) 
		if (buf[i].digit<min) 
		{
			min=buf[i].digit;
			ix = i;
		}
		
		num.push_back(buf[ix]);
		buf.erase(buf.begin()+ix);
	}
	
}

void write_double (ofstream& ost, vector<Numbers>& num)
{
	sorting_vec(num);
	for (int i =0; i < num.size();++i) 
	{
		ost 	<< num[i].digit << ' ';
		if (num[i].duplic!=0) ost << num[i].duplic << '\n';
		else ost << " " << '\n';
	}
	
}

int dupcicates (double& d)
{
	string s = "D:\\Programms\\Ch11\\ex\\16\\data\\1.txt";
	ifstream ist {s};
	int i = 0;
	double dd = 0;
	while (ist >> dd)
	{
		
		if (dd==d) ++i;
		
	}
	if (i == 1) i = 0; 
	return i;
	
}

 bool is_dublicate (const double& d, const vector<int>& dups)
{
	for (double dd : dups) if (dd==d) return true;
	return false;	
} 
ifstream& operator >> (ifstream& ist, double& d)
{
	
	string oname = "D:\\Programms\\Ch11\\ex\\16\\data\\2.txt";
	ofstream ost = write_file(oname);
	vector<int>dups;
	vector<Numbers>num;
	
	int duplic =0;
	
	while (d=read_double(ist))
	{
	duplic= dupcicates (d);
	Numbers n = {d,duplic};
	if (!is_dublicate(d,dups)) num.push_back(n);
	if (duplic>0) dups.push_back(d);
	}
	write_double(ost,num);
	
	return ist;
}

int main ()
try
{
	string iname = "D:\\Programms\\Ch11\\ex\\16\\data\\1.txt";
	ifstream ist = read_file(iname);
	double d = 0;
	ist >> d;

	
//	keep_window_open();
	
}

catch (exception& e)
{
	cerr << e.what() << '\n';
	keep_window_open("~~");
}





















