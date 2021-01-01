
const int standart_radius = 10;


class Box : public Shape
{
public:
Box() {}
Box (Point xy, int w, int h, string l);
void draw_lines() const;
int high_of_box () const {return high;}
private:
Point p;
int width;
int high;
string lab;
};

Box::Box (Point xy, int w, int h, string l) : p (xy), width(w), high (h), lab(l)
{
	add(p);
	add(Point{p.x+width,p.y});
	add(Point{p.x+width,p.y+high});
	add(Point{p.x,p.y+high});
}

void Box::draw_lines() const 
{
		fl_font(FL_TIMES,14);
		fl_draw(lab.c_str(),point(0).x,point(0).y+(standart_radius/2));
		fl_begin_loop();
		fl_arc(point(0).x,point(0).y,standart_radius,180,90);
		fl_arc(point(1).x,point(1).y,standart_radius,90,0);
		fl_arc(point(2).x,point(2).y,standart_radius,360,270);
		fl_arc(point(3).x,point(3).y,standart_radius,270,180);
		fl_end_loop();
		fl_line(point(0).x-standart_radius,point(0).y+standart_radius,point(1).x+standart_radius,point(1).y+standart_radius);
		
}