#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>
#include <cmath>


const double pi = 3.1415;


void right_triangle (Graph_lib::Polygon& poly, const double& d)
{
	Point p{ 400,400 };
	poly.add(p);
	p.x = p.x-(d * cos(120 * pi / 180));
	p.y = p.y-(d * sin(120 * pi / 180));
	poly.add(p);
	p = { 400,400 };
	p.x = p.x - (d * cos(180 * pi / 180));
	p.y = p.y - (d * sin(180 * pi / 180))+1;
	poly.add(p);
	poly.set_color(Color::red);
	poly.set_style(Line_style(Line_style::solid, 3));
}

void right_square(Graph_lib::Polygon& poly, const double& d)
{
	Point p{ 400,400 };
	poly.add(p);

	//cout << p.x << ' ' << p.y << '\n';
	p.x = p.x - (d * cos(90 * pi / 180))+1;
	p.y = p.y - (d * sin(90 * pi / 180))+1;
	poly.add(p);
	//cout << p.x << ' ' << p.y << '\n';
	p.x = p.x - (d * cos(180 * pi / 180))+1;
	p.y = p.y - (d * sin(180 * pi / 180))+1;
	poly.add(p);
	//cout << p.x << ' ' << p.y << '\n';
	p = { 400,400 };
	p.x = p.x - (d * cos(180 * pi / 180))+1;
	p.y = p.y - (d * sin(180 * pi / 180))+1;
	poly.add(p);
	//cout << p.x << ' ' << p.y << '\n';
	
	poly.set_color(Color::blue);
	poly.set_style(Line_style(Line_style::solid, 3));
}


void right_pentagon(Graph_lib::Polygon& pentagon, const double& d)
{
	Point p{ 410,400 };
	pentagon.add(p);

	p.x = p.x - (d * cos(72 * pi / 180));
	p.y = p.y - (d * sin(72  * pi / 180));
	cout << p.x << ' ' << p.y << '\n';
	pentagon.add(p);

	p.x = p.x - (d * cos(144 * pi / 180));
	p.y = p.y - (d * sin(144 * pi / 180));
	cout << p.x << ' ' << p.y << '\n';
	pentagon.add(p);
	
	p.x = p.x - (d * cos(216 * pi / 180));
	p.y = p.y - (d * sin(216 * pi / 180));
	cout << p.x << ' ' << p.y << '\n';
	pentagon.add(p);

	p = { 510,400};
	cout << p.x << ' ' << p.y << '\n';
	pentagon.add(p);

	

	pentagon.set_color(Color::green);
	pentagon.set_style(Line_style(Line_style::solid, 3));



}

int main()
try
{
	Simple_window win{ Point{ 80,80 },1000,800, "Kansas" };

	Axis ax{ Axis::x, Point{ 20,700 }, 800,50, "x axis" };
	ax.set_color(Color::red);
	win.attach(ax);

	Axis ay{ Axis::y, Point{ 20,700 }, 550,50, "y axis" };
	ay.set_color(Color::red);
	win.attach(ay);

	Graph_lib::Polygon triangle;
	Graph_lib::Polygon square;
	Graph_lib::Polygon pentagon;


	right_triangle(triangle,140);
	right_square(square, 120);
	right_pentagon(pentagon, 100);

	win.attach(triangle);
	win.attach(square);
	win.attach(pentagon);
	win.wait_for_button();
}
catch (exception& e)
{
	cerr << e.what() << '\n';
	keep_window_open("~~");
}

catch (...)
{
	cerr << "Unknown error" << '\n';
	keep_window_open("~~");
}