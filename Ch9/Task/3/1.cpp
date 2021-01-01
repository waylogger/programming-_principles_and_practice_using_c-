/*1. ќпределить объект класса Date 
с именем today. инициализированный датой 
19 ма¤ 1963 года.

2. ќпределить объект класса Date с именем 
tomorrow и присвоить ему значение, 
скопировав в него объект today и увеличив 
его день на единицу с помощью функции add_day();

3. ¬ывести на печать объекты today и 
tomorrow, использу¤ оператор <<
 опредеелнный в разделе 9.8*/

#include <std_lib_facilities.h>


class Date {
	int y, m, d;
public:
	Date(int d,int m, int y) : d(d), m(m), y(y){};
	int add_day(int n);
	int month () {return m;}
	int day () {return d;}
	int year() {return y;}
};

ostream& operator << ( ostream& os, Date d)
{
return os << '(' << d.day()	
	  << ',' << d.month()
	  << ',' << d.year() << ')';
}

int Date::add_day(int n) {
	return n+1;
}


int main () {
	Date today = {23,05,1963};
	Date tomorrow = {today.add_day(today.day()),today.month(),today.year()};
	cout << today << '\n';
	cout << tomorrow << '\n';
	keep_window_open();
}




/*
class Date {
private:
	int y =0;
	int m =0;
	int d =0;
public:
	void add_day(int n);
	int month () {return m;}
	int day () {return d;}
	int year() {return y;}
	Date(int d, int m, int y);
};

void Date::add_day(int n) {
	cout << n+1;
};



int main () {
	Date today = {23,05,1963};
	//Date tomorrow;
	//cout << today.d << ' ' << today.m << ' ' << today.y << '\n';
	//cout << tomorrow.d << ' ' << tomorrow.m << ' ' << tomorrow.y << '\n';
	cout << today << '\n';
	//cout << tomorrow << '\n';
	keep_window_open();
}
*/