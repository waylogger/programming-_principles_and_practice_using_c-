#include<D:\Programms\Ch9\Rep\Date\Chrono.h>

namespace Chrono { // open namespace Chrono

Date::Date(int dd, Month mm, int yy) 
	: d{dd}, m{mm},y{yy}
{
	if (!is_date(dd,mm,yy)) error ("Ups,,,");
}

const Date& default_date()
{
	static Date dd = {1,Month::jan,2001};
	return dd;
}

Date::Date()
	:
	d{default_date().day()}, 
	y{default_date().year()},
	m{default_date().month()}	
{
}

void Date::add_day(int n) //добавляем день
{
int days_in_month = 31;
for (int i=0;i<n;++i)
	{
	int days_in_month = 31; //определяем максимальное количество дней в месяце
	switch(m)
	{
	case Month::feb:
	days_in_month=(leapyear(y))?29:28;
	break;
	case Month::apr: case Month::jun:
	case Month::sep: case Month::nov:
	days_in_month = 30;
	break;
	}
	if (d==days_in_month) {d=0; add_month(1);} // если количество дней сравнялось с максимумом, то обнуляем счетчик дней и отщелкиваем 1 месяц
	d+=1;
	
	}
}

void Date::add_month(int n) //прибавляем месяц
{
	int z;
	z = int(m);
	for (int i =0; i<n;++i) 
	{
		if (Month(z)==Month::dec) {z=0; add_year(1);} //если встречаем декабрь, то отщелкиваем год и обнуляем месяц
		z+=1;
		
	}
	
	m = Month(z);
	
}

void Date::add_year(int n) //прибавляем год.
{
	if (m==Month::feb && d==29
		&& !leapyear(y+n)) {
			m = Month::mar;
			d = 1;
		}
		y+=n;
}

//вспомогательные функции

bool is_date(int d, Month m, int y)
{
	//полагаем корректным
	if (d<=0) return false;
	if (m<Month::jan || Month::dec<m) return false;
	int days_in_month = 31;
	switch (m) {
		case Month::feb:
		days_in_month = (leapyear(y))?29:28;
	break;
	case Month::apr: case Month::jun:
	case Month::sep: case Month::nov:
	days_in_month = 30;
	break;
	}
	if (days_in_month<d) return false;
	return true;
}


bool leapyear (int y)
{
	if (y%4==0) return true;
	return false;
}

bool operator == (const Date&a, const Date& b)
{
	return a.day() == b.day()
	&&     a.month()== b.month()
	&& 	   a.year()  == b.year();
}

bool operator != (const Date&a, const Date& b)
{
	return !(a==b);
}

bool operator < (const Date&d, const Date& dd)
{
	if (d.year()<dd.year()) return true;
	if(d.year()==dd.year()
	&&
	d.month()<dd.month()) return true;
	if (d.year()==dd.year()
	&&
	d.month()==dd.month()
	&&
	d.day()<dd.day()) return true;
	return false;
	
}

bool operator > (const Date&d, const Date& dd)
{
	if (d.year()>dd.year()) return true;
	if(d.year()==dd.year()
	&&
	d.month()>dd.month()) return true;
	if (d.year()==dd.year()
	&&
	d.month()==dd.month()
	&&
	d.day()>dd.day()) return true;
	return false;
	
}

ostream& operator << (ostream& os, const Date& d)
{
	return os	<< d.day () << '.' 
				<< int (d.month())
				<< '.' << d.year()<< '\n'; 
}



istream& operator >> (istream& is, Date& dd)
{
	int y =0;
	int m =0;
	int d =0;
	char ch1, ch2;
	is >> d >> ch1 >> m >> ch2 >> y;
	if (ch1!='.'&&ch2!='.') is.clear(ios_base::failbit);
	dd = Date(d, Month(m),y);
	return is;
}


enum class Day {
	monday,tuesday,wednesday,
	thursday,friday,saturday, sunday
};

Day day_of_week(bool print, const Date&e) //определяем день недели
{
	int i2 =0;
	int days_midle =0;
	Date d = e;
	Day c = Day(1);
	Date dd = {01,Month::jan,2001}; //точка отсчета
	
	if (d == dd) return c;
	if (d<dd) days_midle=midle_days(d,dd)-1; //находим разницу в днях между точкой отсчета и датой
	if (dd<d) days_midle=midle_days(dd,d);
	
	for (int i =0; i<days_midle;++i)
	{
		++i2;
		if (i2>int(Day::sunday)) {i2=int(Day::monday);}; //зацикливаем переход дней
		c = Day(i2);
	}
	if (print) print_day (c); //печатаем день, если true
	return c;
}


Date next_sunday (const Date& d) //дату следующего воскресенья
{
	Date e = d;
	Day t = day_of_week(false,d);
	while (t!=Day::sunday) 
	{
		e.add_day(1);
		t = day_of_week(false,e);
	}
	cout << "Next sunday is - " << e;
	
	return d;
}

Date next_weekday(const Date&d) //следующий будний день
{
	Date e = d;
	e.add_day(1);
	Day t = day_of_week(false,e);
	if (t == Day :: friday)		{t = Day :: monday; e.add_day(3);}
	if (t == Day :: sunday) 	{t = Day :: monday; e.add_day(1);}
	if (t == Day :: saturday) 	{t = Day :: monday; e.add_day(2);}
	cout << "Next weekday is - " << e;
	
	return d;
}

Date next_workday(const Date&d) //следующий рабочий день
{
	Date e = d;
	e.add_day(1);
	Day t = day_of_week(false,e);
	if (t == Day :: friday)		{t = Day :: monday; e.add_day(3);}
	if (t == Day :: sunday) 	{t = Day :: monday; e.add_day(1);}
	if (t == Day :: saturday) 	{t = Day :: monday; e.add_day(2);}
	cout << "Next workday is - " << e;
	
	return d;
}

int week_of_year(const Date& d)  // сколько недель прошло с начала года
{
	Date e = d;
	Date def = {01,Month::jan,e.year()};
	Day t = day_of_week(false, def);
	
	int i = midle_days(def, e);
	
	int weeks = 0;
	for (int i2 = 0; i2 < i;++i2) 
	{
	if (t==Day::monday) ++weeks;
	def.add_day(1);
	t = day_of_week(false, def);
	}
	cout << "Between start of year and currect date - " << weeks << " weeks\n";
	return weeks;
}
int midle_days (const Date& d, const Date& dd) //сколько дней между двумя датами
{
	Date c = d;
	Date cc = dd;
	int i = 0;
	while (c!=cc)
	{
		c.add_day(1);
		++i;
	}
	return i;
}

void print_day (Day& c) // печатаем день
{
	if (c==(Day(0))) cout << "Monday\n"; 	if (c==(Day(1))) cout << "Tuesday\n";
	if (c==(Day(2))) cout << "Wednesday\n"; if (c==(Day(3))) cout << "Thursday\n";	
	if (c==(Day(4))) cout << "Friday\n";	if (c==(Day(5))) cout << "Saturday\n";	
						if (c==(Day(6))) cout << "Sunday\n";
}


void to_null (const Date& t)
{
	Date dd = {1,Month::jan, 1970};
	Date d =t;
	long int after_null = midle_days(dd,d);
	cout << after_null << '\n';
}



}// close namespace Chrono

int main () 
try {
	while (true)
	{
	Chrono::Date p;
	cin >> p;
	//day_of_week(true,p);
	//p.add_day(365);
	//p.add_month(1);
	//p.add_year(1);
	//cout << p;
	//next_sunday(p);
	//next_weekday(p);
	//next_workday(p);
	//week_of_year(p);
	to_null(p);
	}
	
	keep_window_open("''");
}
catch (exception& e)
{
cerr << e.what() << '\n';
keep_window_open("~~");
}
