
#include <Graph.h>
#include <Simple_window.h>

const double pi = 3.1415;


void rotation(Point& p, const Point& start, const Point& dest, const int grad)
{
	
		p.x = start.x + (dest.x - start.x)*cos(grad * pi / 180) - (dest.y - start.y)*sin(grad * pi / 180);
		p.y = start.y + (dest.y - start.y)*cos(grad * pi / 180) + (dest.x - start.x)*sin(grad * pi / 180);
	
}

class R_Triangle : public Shape
{
public:
	R_Triangle(Point pp, int rr) : center(pp), r(rr) {}
	R_Triangle(Point pp, int rr, int ang, int cc) : center(pp), r(rr), angle(ang), c(cc) { rot = true; }
	R_Triangle() {}
	void draw_lines() const;
private:
	Point center;
	int r;
	int angle;
	bool rot = false;
	int c = 54000;
};

void R_Triangle::draw_lines() const
{
	vector<Point>ps;
	Point p;
	Point start = center;
	Point dest{ start.x,start.y + r };
	for (int grad = -23; grad <= 45; grad += 45)
	{
		p.x = start.x + (dest.x - start.x)*cos(grad * pi / 180) - (dest.y - start.y)*sin(grad * pi / 180);
		p.y = start.y + (dest.y - start.y)*cos(grad * pi / 180) + (dest.x - start.x)*sin(grad * pi / 180);
		
		if (rot == true)
		{
			//cout << "before - {" << p.x << ';' << p.y << '}' << '\n';
			rotation(p, start, dest, grad+angle);
			//cout << "after - {" << p.x << ';' << p.y << '}' << '\n';
		}
		
		ps.push_back(p);
	}
	
	
	fl_color(c);
	fl_line_style(FL_SOLID, 4);
	fl_line(start.x, start.y, ps[0].x, ps[0].y);
	fl_line(ps[0].x, ps[0].y, ps[1].x, ps[1].y);
	fl_line(ps[1].x, ps[1].y, start.x, start.y);
	

	
	
}

int main()
{
	Simple_window win{ Point{ 80,80 },1000,800, "Kansas" };

	Axis ax{ Axis::x, Point{ 20,700 }, 800,50, "x axis" };
	ax.set_color(Color::red);
	win.attach(ax);

	Axis ay{ Axis::y, Point{ 20,700 }, 550,50, "y axis" };
	ay.set_color(Color::red);
	win.attach(ay);
	
	Vector_ref<R_Triangle>rt;
	
	int x_corr = 63;
	int y_corr = 141;
	int rot = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	int l = 150;
	int clr = 54000;
	int i = 0;
	x = 50;
	y = 100;

	for (int i=0; i < 4; ++i)
	{
		for (int j = 0;j < 14; ++j)
		{
			
			if (rot > 180)	rot = 0;
			if (rot == 0) rt.push_back(new R_Triangle{ Point{ x += x_corr,y },l,rot,clr += clr });
			if (rot == 180) rt.push_back(new R_Triangle{ Point{ x += x_corr,y + y_corr },l,rot,clr += clr });
			rot += 180;
			}
		y += 141;
		x = 50;
		clr = 54000;
		
	}
					
	for (int i =0; i < rt.size();++i)	win.attach(rt[i]);
		win.wait_for_button();
}