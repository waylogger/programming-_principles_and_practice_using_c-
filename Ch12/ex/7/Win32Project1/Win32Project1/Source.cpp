#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>

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

	Graph_lib::Rectangle rec{ Point{200,400},400,300 };
	rec.set_color(Color::black);
	rec.set_style(Line_style(Line_style::solid, 3));
	win.attach(rec);

	Graph_lib::Polygon poly;
	poly.add(Point{ 200,400 });
	poly.add(Point{ 400,150 });
	poly.add(Point{ 600,400 });
	poly.set_color(Color::black);
	poly.set_style(Line_style(Line_style::solid, 3));
	win.attach(poly);


	Graph_lib::Circle e{ Point{400,290},30 };
	e.set_color(Color::black);
	e.set_style(Line_style(Line_style::solid, 3));
	win.attach(e);

	Graph_lib::Line nx{ Point{370,290}, Point {430,290} };
	nx.set_color(Color::black);
	nx.set_style(Line_style(Line_style::solid, 3));
	win.attach(nx);

	Graph_lib::Line ny{ Point{ 400,260 }, Point{ 400,320 } };
	ny.set_color(Color::black);
	ny.set_style(Line_style(Line_style::solid, 3));
	win.attach(ny);

	Closed_polyline tube;

	tube.add(Point{ 512,290 });
	tube.add(Point{ 512,230 });
	tube.add(Point{ 540,230 });
	tube.add(Point{ 540,324 });
	tube.set_color(Color::black);
	tube.set_style(Line_style(Line_style::solid, 3));
	win.attach(tube);

	Graph_lib::Circle smoke{ Point{535,212},15 };
	smoke.set_color(Color::black);
	smoke.set_style(Line_style(Line_style::solid, 3));
	smoke.set_fill_color(Color::black);
	win.attach(smoke);

	Graph_lib::Circle smoke1{ Point{ 545,200 },15 };
	smoke1.set_color(Color::black);
	smoke1.set_style(Line_style(Line_style::solid, 3));
	smoke1.set_fill_color(Color::black);
	win.attach(smoke1);

	Graph_lib::Rectangle door{ Point{250,550},75,150 };
	door.set_color(Color::black);
	door.set_style(Line_style(Line_style::solid, 3));
	door.set_fill_color(Color::black);
	win.attach(door);

	Graph_lib::Rectangle window{ Point{ 450,550 },75,85 };
	window.set_color(Color::black);
	window.set_style(Line_style(Line_style::solid, 3));
	window.set_fill_color(Color::white);
	win.attach(window);
	
	Line ramy{ Point{ 450,580 }, Point{ 482,580 } };
	
	ramy.set_color(Color::black);
	ramy.set_style(Line_style(Line_style::solid, 3));
	win.attach(ramy);
	

	Line ramx{ Point{ 482,550 }, Point{ 482,635 } };

	ramx.set_color(Color::black);
	ramx.set_style(Line_style(Line_style::solid, 3));
	win.attach(ramx);
	win.wait_for_button();


}

catch (exception& e)
{
	cerr << e.what() << '\n';
	keep_window_open();
}