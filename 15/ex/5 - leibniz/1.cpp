#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>


double leib (double x)
{
	return pow(-1,x)/((2*x)+1);
}

int n_of_l = 0;
double anim_leb (double x)
{
	double sum = 0;
	for (int i = 0; i < n_of_l; ++i)
	{
		sum+=leib(int(x));
	}
	
	return sum;
}


int main () try {


	Simple_window win {Point{20,20},800,600,"Kansas"};
	for (int i =0; i < 50; ++i)
	{
		n_of_l = i;
	Function f {anim_leb,-11,10,Point{300,200}};
	f.set_color(Color::red);
	win.attach(f);
	win.wait_for_button();
	win.detach(f);
	}


}
catch (exception& e){
	cerr << e.what() << '\n';
	keep_window_open();
}
catch (...){
	cerr << "Unknown error" << '\n';
	keep_window_open();
}