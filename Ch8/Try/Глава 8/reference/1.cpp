#include <std_lib_facilities.h>

int e () {
	int q = 16;
	return q;
}
int b = 16;
int main () {
	int& s = e();
	keep_window_open();
}