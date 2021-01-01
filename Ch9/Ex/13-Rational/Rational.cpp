#include <std_lib_facilities.h>



bool is_rational(const double ch, const double zn);



int gsd(int x, int y)
{
	x= abs(x);
	y= abs(y);
	while (y)
	{
		int t = y;
		y = x%y;
		x=t;
	}
return x;
}


class Rational
{
	public:
	double chisl = 0;
	double znam = 0;
	
	Rational() {}
	Rational(double ch, double zn) : chisl(ch), znam(zn) 
	{
		if (!is_rational(ch,zn)) error ("Formar error::ratiolals digits is different");;
	}
	void normalized();
};

void Rational::normalized()
{
	if (znam<0) {znam=-znam; chisl = -chisl;}
	double n = gsd(chisl,znam);
	if (n>1) {chisl/=n; znam/=n;}
}

bool is_rational (const double ch, const double zn) 
{
if(zn==0) cout << "Denominator could not be zero\n";
if (zn==0) return false;
return true;
}
//............utilities............................................
bool operator == (Rational& r, Rational&rr)
{
	return r.chisl*rr.znam==r.znam*rr.chisl;
}

bool operator != (Rational& r, Rational&rr)
{return !(r==rr);}

istream& operator >> (istream& is, Rational& p)
{
	double zn, ch;
	char slash = ' ';
	is >> ch;
	is >> slash;
	is >> zn;
	if (slash != '/') {is.clear(ios_base::failbit); error ("Format error: after numenator follow '/' + denumenator");}
	p = Rational(ch,zn);
	return is;
}

ostream& operator << (ostream&os, const Rational& p)
{
	return os << p.chisl <<  '/' << p.znam;
}


//............arithmetic............................................

Rational operator+(Rational& r, Rational&rr)
{
	Rational new_r(r.znam*rr.chisl+r.chisl*rr.znam,r.znam*rr.znam);
	new_r.normalized();
	return new_r;
}

Rational operator*(Rational& r, Rational&rr)
{
	
	Rational new_r(rr.chisl*r.chisl,r.znam*rr.znam);
	new_r.normalized();
	return new_r;
}
Rational operator-(Rational& r, Rational&rr)
{
	Rational new_r(r.znam*rr.chisl-r.chisl*rr.znam,r.znam*rr.znam);
	new_r.normalized();
	return new_r;
}

Rational operator/(Rational& r, Rational&rr)
{
	Rational new_r(r.chisl*rr.znam,r.znam*rr.chisl);
	new_r.normalized();
	return new_r;
}

Rational operator - (Rational r)
{
	return Rational(-r.chisl,r.znam);
}


int main () 
try
{
	Rational r, b;
	cin >> r >> b; 
	cout << r+b << '\n';
	cout << r*b << '\n';
	cout << r-b << '\n';
	cout << r/b << '\n';
	keep_window_open("~~");
}
catch (exception& e)
{
	cerr << e.what() << '\n';
	keep_window_open("~~");
}
catch (...)
{
	cerr << "Unknown exception" << '\n';
	keep_window_open("~~");
}
