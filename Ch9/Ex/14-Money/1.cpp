#include <std_lib_facilities.h>
const long int  max_of_long_int = 2147483647;
const long int  min_of_long_int = -2147483647;

double circle (double d);
bool cor_cur (const double& d);

enum class Currency
{
	USD, RUB, EUR
};
class Money
{
	public:
	double money = 0;
	Currency currency;
	Money(Currency cur, double m) : currency(cur), money(m) 
	{
		//if (!cor_cur(m)) error ("Format error");
	}
	Money() {}
};
bool cor_cur (const double& d)
{
	if (d>max_of_long_int || d<min_of_long_int) {cout << "Sum of cents(kopeks) too big for long int\n"; return false;};
	if (d<=0) {cout << "Sum must be biggest than zero\n"; return false;};
	return true;
}
Currency const_cur  (const string s) 
{
	if (s=="USD") return Currency::USD;
	else if (s=="RUB") return Currency::RUB;
	else if (s=="EUR") return Currency::EUR;
	else error ("That currency unecxpecteble");
	return Currency::USD;
} 
ostream& operator << (ostream& os, const Currency& c)
{
	if (c==Currency::USD) return os << "USD";
	if (c==Currency::RUB) return os << "RUB";
	if (c==Currency::EUR) return os << "EUR";
	return os;
}
istream& operator >> (istream& is, Money& m)
{
	double d = 0;
	string s = " ";
	cout << "How much money(USD,RUB,EUR)?\n";
	is >> s >> d;
	d = circle (d);
	Currency c = const_cur(s);
	d = d*100;
	m=Money(c,d);
	return is;
}
ostream& operator << (ostream& os, const Money& m)
{
	double d = m.money;
	return os << m.currency << d/100 << '\n';
	return os;
}
double circle (double d)
{
	double c = d - int(d);
	double rc = 1-c;
	if (c <= 0.5) return d-c;
	if (c > 0.5) return d+rc;
	return c;
}

Money operator + (Money& m,Money& mm)
{
	if (m.currency!=mm.currency) error ("You are havant tables of convers for sum dif currency");
	double d = m.money+mm.money;
	Currency c = m.currency;
	m = Money(c,d);
	return m;
}

Money operator * (Money& m,Money& mm)
{
	if (m.currency!=mm.currency) error ("You are havant tables of convers for sum dif currency");
	double d = m.money*mm.money;
	Currency c = m.currency;
	m = Money(c,d);
	return m;
}

Money operator / (Money& m,Money& mm)
{
	if (m.currency!=mm.currency) error ("You are havant tables of convers for sum dif currency");
	double d = m.money/mm.money;
	Currency c = m.currency;
	m = Money(c,d);
	return m;
}

Money operator - (Money& m,Money& mm)
{
	if (m.currency!=mm.currency) error ("You are havant tables of convers for sum dif currency");
	double d = m.money-mm.money;
	Currency c = m.currency;
	m = Money(c,d);
	return m;
}


int main () 
try
{
	Money m;
	Money mm = {Currency::RUB,863000};
	cin >> m;
	m=mm+m;
	cout << m << '\n';
	m=m-mm;
	cout << m << '\n';
	m=m*mm;
	cout << m << '\n';
	m=m/mm;
	cout << m << '\n';
	keep_window_open();
}
catch (exception& e)
{
	cerr << e.what() << '\n';
	keep_window_open("~~");
}
catch(...)
{
	cerr << "Unknown error" << '\n';
	keep_window_open("~~");
}