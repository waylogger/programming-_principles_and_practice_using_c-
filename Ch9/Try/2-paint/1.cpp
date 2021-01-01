#include <std_lib_facilities.h>

class X
{
	int x = 635;
	public:
	int y = x+1;
};

struct Y
{
	int x = 631;
	int y = x+1;
};


int main ()
{
	X x;
	cout << x.y << '\n';
	Y y;
	cout << y.x << y.y << '\n';
	keep_window_open();
}