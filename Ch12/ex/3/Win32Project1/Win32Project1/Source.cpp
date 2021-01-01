#include <Graph.h>
#include <Simple_window.h>

int main()
{
	Simple_window win{ Point{ 80,80 },1000,800, "Kansas" };

	Axis ax{ Axis::x, Point{ 20,700 }, 800,50, "x axis" };
	ax.set_color(Color::red);
	win.attach(ax);

	Axis ay{ Axis::y, Point{ 20,700 }, 550,50, "y axis" };
	ay.set_color(Color::red);
	
	win.attach(ay);

	Graph_lib::Open_polyline p;
	p.add(Point{ 30,650 });
	p.add(Point{ 80,500 });
	p.add(Point{ 130,650 });
	p.set_color(Color::red);
	p.set_style(Line_style(Line_style::solid, 7));
	win.attach(p);

	Graph_lib::Open_polyline p2;
	p2.add(Point{ 57,575 });
	p2.add(Point{ 105,575 });
	p2.set_color(Color::red);
	p2.set_style(Line_style(Line_style::solid, 7));
	win.attach(p2);

	Graph_lib::Open_polyline p3;
	p3.add(Point{200,500});
	p3.add(Point{ 200,650 });
	p3.add(Point{ 280,500 });
	p3.add(Point{ 280,650 });

	p3.set_color(Color::green);
	p3.set_style(Line_style(Line_style::solid,7));
	win.attach(p3);

	win.wait_for_button();
}