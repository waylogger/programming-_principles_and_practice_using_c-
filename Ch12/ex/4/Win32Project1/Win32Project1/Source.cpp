
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


	Graph_lib::Rectangle b{ Point{ 300,400 },100,100 };
	b.set_style(Line_style(Line_style::solid, 5));
	b.set_color(Color::black);
	win.attach(b);

	Graph_lib::Rectangle b2{ Point{ 400,400 },100,100 };
	b2.set_style(Line_style(Line_style::solid, 5));
	b2.set_fill_color(Color::red);
	b2.set_color(Color::black);
	win.attach(b2);

	Graph_lib::Rectangle b3{ Point{ 500,400 },100,100 };
	b3.set_style(Line_style(Line_style::solid, 5));
	b3.set_color(Color::black);
	win.attach(b3);

	Graph_lib::Rectangle d{ Point{300,300},100,100 };
	d.set_style(Line_style(Line_style::solid, 5));
	d.set_color(Color::black);
	d.set_fill_color(Color::red);
	win.attach(d);

	Graph_lib::Rectangle d2{ Point{ 400,300 },100,100 };
	d2.set_style(Line_style(Line_style::solid, 5));
	d2.set_fill_color(Color::red);
	d2.set_color(Color::black);
	win.attach(d2);

	Graph_lib::Rectangle d3{ Point{ 500,300 },100,100 };
	d3.set_style(Line_style(Line_style::solid, 5));
	d3.set_color(Color::black);
	d3.set_fill_color(Color::red);
	win.attach(d3);

	Graph_lib::Rectangle c{ Point{ 300,200 },100,100 };
	c.set_style(Line_style(Line_style::solid, 5));
	c.set_color(Color::black);
	win.attach(c);

	Graph_lib::Rectangle c2{ Point{ 400,200 },100,100 };
	c2.set_style(Line_style(Line_style::solid, 5));
	c2.set_fill_color(Color::red);
	c2.set_color(Color::black);
	win.attach(c2);

	Graph_lib::Rectangle c3{ Point{ 500,200 },100,100 };
	c3.set_style(Line_style(Line_style::solid, 5));
	c3.set_color(Color::black);
	win.attach(c3);








	win.wait_for_button();
}