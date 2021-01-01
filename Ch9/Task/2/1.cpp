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

struct Date {
	int y;
	int m;
	int d;
	Date(int d, int m, int y) : d(d), m(m), y(y){};
	void add_day(int n);
};

int add_day(int n) {
	return n+1;
};

ostream& operator <<(ostream& os, const Date& d)
{
return os << '(' << d.d 
	  << ',' << d.m
	  << ',' << d.y << ')';
}
int main () {
	Date today = {19,05,1963};
	Date tomorrow {add_day(today.d),05,1963};
	//cout << today.d << ' ' << today.m << ' ' << today.y << '\n';
	//cout << tomorrow.d << ' ' << tomorrow.m << ' ' << tomorrow.y << '\n';
	cout << today << '\n';
	cout << tomorrow << '\n';
	keep_window_open();
}