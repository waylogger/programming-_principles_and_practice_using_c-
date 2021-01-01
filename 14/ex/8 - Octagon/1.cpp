#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>

/*
Задача - определить класс рисующий правильный восьмиугольник.

Основная сложность - привязать собственный класс к классу-предку Shape
например не определять собственный контейнер, а использовать имеющийся в Shape
Сложность в том и заключается, что доступ к указанному контейнеру возможен только посредством фунункции add() и point(i)
А использовать их возможно только из конструктора, потому пришлось идти этим путем, а не привычным - через функцию draw_lines()
что скорее всего более правильный подход


*/

const double pi = 3.14;
const double angle_octagon = 45;
Point next_point(const Point& start, const Point& dest, const double& rad, const double& angle);
class Octagon : public Shape
{
	public:
	Octagon (const Point& c, const double& r);
	void draw_lines() const override;
	
	private:
	double rad;
	Point center;
	
}; 
void Octagon::draw_lines() const
{
	Shape::draw_lines();
	fl_color(fill_color().as_int());
	fl_begin_complex_polygon();
	for (int i = 0; i < number_of_points();++i)
	{
		fl_vertex(point(i).x,point(i).y);
	}
	fl_end_complex_polygon();
	
}
Octagon::Octagon(const Point& c, const double& r) : center(c), rad(r)
{
	Point start = c;
	Point dest;
	dest.x = start.x;
	dest.y = start.y+r;
	Point p;

	for (int angle = 0; angle <=360; angle+=angle_octagon)
	{
		p=next_point(start,dest,r,angle);
		add(p);
	}
}



Point next_point(const Point& start, const Point& dest, const double& rad, const double& angle)
{
	Point p;
	p.x = start.x+(dest.x-start.x)*cos(angle*pi/180)-(dest.y-start.y)*sin(angle*pi/180);
	p.y = start.y+(dest.y-start.y)*cos(angle*pi/180)+(dest.x-start.x)*sin(angle*pi/180);
	return (p);
}




int main () try {

Simple_window win(Point{20,20},1000,1000,"Kansas");

Octagon oct {Point{500,500},100};
Lines a;
a.add(Point{500,500},Point{600,600});
oct.set_color(Color::blue);
oct.set_style(Line_style(Line_style::solid,5));

a.set_color(oct.color());
a.set_style(oct.style());
oct.set_fill_color(Color::red);
//oct.move(200,200);
//cout << oct.point(4).x << '\n';
//cout << oct.number_of_points() << '\n';
win.attach(oct);
win.attach(a);


win.wait_for_button();


}
catch (exception& e){
	cerr << e.what() << '\n';
	keep_window_open();
}
catch (...){
	cerr << "Unknown error" << '\n';
	keep_window_open();
}