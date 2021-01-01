/*1. Определить объект класса Date 
с именем today. инициализированный датой 
19 мая 1963 года.

2. Определить объект класса Date с именем 
tomorrow и присвоить ему значение, 
скопировав в него объект today и увеличив 
его день на единицу с помощью функции add_day();

3. Вывести на печать объекты today и 
tomorrow, используя оператор <<
 опредеелнный в разделе 9.8*/

#include <std_lib_facilities.h>
struct Date {
	int d;
	int m;
	int y;
};

Date add_day(Date i) {
	i.d=i.d+1;
	return i;
}

int main () 
{
	Date today {19,05,1963};
	Date tomorrow {add_day(today)};
	cout << today.d << ' ' << today.m << ' ' << today.y << '\n';
	cout << tomorrow.d << ' ' << tomorrow.m << ' ' << tomorrow.y << '\n'; 	
	keep_window_open();
};


