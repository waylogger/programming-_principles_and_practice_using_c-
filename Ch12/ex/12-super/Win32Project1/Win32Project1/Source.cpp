#include <Graph.h>
#include <Simple_window.h>


void super_ellipse(Graph_lib::Open_polyline & line, double a, double b, double m, double n)
{
	double x = 1;
	double y = 0;
	for (int i = 0; i < 100; ++i)
	{
		++x;
		y = sqrt(abs(1 / b - abs(pow(x, n) / pow(a*b, n))));
		cout << x << ' ' << y << '\n';
	}
	
	
	









}


int main()
{
	Simple_window win{ Point{ 80,80 },1000,800, "Kansas" };

	Axis ax{ Axis::x, Point{ 20,700 }, 800,50, "x axis" };
	ax.set_color(Color::red);
	win.attach(ax);

	Axis ay{ Axis::y, Point{ 20,700 }, 550,50, "y axis" };
	ay.set_color(Color::red);
	win.attach(ay);

	Graph_lib::Open_polyline line;;
	double a = 2;
	double b = 2;
	double m = 2;
	double n = 2;
	super_ellipse(line, a, b, m, n);
	win.attach(line);


	win.wait_for_button();
}