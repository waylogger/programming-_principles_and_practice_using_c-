#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>

typedef double S (double);

 double a (double b)
 {
	 return b;
 }
 
double c (S s, double d)
{
	return s(d);
}
 
int main () try {

cout << c(a,5) << '\n';

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