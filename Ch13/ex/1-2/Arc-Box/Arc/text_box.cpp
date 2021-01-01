
class Text_Box : public Shape
{
private:
	int radius = 0;
	Point p1, p2, p3, p4;
	vector<Point>lines_of;
public:
	void draw_lines() const;
	vector<Point>lines(const int&);

	Box(Point pp, int rr,int ww,int h) : 
		p1(pp), 
		p2(Point{ pp.x-ww,pp.y }), 
		p3(Point{ pp.x-ww,pp.y +h }),
		p4(Point{ pp.x,pp.y+h}),
		radius(rr)
		
	{
		Shape::add(p1);		Shape::add(p2);
		Shape::add(p3);		Shape::add(p4);
		lines(rr);
	}
}; //рисуем прямоугольник с закруглёнными углами


void Box::draw_lines() const
{
	for (int i = 0; i < number_of_points(); ++i)
	{
		fl_begin_line();
		if (i==0) fl_arc(point(i).x, point(i).y, radius, 90, 0);
		if (i == 1) fl_arc(point(i).x, point(i).y, radius, 180, 90);
		if (i == 2) fl_arc(point(i).x, point(i).y, radius, 270, 180);
		if (i == 3) fl_arc(point(i).x, point(i).y, radius, 360, 270);
		fl_end_line();
	}
	
	for (int i = 0; i < lines_of.size(); i+=2)
	{
		if (i+1<lines_of.size()) 

				fl_line	(lines_of[i].x, lines_of[i].y, 
						lines_of[i + 1].x, lines_of[i + 1].y);
	}


}
vector<Point> Box::lines(const int& rad)
{
	Point pl1{ p1.x, p1.y -rad };		Point pl2{ p2.x, p1.y - rad };		
	Point pl3{ p2.x - rad , p2.y };		Point pl4{ p3.x - rad , p3.y };
	Point pl5{ p3.x,p3.y + rad };		Point pl6{ p4.x,p4.y + rad };
	Point pl7{ p4.x + rad,p4.y };		Point pl8{ p1.x + rad,p1.y };
	
	lines_of.push_back(pl1);	lines_of.push_back(pl2);
	lines_of.push_back(pl3);	lines_of.push_back(pl4);
	lines_of.push_back(pl5);	lines_of.push_back(pl6);
	lines_of.push_back(pl7);	lines_of.push_back(pl8);
	return lines_of;
}