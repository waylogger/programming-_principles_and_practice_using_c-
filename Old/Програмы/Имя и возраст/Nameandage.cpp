#include <std_lib_facilities.h>

int main () {
cout << "Please, input your Name and age\n";
string first_name;
double age;
cin >> first_name;
cin >> age;
cout << "Hi, " << first_name << " " << age*12 << " ";
keep_window_open ();
;}