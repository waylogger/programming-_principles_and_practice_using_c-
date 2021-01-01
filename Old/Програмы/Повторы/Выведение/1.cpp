// Программа выводящая таблицу символов и соответствующий им номер;
#include <std_lib_facilities.h>

int main () {
int n = 0;
char a = 'a';
for (char a = 'a'; n<=24; ++a)
cout 	<< " "
	<< a 
	<< " " 
	<< ++n 
	<< "\n";
keep_window_open ();
} 