#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>

double fx (double x) 
{
	return sin(x)+cos(x);
}

double fx1 (double x) 
{
	return (sin(x)*sin(x))+(cos(x)*cos(x));
}

int main () try {

Simple_window win {Point{20,20},800,600,"Kansas"};

Function f {sin,-11,10,Point{400,300}};
f.set_color(Color::red);
win.attach(f);

Function f1 {cos,-11,10,Point{400,300}};
f1.set_color(Color::blue);
win.attach(f1);

Function f2 {fx,-11,10,Point{400,300}};
f2.set_color(Color::green);
win.attach(f2);

Function f3 {fx1,-11,10,Point{400,300}};
f3.set_color(Color::dark_red);
win.attach(f3);




win.wait_for_button();


}
catch (exception& e){
	cerr << e.what() << '\n';
	keep_window_open();
}
catch (...){
	cerr << "Unknown error" << '\n';
	keep_window_open();
}