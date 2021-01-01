
const int icon_size = 10;

class Icons : public Shape
{
	public:
	Icons (Point xy) : cross(xy), strip(Point{xy.x-icon_size*2,xy.y+icon_size}), sq(Point{xy.x-icon_size*5,xy.y}) {};
	void draw_lines() const;
	private:
	Point cross, strip, sq;
};

void Icons::draw_lines() const
{
	fl_line(cross.x,cross.y,cross.x-icon_size,cross.y+icon_size);
	fl_line(cross.x-icon_size,cross.y,cross.x,cross.y+icon_size);
	fl_line(strip.x,strip.y,strip.x-icon_size,strip.y);
	fl_rect(sq.x,sq.y,icon_size,icon_size);
	
}