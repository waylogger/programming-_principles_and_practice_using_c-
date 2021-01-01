#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>

int fac(int n)
{
return n>1 ? n*fac(n-1) : 1;
}

int fact (int i)
{
	int f = 1;
	while (i>0)
	{
		f*=i;
		--i;
	}
	return f;
}
int main () try {

for (int i =0; i < 20; ++i)
{
double f = fac(i);
double ff = fact(i);
cout << f << '\n';
cout << ff << '\n';
}
keep_window_open();

}
catch (exception& e){
	cerr << e.what() << '\n';
	keep_window_open();
}
catch (...){
	cerr << "Unknown error" << '\n';
	keep_window_open();
}