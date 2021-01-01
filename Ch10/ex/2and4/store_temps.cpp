#include <std_lib_facilities.h>

const double low_abs_min = -77777; 
const double too_hot = 500000000;
class Reading
{
	public:
	int d;
	double t;
	string s;
	Reading () {}
	Reading (int dd, double tt, string ss) : d(dd), t(tt), s(ss) {}
};
istream& operator>> (istream& is, Reading& r)
{
	{
	string s = " ";
	int hour =0;
	double temp;
	is >> hour >> temp >> s;
	r = Reading(hour,temp,s);
	return is;
}
}
ostream& operator<< (ostream& os, const vector<Reading>& t)
{
	os  << "[hour]" << '|' << "[Temp]\n";
	for (int i =0; i<t.size();++i)  
	{
	os << "["<<t[i].d << "]|[" << t[i].t << t[i].s << "]\n"<< '\n';
	}
	return os;
	
}
bool operator == (Reading& r, Reading rr)
{
	return r.d==rr.d&&r.t==rr.t;
}
void stream_file_in(vector<Reading>&r)
{
	string iname;
	cin >> iname;
	ifstream ist {iname};
	
	Reading p;
	while (ist >> p)
	{
		if  (ist.fail()) ist.clear();
		if (p.d<0 || 23<p.d) error ("Uncorrect time");
		r.push_back(p);
	}
}
void stream_file_out (const vector<Reading>&r)
{
string oname;
cin >> oname;
ofstream ost {oname};
ost << r;
}
double C_to_F(double& d)
{
	return (d*1.8)+32;
}

void C_to_F (vector<Reading>&r)
{
	for (int i =0; i<r.size();++i)
	{
		if (r[i].s=="C") {r[i].s="F", r[i].t=C_to_F(r[i].t);}
	}
}




int main () 
try
{
Reading r;
vector<Reading>v_r;
stream_file_in(v_r);
C_to_F(v_r);
stream_file_out(v_r);
keep_window_open();
}
catch (exception& e)
{
	cerr << e.what() << '\n';
	keep_window_open ("~~");
}





















