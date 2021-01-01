const double pi = 3.1415;
Point turn (const Point& start, const Point& dest, const double& angle)
{
	double x0 = start.x;
	double y0 = start.y;
	double x1 = dest.x;
	double y1 = dest.y;
	
	Point p;
	p.x = x0+(x1-x0)*cos(angle*pi/180)-(y1-y0)*sin(angle*pi/180);
	p.y = y0+(y1-y0)*cos(angle*pi/180)+(x1-x0)*sin(angle*pi/180);
	return p;
}
