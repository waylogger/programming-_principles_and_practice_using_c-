#include <Graph.h>
#include <Simple_window.h>

const double pi = 3.1415;

class Regular_polygone : public Shape
{
public:
	Regular_polygone(Point p, int gg, int rr) : center(p), rad(rr), u(gg){}
	void draw_lines() const;
private:
	Point center;
	int rad;
	int u;
};

void Regular_polygone::draw_lines() const
{
	
	vector<Point>ps;
	Point p;
	double angel = 360/u;
	Point e = center;
	Point	dest  { e.x,e.y + rad };
	Point	start  { e.x,e.y };
	
	for (double grad = 0; grad < 360; grad += angel)
	{
		p.x = start.x + (dest.x - start.x)*cos(grad * pi / 180) - (dest.y - start.y)*sin(grad * pi / 180);
		p.y = start.y + (dest.y - start.y)*cos(grad * pi / 180) + (dest.x - start.x)*sin(grad * pi / 180);
		ps.push_back(p);
	}
	
	for (int i = 0; i < ps.size(); ++i)
	{
		if (i + 1 < ps.size()) fl_line(ps[i].x, ps[i].y, ps[i+1].x, ps[i+1].y);
		if (i == 0)
		{
			fl_line(ps[0].x, ps[0].y, ps[ps.size()-1].x, ps[ps.size() - 1].y);

		}
		
	}
	

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
	
	Vector_ref<Regular_polygone>v;
	int x = 0;
	int y = 100;
	int x_corr = 87;
	int y_corr = 77;
	bool rub = true;
	int clr = 5400;
	for (int j = 0; j < 10; ++j)
	{
		for (int i = 0; i < 11; ++i)
		{
			v.push_back(new Regular_polygone{ Point{x += x_corr,y },6, 50 });
		}
		y += y_corr;
		
		if (rub) 
		{
			x = -44; rub = { false };
		}
		else
		{
			x = 0; rub = { true };
		}
	}

	for (int i = 0; i < v.size(); ++i)
	{
		v[i].set_color(clr+=100000);
		
		v[i].set_style(Line_style(Line_style::solid, 4));
		win.attach(v[i]);
	}
		
		win.wait_for_button();
	
		
	
}