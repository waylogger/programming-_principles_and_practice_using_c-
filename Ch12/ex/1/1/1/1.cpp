#include <Graph.h>
#include <Simple_window.h>

int main()
{

	Simple_window win{ Point{50,50},800,800,"Kansas" };
	Graph_lib::Rectangle rec{ Point{80,80},100,80 };
	rec.set_color(Color::blue);
	win.attach(rec);

	Graph_lib::Polygon poly;
	poly.add(Point{ 80,170 });
	poly.add(Point{ 180,170 });
	poly.add(Point{ 180,270 });
	poly.add(Point{ 80,270 });
	poly.set_color(Color::red);
	win.attach(poly);

	win.wait_for_button();
}