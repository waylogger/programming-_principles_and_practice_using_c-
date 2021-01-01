#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>

const double pi = 3.14;
int what_grad(const int & ex, const int & ey, const int & fx, const int & fy)
{
	//ориентир имеет координаты {0:0} : {0:2}; соответственно вектор имеет координаты {0;2}
	//вычисляем угол наклона вектора по отношению к ориентиру
	Point vec{ ex-fx,ey-fy }; //вычисляем координаты вектора
	double a = (vec.x * 0) + (vec.y * 2);
	double b = sqrt(pow(vec.x, 2) + pow(vec.y, 2));
	double c = sqrt(pow(0, 2) + pow(2, 2));
	b = b*c;
	a = a / b;
	a = acos(a) * 180 / pi;
	if (fx < ex) return int(ceil(-a));
	return int(ceil(a));
} //Какой градус?

bool operator > (const Point&p, const Point& p1){
	if 		(p.x>p1.x && p.y>p1.y) return true;
	else if (p.x>p1.x && p.y==p1.y) return true;
	else if (p.x>p1.x && p.y<p1.y) return true;
	else if (p.x==p1.x && p.y>p1.y)return true;
	
	return false;
}
bool operator < (const Point&p, const Point& p1){
	if 		(p.x<p1.x && p.y<p1.y) return true;
	else if (p.x<p1.x && p.y==p1.y) return true;
	else if (p.x<p1.x && p.y>p1.y) return true;
	else if (p.x==p1.x && p.y<p1.y) return true;
	return false;
}
Point operator- (const Point& a, const Point b){
	return (Point{a.x-b.x,a.y-b.y});
}
Point operator+ (const Point& a, const Point b){
	return (Point{a.x+b.x,a.y+b.y});
}
Point rot(const Point& start,const Point& dest, const double& angle)
{
	Point r;
	double x0 = start.x;
	double y0 = start.y;
	double x1 = dest.x;
	double y1 = dest.y;
	r.x = x0+(x1-x0)*cos(angle*pi/180)-(y1-y0)*sin(angle*pi/180);
	r.y = y0+(y1-y0)*cos(angle*pi/180)+(x1-x0)*sin(angle*pi/180);
	return r;
}


vector<Point>seq(const Point&p1, const Point& p2)
{
	vector<Point>ps;
	Point e;
	ps.push_back(p1);
	Point v {p2.x-p1.x,p2.y-p1.y};
	double l = sqrt(pow(v.x,2)+pow(v.y,2));
	const double  ortx = v.x/l;
	const double  orty = v.y/l;
	double x1 =0;
	double y1 =0;
	double x2 =0;
	double y2 =0;
	
	//cout << ortx << ":" << orty << " - xyort\n";

	x1 = p1.x;
	y1 = p1.y;
	x2 = ortx+x1;
	y2 = orty+y1;
	double lp = 0;
	for (int i =0; lp < l ;++i)
	{
		lp = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
		x2+=(ortx);
		y2+=(orty);
		e.x=x2;
		e.y=y2;
		if (i%10==0) ps.push_back(e);
	}
	return ps;
}

class Striped_closed_polyline : public Closed_polyline
{
	public:
	Closed_polyline::Closed_polyline;
	void draw_lines() const override;
	
};
/*
inline pair<double,double> line_intersect(Point p1, Point p2, Point p3, Point p4, bool& parallel) 
{
    double x1 = p1.x;
    double x2 = p2.x;
	double x3 = p3.x;
	double x4 = p4.x;
	double y1 = p1.y;
	double y2 = p2.y;
	double y3 = p3.y;
	double y4 = p4.y;

	double denom = ((y4 - y3)*(x2-x1) - (x4-x3)*(y2-y1));
	if (denom == 0){
		parallel= true;
		return pair<double,double>(0,0);
	}
	parallel = false;
	return pair<double,double>( ((x4-x3)*(y1-y3) - (y4-y3)*(x1-x3))/denom,
								((x2-x1)*(y1-y3) - (y2-y1)*(x1-x3))/denom);
}


//intersection between two line segments
//Returns true if the two segments intersect,
//in which case intersection is set to the point of intersection
bool line_segment_intersect(Point p1, Point p2, Point p3, Point p4, Point& intersection){
   bool parallel;
   pair<double,double> u = line_intersect(p1,p2,p3,p4,parallel);
   if (parallel || u.first < 0 || u.first > 1 || u.second < 0 || u.second > 1) return false;
   intersection.x = p1.x + u.first*(p2.x - p1.x);
   intersection.y = p1.y + u.first*(p2.y - p1.y);
   return true;
} 
*/
void Striped_closed_polyline::draw_lines() const
{
	Closed_polyline::draw_lines();
	
	vector<Point>ps;
	vector<Point>all_lines;
	
	for (int i =0; i <number_of_points();++i)
	{
	if (i+1 > number_of_points()-1) 
	{
		ps = seq(point(number_of_points()-1),point(0));
		for (int i2=0; i2 <ps.size();++i2)
		{
		all_lines.push_back(ps[i2]);
		}
		break;
	}
	ps=seq(point(i),point(i+1));
	
	for (int i2=0; i2 <ps.size();++i2)
	{
	all_lines.push_back(ps[i2]);
	}
	}
	fl_color(FL_BLUE);
	fl_line_style(FL_SOLID,2);
	
	for (int i =0; i < all_lines.size();++i)
	{
	if (i+1 > all_lines.size()-1) break;
	
	fl_line(all_lines[i].x,all_lines[i].y,all_lines[i].x,all_lines[i].y);
	}
	
	double x1 = 0;
	double y1 = 0;
	double x2 = 0;
	double y2 = 0;
	int rav = 0;
	for (int i =0; i < all_lines.size();++i)
	{
	if (i+1 > all_lines.size()-1) break;
				x1 = all_lines[i].x;
				for (int i2 = 0; i2< all_lines.size();++i2)
		{
				
				x2 = all_lines[i2].x;
				y2 = all_lines[i2].y;
				y1=y2;
				fl_line(x1,y1,x2,y2);
			
		}			
	
	
	}
	

}
	


int main () try {
Simple_window win {Point{10,10},1000,800,"Kansas"};

Striped_closed_polyline scp;

	scp.set_color(Color::red);
	scp.set_style(Line_style(Line_style::solid,4));
	scp.add(Point{500,200});
	scp.add(Point{500,600});
	scp.add(Point{600,400});
	scp.add(Point{600,200});
	scp.add(Point{200,563});
	
win.attach(scp);
	




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