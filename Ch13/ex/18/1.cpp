#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>




void intersection(const Point& p1, const Point& p2,const Point& p3, const Point& p4)
{
	if (p1==p3 || p2==p4) return;
	if (p1==p4 || p2==p3) return; 
	Point u;
	Point p;
	double  x1 = p1.x;	double 	y1 = p1.y;
	double	x2 = p2.x;	double	y2 = p2.y;
	double x3 = p3.x;	double y3 = p3.y;
	double x4 = p4.x;	double y4 = p4.y;
	
	double denom = (y4-y3)*(x2-x1)-(x4-x3)*(y2-y1);
	if (denom==0) return;

	u.x = ((x4-x3)*(y1-y2)-(y4-y3)*(x1-x3))/denom;
	u.y = ((x2-x1)*(y1-y3)-(y2-y1)*(x1-x3))/denom;
	if (u.x<0 || u.x > 1 || u.y <0 || u.y >1 ) return;
	p.x = x1+u.x*(x2-x1);
	p.y = y1+u.x*(y2-y1);
	error ("Lines are intersect");
}

class Poly : public Shape
{
public:
	Poly(Point pp1, Point pp2, Point pp3, Point pp4) : p1(pp1), p2(pp2), p3(pp3), p4(pp4) 
	{
		add(p1);
		add(p2);
		add(p3);
		add(p4);
		intersection(p1,p2,p3,p4); //проверка на пересечение
	}
	Poly () {}
	void draw_lines() const;
	void add(const Point& p);
private:
	Point p1, p2, p3, p4;
	vector<Point> ps;
};

void Poly::draw_lines() const
try
{
	if (ps.size() % 2 > 0) error (" s ");
	fl_color(FL_BLUE);
	fl_line_style(FL_SOLID, 5);
	string lab;
	string s;
	ostringstream os{ lab };
	
	
	
	for (int i = 0; i < ps.size(); ++i)
	{
		os << i;
		s = os.str();
		
		//cout << s << '\n';
		fl_draw(s.c_str(), ps[i].x+5, ps[i].y-8);
		if (i+1<ps.size()) fl_line(ps[i].x, ps[i].y, ps[i + 1].x, ps[i + 1].y);
		fl_line(ps[0].x, ps[0].y, ps[ps.size() - 1].x, ps[ps.size() - 1].y);
		os.str(string());
	}
	for (int i =0; i <ps.size();++i)
	{
		if (i+1<ps.size()) intersection(ps[0], ps[ps.size() - 1],ps[i],ps[i+1]); // проверяем на пересечения с завершающей линией
	}
	

}
catch (exception& e)
{
	cerr << e.what() << '\n';
	keep_window_open();
	exit(0);
}

void Poly::add(const Point& p)
{
	ps.push_back(p);
	//cout << ps.size() << '\n';
}





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


	Poly an{ Point {200,200},Point{ 200,350 },Point{ 300,300 },Point{ 300,200 } };
	//an.add(Point{400,500});
	//an.add(Point{300,500});
	win.attach(an);


	win.wait_for_button();
}
catch (exception& e)
{
	cerr << e.what() << '\n';
	keep_window_open();
}


catch (...)
{
	cerr << "Unknown error" << '\n';
	keep_window_open();
}