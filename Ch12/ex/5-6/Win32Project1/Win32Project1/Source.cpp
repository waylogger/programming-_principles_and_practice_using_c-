#include <Graph.h>
#include <Simple_window.h>

int main()
{
	Simple_window win{ Point{ 80,80 },1500,1000, "Kansas" };

	Graph_lib::Rectangle rec { Point{90,90},1280,810 };
	rec.set_style(Line_style(Line_style::solid, 5));
	rec.set_color(Color::red);
	win.attach(rec);

	/*ex6
	Simple_window win{ Point{ 80,80 },1500,1000, "Kansas" };

	Graph_lib::Rectangle rec{ Point{ 90,90 },1280,10000 };
	rec.set_style(Line_style(Line_style::solid, 5));
	rec.set_color(Color::red);
	win.attach(rec);*/

	/*Simple_window win{ Point{ 80,80 },1500,10000, "Kansas" };

	Graph_lib::Rectangle rec{ Point{ 90,90 },1280,810 };
	rec.set_style(Line_style(Line_style::solid, 5));
	rec.set_color(Color::red);
	win.attach(rec);*/






	win.wait_for_button();
}