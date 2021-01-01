#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>

double fac (int n)

{
	return n>1 ? n*fac(n-1) : 1;
}

double term (double x, int n)
{
	return pow (x,n)/fac(n);
}

double expe (double x, int n)
{
	double sum = 0;
	for (int i =0; i < n; ++i)
		sum+=term(x,i);
	return sum;
}

int N_of_aproximation = 0;
double expN (double en) {return expe(en,N_of_aproximation);}


int main () try {




Simple_window win {Point{100,100},800,600,"Kansas - Function graphic"};



for (int n =0; n<50; ++n)
{
	ostringstream ss;
	ss << "exp appriximation; n==" << n ;
	win.set_label(ss.str());
	N_of_aproximation = n;
	Function e {expN
	,-11,10,Point{200,300}};
	e.set_color(Color::red);
	win.attach(e);
	win.wait_for_button();
	win.detach(e);
}

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