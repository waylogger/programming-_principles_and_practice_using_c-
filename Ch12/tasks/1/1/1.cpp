
#include <Graph.h>
#include <Simple_window.h>


int main()
{
	
Point tl{ 100,100 };
Simple_window win (tl,600,400,"My window");


Axis ax{ Axis::x, Point(150,300), 280 , 10, "                           x axis" };
ax.set_color(Color::red);
win.attach(ax);

Axis ay{ Axis::y, Point(150,300), 280 , 10, "y axis" };
ay.set_color(Color::red);
win.attach(ay);

Function sine{ sin,0,100,Point{150,200}, 300,10,10 };
sine.set_style(Line_style(Line_style(Line_style::dash, 10)));
sine.set_color(Color::red);
win.attach(sine);

Graph_lib::Polygon poly;
poly.add(Point{200,100 });
poly.add(Point{ 250,100 });
poly.add(Point{ 225,30 });
poly.set_style(Line_style(Line_style::dash, 4));
poly.set_color(Color::red);
win.attach(poly);

Graph_lib::Rectangle rec{ Point{300,50}, 50,50 };
rec.set_color(Color::blue);
win.attach(rec);

Graph_lib::Closed_polyline poly_rect;
poly_rect.add(Point{ 400,50 });
poly_rect.add(Point{ 450,50 });
poly_rect.add(Point{ 450,100 });
poly_rect.add(Point{ 400,100 });
poly_rect.set_color(Color::green);
poly_rect.set_fill_color(Color::blue);
win.attach(poly_rect);

Text t{ Point{210,150}, "Surprise, motherfucker!!!" };
t.set_color(Color::black);
t.set_font(Font::times_bold);
t.set_font_size(25);
win.attach(t);

Image ii{ Point{210,160}, "C:\\Users\\wLr\\Documents\\Visual Studio 2015\\Projects\\12\\tasks\\1\\1.jpg" };
win.attach(ii);

win.wait_for_button();
}