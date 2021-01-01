
/*
Можно ли объевить константный аргумент
функции, который передается не по ссылке?
Что это значит?
Зачем это нужно?
Почему это практически не применяется?
*/

#include <std_lib_facilities.h>

void f(const int p) {
	int p = p+4;
	int s = 1;
	cout << s << '\n';
}

int main () {
	const int p = 11;
	f(p);
	keep_window_open();
		
}