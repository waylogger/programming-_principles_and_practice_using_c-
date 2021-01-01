#include <std_lib_facilities.h>
const double low_abs_min = -77777; 
const double too_hot = 500000000;
class Reading
{
	public:
	int d;
	double t;
	Reading () {}
	Reading (int dd, double tt) : d(dd), t(tt) {}
};
istream& operator>> (istream& is, Reading& r)
{
	char ch1,ch2,ch3,ch4,ch5;
	int hour =0;
	double temp;
	is >> ch1 >> hour >> ch2 >> ch3 >> ch4 >> temp >> ch5;
	r = Reading(hour,temp);
	return is;
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
		r.push_back(p);
	}
}
void stream_file_out (const double& d,const double& dd)
{
string oname;
cin >> oname;
ofstream ost {oname};
ost << "Mediana - "<< d  << "\n" << "Mid - " <<dd << '\n' ;
}
bool operator == (Reading& r, Reading rr)
{
	return r.d==rr.d&&r.t==rr.t;
}
void remove_el(vector<Reading>&r,int i)
{
	r.erase(remove(r.begin(),r.end(),r[i]));
}
void sort_vector(vector<Reading>&r)
{
double d = too_hot;
int ind = 0;
vector<Reading>s_r = r;
r.clear();
while(s_r.size()!=0)
	{
		for (int i = 0; i<s_r.size();++i)
		{
		if (d>s_r[i].t) {d=s_r[i].t; ind=i;};
		}
		r.push_back(s_r[ind]);
		remove_el(s_r,ind);
		ind = 0;
		d = too_hot;
	}
}
double mediana_temps (const vector<Reading>& r)
{
	vector<Reading>p = r;
	sort_vector(p);
	int i_f =0;
	int i_b=p.size()-1;
	int midle =0;
	if (p.size()%2!=0)
	{
		while (i_f<p.size() && i_b>=0)
		{
			++i_f;
			--i_b;
			if (i_f==i_b) {midle = i_f; break;}
		}
	return p[midle].t;
	}
	if (p.size()%2==0)
	{
		while (i_f<p.size() && i_b>=0)
		{
			++i_f;
			--i_b;
			if ((i_f+1)==i_b) {midle = i_f; break;}
		}
	return p[(midle)].t+p[(midle+1)].t;
	}
	return 1;
	
}
double midle_temps (const vector<Reading>&r)
{
	double d = 0;
	for (int i =0; i<r.size();++i) d+=r[i].t;
		return d/r.size();
}


int main () 
try 
{
	Reading p;
	vector<Reading>vp;
	stream_file_in(vp);
	double mid = midle_temps(vp);
	double med = mediana_temps (vp);
	stream_file_out (med,mid);
	
	keep_window_open();
}
catch (exception&e)
{
	cerr << e.what() << '\n';
	keep_window_open("");
}
