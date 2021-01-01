#include<D:\Programms\Ch9\Rep\Date\Chrono.h>

namespace Chrono { // open namespace Chrono

Date::Date(int yy, Month mm, int dd)
	: y{yy}, m{mm},d{dd}
{
	if (!is_date(yy,mm,dd)) error ("Ups,,,");
}

const Date& default_date()
{
	static Date dd = {2001,Month::jan,1};
	return dd;
}

Date::Date()
	: y{default_date().year()},
	  m{default_date().month()},
	  d{default_date().day()}
{
}
/*
void Date::add_day(int n)
{
	//...
}

void Date::add_month(int n)
{
	//...
}

void Date::add_year(int n)
{
	if (m==Month::feb && d==29
		&& !leapyear(y+n)) {
			m = Month::mar;
			d = 1;
		}
		y+=n;
}
*/
//вспомогательные функции

bool is_date(int y, Month m, int d)
{
	//полагаем корректным
	if (d<=0) return false;
	if (m<Month::jan || Month::dec<m) return false;
	int days_in_month = 31;
	switch (m) {
	//	case Month::feb:
	//	days_in_month = (leapyear(y))?29:28;
	//break;
	case Month::apr: case Month::jun:
	case Month::sep: case Month::nov:
	days_in_month = 30;
	break;
	}
	if (days_in_month<d) return false;
	return true;
}

/*
bool leapyear (int y)
{
	return true;//...
}
*/

bool operator == (const Date&a, const Date& b)
{
	return a.year() == b.year()
	&&     a.month()== b.month()
	&& 	   a.day()  == b.day();
}

bool operator != (const Date&a, const Date& b)
{
	return !(a==b);
}

ostream& operator << (ostream& os, const Date& d)
{
	return os << '(' << d.year()
			  << ',' << int (d.month())
			  << ',' << d.day () << ')' << '\n'; 
 
}


istream& operator >> (istream& is, Date& dd)
{
	int y, m, d;
	char ch1 , ch2 , ch3 , ch4 ;
	is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4 ;
	if (!is) return is ;
	if (ch1!='(' || ch2!=',' || ch3!=','||ch4!=')')
	is.clear (ios_base::failbit) ; // Устана влива ем бит ошибки
	dd = Date(y, Month(m),d);
	return is;
}

}// close namespace Chrono
/*
int main () 
try {
	Chrono::Date p;
	cin >> p;
	cout << p;
	keep_window_open("''");
}
catch (exception& e)
{
cerr << e.what() << '\n';
keep_window_open();
}
*/