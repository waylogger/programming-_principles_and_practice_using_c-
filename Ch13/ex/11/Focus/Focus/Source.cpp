
#include <Graph.h>
#include <Simple_window.h>
#include<std_lib_facilities.h>

const double pi = 3.1415;

int main()
{
	Simple_window win{ Point{ 80,80 },1000,800, "Kansas" };



	Graph_lib::Ellipse el{ Point{400,400},150,100 };
	el.set_color(Color::blue);
	el.set_style(Line_style(Line_style::solid, 4));
	win.attach(el);

	int focus_x = sqrt(pow(150, 2) - pow(100, 2)) ;
	Point f1{focus_x + 400,400};
	Mark F1(f1, 'F1');
	win.attach(F1);
	Point f2{ f1.x-focus_x*2,f1.y };
	Mark F2(f2, 'F2');
	win.attach(F2);
	Mark m{ Point{410,390},'O' };
	win.attach(m);
	Axis ax{ Axis::x, Point{ 200,400 }, 400,50 };
	ax.set_color(Color::red);
	win.attach(ax);

	Axis ay{ Axis::y, Point{ 400,550 }, 300,50, "y axis" };
	ay.set_color(Color::red);
	win.attach(ay);

	
	Point s;
	for (int i = 0; i < 360; i+=5)
	{
		s.x = 150 * cos(i * pi / 180) + 400;
		s.y = 100 * sin(i * pi / 180) + 400;
		Line a{ f1,s };
		win.attach(a);
		Line b{ f2,s };
		win.attach(b);
		a.set_color(Color::dark_green);
		b.set_color(Color::dark_green);
		a.set_style(Line_style(Line_style::solid, 4));
		b.set_style(Line_style(Line_style::solid, 4));
		win.wait_for_button();
		
	}
	
	

	

	



	win.wait_for_button();
}