
class Arct : public Shape
{
private:
	Point p;
	int rad;
	double start_rad;
	double end_rad;
public:
	Arct(Point pp, int rr, double s_r, double e_r) : p(pp), rad(rr), start_rad(s_r),end_rad(e_r) { }
	void draw_lines() const;
}; //рисуем полукруг
void Arct::draw_lines() const
{
	fl_begin_line();
	fl_arc(p.x, p.y, rad, start_rad, end_rad);
	fl_end_line();
}