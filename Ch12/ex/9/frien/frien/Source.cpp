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

	Graph_lib::Image ii{ Point{25,25},"C:\\\\Users\\wLr\\Documents\\Visual Studio 2015\\Projects\\12\\ex\\9\\frien\\1.jpg" };
	win.attach(ii);
	win.set_label("Trufanov");
	Text t{Point{ 25,15 }, "Trufanov Maks"};
	t.set_font_size(20);
	t.set_color(Color::black)
	win.attach(t);
	win.wait_for_button();
}