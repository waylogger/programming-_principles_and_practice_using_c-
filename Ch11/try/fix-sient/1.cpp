#include <std_lib_facilities.h>


int main ()
{
	cout 	<< setprecision(89) <<1234567.89 << '\n'
			<< fixed << 1234567.89 << '\n'
			<< scientific << 1234567.89 << '\n'
			<< defaultfloat << 1234567.89 << '\n';
	keep_window_open();
}