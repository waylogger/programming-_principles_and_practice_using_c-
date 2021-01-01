#include <std_lib_facilities.h>
const int not_a_reading = -7777;
const int not_a_month = -1;

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

bool is_valid (const Reading& r);

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
	char ch1 = ' ';
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
	is >> d >> h >>t >>ch2;
	if (!is || ch2 != ')') error ("Bad note");
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
string mm;
is >> month_maker >> mm;
if (!is || month_maker!="month")
	error ("Bad start Month");
//m.month=month_to_int(mm);

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

constexpr int implausible_min =-200;
constexpr int implausible_max = 200;

bool is_valid(const Reading& r)
{
	if (r.day<1 || 31<r.day) return false;
	if (r.hour<0 || 23<r.hour) return false;
	if (r.temperature < implausible_min || implausible_max>r.temperature)
		return false;
	return true;
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
while (true)
{
	Month m;
	if (!(is >> m)) break;
	y.month[m.month] = m;
}
end_of_loop(is,'}',"Bad and of Year");
return is;
}


void print_year (Year&y) 
{
	cout << y;
}


int main ()
try
{
	cout << "Name\n";
	string iname;
	cin >> iname;
	ifstream ist {iname};
	if (!ist) error ("Cant open file",iname);
	
	cout << "Name\n";
	string oname;
	cin >> oname;
	ofstream ost {oname};
	if (!ost) error ("Cant open file",oname);
	
	vector<Year>ys;
	
	while (true)
	{
		Year y;
		if (!(ist>>y)) break;
		ys.push_back(y);
	}
	cout << "Read " << ys.size() << " year note\n";
	print_year(ys[0]);
	//for (Year&y : ys) print_year(ost,y);
	keep_window_open();
	
}


catch (exception& e)
{
	cerr << e.what() << '\n';
	keep_window_open("~~");
}





























