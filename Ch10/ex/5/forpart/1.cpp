#include <std_lib_facilities.h>

const int not_a_reading = -7777;
const int not_a_month = -1;
constexpr int implausible_min =-200;
constexpr int implausible_max = 200;


struct Day
{
	vector<double>hour {vector<double>(24,not_a_reading)};
};
struct Month {
	
	int month = {not_a_month};
	vector<Day>day {32};
};

struct Year
{
	int year;
	vector<Month>month {12};
};
struct Reading
{
	int day;
	int hour;
	double temperature;
};

bool is_valid(const Reading& r)
{
	if (r.day<1 || 31<r.day) {cout << 1; return false;}
	if (r.hour<0 || 23<r.hour) {cout << 2; return false;}
	if (r.temperature < implausible_min || implausible_max<r.temperature)
		{cout << 3 << " t-"<<r.temperature <<'\n'; return false;}
	return true;
}

void end_of_loop (istream& ist, char term, const string& mes) 
{
	if (ist.fail())
	{
		ist.clear();
		char ch;
		if (ist >> ch && ch == term) return;
		error (mes);
	}
}

istream& operator >> (istream&is, Reading& r)
{
	char ch1;
	if (is >> ch1 && ch1 != '(')
	{
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}
	char ch2;
	int d;
	int h;
	double t;
	is >> d >> h >>t >> ch2;
	if (is.fail()) { return is;}
	if (!is) error ("Bad note - !is");
	if (ch2 != ')') error ("Bad note = ')'");
	r.day = d;
	r.hour = h;
	r.temperature = t;
	return is;
}

istream& operator>>(istream&is, Month& m)
{
char ch =0;
if(is >> ch && ch!='{' ) 
	{
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

string month_maker;
int mm;
is >> month_maker >> mm;
if (!is)	error ("Bad start Month - !is");
if  (month_maker!="month") error ("Bad start Month - maker");
m.month=mm;

Reading r;
int duplicates =0;
int invalids =0;
for (Reading r; is >>r;)
{
	
	if (is_valid(r))
	{
		if (m.day[r.day].hour[r.hour] != not_a_reading)
			++duplicates;
		m.day[r.day].hour[r.hour] = r.temperature;
	}
	else ++invalids;
}

if (invalids)
	error ("Bad data in Month, all -", invalids);
if (duplicates)
	error ("Repeting data in Month, all - ", duplicates);
end_of_loop (is,'}',"Bad end of Month");
return is;
}

istream& operator>> (istream& is, Year& y)
{
char ch;
is >> ch;
if (ch!='{') {is.unget();is.clear(ios_base::failbit); return is;}
string year_maker;
int yy;
is >> year_maker >> yy;
if (!is || year_maker!="year") error ("Bad start of Year");
y.year = yy;
int i =0;
while (true)
{
	Month m;
	if (!(is >> m)) break;
	if (m.month > not_a_month) y.month[m.month] = m;
}
end_of_loop(is,'}',"Bad and of Year");
return is;
}

ostream& operator << (ostream& os, Reading& r)
{
	return os << "Day|Hour|Temp\n" << "   " << r.day << '|' << r.hour << '|' << r.temperature << '|';
}
ostream& operator << (ostream&os, Day& d)
{
	
	for (int i = 0; i < d.hour.size(); ++i) {if (d.hour[i] != not_a_reading)
		os << ", hour - " << i << ", temperature - " << d.hour [i];}
	return os;
}

ostream& operator << (ostream&os, Month& m)
{
	
	for (int i=1; i<m.day.size();++i) 
	{
		for (int i2=0;i2<m.day[i].hour.size();++i2)
		{
			if (m.day[i].hour[i2]!=not_a_reading) {os << "Day - " << i << m.day[i] << '\n'; break;};
		}
	}
	return os;
}

ostream& operator << (ostream& os, Year& y)
{
	os << "Year - " << y.year << ":\n";
	for (int i = 0; i<y.month.size();++i) 
	{
		if (y.month[i].month!=not_a_month)os 	<< "month - " << i << ":\n" << y.month[i] << "\n";
	}

	return os;
}

ifstream file_stream_in (string& iname, const string error_mes)
{
	cin >> iname;
	ifstream ist {iname};
	if (!ist) error (error_mes,iname);
	
	ist.exceptions(ist.exceptions()|ios_base::badbit);
	return ist;
}

ofstream file_stream_out (string& oname, const string error_mes)
{
	cin >> oname;
	ofstream ost {oname};
	if (!ost) error (error_mes,oname);	
	return ost;
}

void read_circle (ifstream& ist, vector<Year>&ys)
{
	while (true)
	{
		
		Year y;
		if (!(ist>>y)) break;
		ys.push_back(y);
		
	}
	
}



void print_circle(vector<Year>& ys)
{
	for (int i = 0 ; i < ys.size(); ++i) cout << ys[i] << '\n';
}

void file_print_circle(ofstream& ost, vector<Year>& ys)
{
	for (Year&y : ys) ost << y << '\n';
}
int main ()
try
{
	while (true)
	try {
	string adress_in = " ";
	string adress_out = " ";
	
	
	const string error_mes = "Cant open file\n";
	
	cout << "Path input\n";
	ifstream is = file_stream_in(adress_in,error_mes);
	
	cout << "Path output\n";
	ofstream os = file_stream_out(adress_out,error_mes);
		
	vector<Year>ys;
	read_circle(is,ys);
	file_print_circle(os, ys);
	cout << "Read " << ys.size() << " year note\n";
	
	}
	catch (exception& e)
	{
	cerr << e.what() << '\n';
	keep_window_open("~~");
	}
	keep_window_open();
	
}


catch (exception& e)
{
	cerr << e.what() << '\n';
	keep_window_open("~~");
}

