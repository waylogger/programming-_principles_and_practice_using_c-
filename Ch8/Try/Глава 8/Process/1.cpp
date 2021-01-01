#include <std_lib_facilities.h>

int main () {
int i= 0;
int x = ++i + ++i;
cout << x << " " << i << '\n';
keep_window_open();
}