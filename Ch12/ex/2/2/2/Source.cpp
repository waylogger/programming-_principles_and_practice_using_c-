#include <Graph.h>
#include <Simple_window.h>

int main()
{
	Simple_window win{ Point{80,80},1000,800, "Kansas"}; 

	Axis ax{ Axis::x, Point{20,700}, 800,50, "x axis" };
	ax.set_color(Color::red);
	win.attach(ax);

	Axis ay{ Axis::y, Point{ 20,700 }, 550,50, "y axis" };
	ay.set_color(Color::red);
	win.attach(ay);

	Graph_lib::Rectangle rec{ Point{50,300},250,86 };
	rec.set_color(Color::blue);
	rec.set_fill_color(Color::red);
	win.attach(rec);

	Text t{ Point{150,350}, "Howdy!" };
	t.set_font_size(20);
	win.attach(t);


	win.wait_for_button();
}