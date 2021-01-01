#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>

const double pi = 3.1415;

Point turn (const int& i,double x0,double y0,double x1,double y1)
{
	Point p;
	p.x = x0+(x1-x0)*cos(i*pi/180)-(y1-y0)*sin(i*pi/180);
	p.y = y0+(y1-y0)*cos(i*pi/180)+(x1-x0)*sin(i*pi/180);
	return p;
}
class Nangle : public Shape
{
	public:
	Nangle(Point st, double rad, int angles);
	void draw_lines() const;

	
};

void Nangle::draw_lines() const
{
	fl_color(fill_color().as_int());
	fl_begin_complex_polygon();
	for(int i =0; i < number_of_points();++i)
	{
	fl_vertex(point(i).x,point(i).y);
	}
	fl_end_complex_polygon();
	
}
Nangle::Nangle(Point start, double rad, int angles)
{
	Point p;
	int angle = (180/angles)*2;
	double x0 = start.x;
	double y0 = start.y;
	double x1 = x0;
	double y1 = y0+rad;
	for (int i =angle;	i<=360;	i+=angle)		
		{
			p=turn(i,x0,y0,x1,y1);
			Shape::add(p);
		}
	Shape::add(Point{point(0).x,point(0).y});
	
}

int main ()
{
	
	
	Simple_window win {Point{20,20},800,600,"Kansas"};
	Nangle n {Point{300,300},100,6};
	Vector_ref<Shape>sh;
	sh.push_back(n);
	for (int i =0; i < sh.size();++i)
	{
	win.attach(sh[i]);	
	}
	win.wait_for_button();
	sh[0].set_fill_color(Color::red);
	win.wait_for_button();
	sh[0].set_fill_color(Color::black);
	win.wait_for_button();
	sh[0].set_fill_color(Color::green);
	win.wait_for_button();
	
	
	
	
	
	
	
	
	
	
	
	
}
