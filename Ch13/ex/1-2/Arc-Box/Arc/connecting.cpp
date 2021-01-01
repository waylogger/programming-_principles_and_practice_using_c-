
Point n(const Graph_lib::Rectangle& e)
{
	int h = e.height();
	int w = e.width();
	
		for (int i = 0; i < e.number_of_points(); ++i)
		{
			Point pp{ e.point(i).x+(w/2),e.point(i).y };
			return pp;
		}
}
Point s(const Graph_lib::Rectangle& e)
{
	int h = e.height();
	int w = e.width();

	for (int i = 0; i < e.number_of_points(); ++i)
	{
		Point pp{ e.point(i).x + (w / 2),e.point(i).y + h };
		return pp;
	}
}
Point e(const Graph_lib::Rectangle& rec)
{
	int h = rec.height();
	int w = rec.width();

	for (int i = 0; i < rec.number_of_points(); ++i)
	{
		Point pp{ rec.point(i).x,rec.point(i).y + h / 2 };
		return pp;
	}
}
Point w(const Graph_lib::Rectangle& rec)
{
	int h = rec.height();
	int w = rec.width();

	for (int i = 0; i < rec.number_of_points(); ++i)
	{
		Point pp{ rec.point(i).x + w,rec.point(i).y + h / 2 };
		return pp;
	}
}
Point center(const Graph_lib::Rectangle& rec)
{
	int h = rec.height();
	int w = rec.width();

	for (int i = 0; i < rec.number_of_points(); ++i)
	{
		Point pp{ rec.point(i).x + w / 2,rec.point(i).y + h / 2 };
		return pp;
	}
}
Point ne(const Graph_lib::Rectangle& rec)
{
	int h = rec.height();
	int w = rec.width();

	for (int i = 0; i < rec.number_of_points(); ++i)
	{
		Point pp{ rec.point(i).x,rec.point(i).y };
		return pp;
	}
}
Point se(const Graph_lib::Rectangle& rec)
{
	int h = rec.height();
	int w = rec.width();

	for (int i = 0; i < rec.number_of_points(); ++i)
	{
		Point pp{ rec.point(i).x,rec.point(i).y + h };
		return pp;
	}
}
Point sw(const Graph_lib::Rectangle& rec)
{
	int h = rec.height();
	int w = rec.width();

	for (int i = 0; i < rec.number_of_points(); ++i)
	{
		Point pp{ rec.point(i).x + w,rec.point(i).y + h };
		return pp;
	}
}
Point nw(const Graph_lib::Rectangle& rec)
{
	int h = rec.height();
	int w = rec.width();

	for (int i = 0; i < rec.number_of_points(); ++i)
	{
		Point pp{ rec.point(i).x + w,rec.point(i).y };
		return pp;
	}
}
Point center(const Graph_lib::Ellipse& ell)
{
	int h = ell.minor();
	int w = ell.major();

	for (int i = 0; i < ell.number_of_points(); ++i)
	{
		Point pp = ell.center();
		return pp;
	}
}
Point n(const Graph_lib::Ellipse& ell)
{
	int h = ell.minor();
	int w = ell.major();
	Point cent = ell.center();

	for (int i = 0; i < ell.number_of_points(); ++i)
	{

		Point pp{ cent.x,cent.y - h };
		return pp;
	}
}
Point s(const Graph_lib::Ellipse& ell)
{
	int h = ell.minor();
	int w = ell.major();
	Point cent = ell.center();

	for (int i = 0; i < ell.number_of_points(); ++i)
	{

		Point pp{ cent.x,cent.y + h };
		return pp;
	}
}
Point w(const Graph_lib::Ellipse& ell)
{
	int h = ell.minor();
	int w = ell.major();
	Point cent = ell.center();

	for (int i = 0; i < ell.number_of_points(); ++i)
	{

		Point pp{ cent.x - w,cent.y };
		return pp;
	}
}
Point e(const Graph_lib::Ellipse& ell)
{
	int h = ell.minor();
	int w = ell.major();
	Point cent = ell.center();

	for (int i = 0; i < ell.number_of_points(); ++i)
	{

		Point pp{ cent.x + w,cent.y };
		return pp;
	}
}
Point nw(const Graph_lib::Ellipse& ell)
{
	int h = ell.minor();
	int w = ell.major();
	Point cent = ell.center();

	for (int i = 0; i < ell.number_of_points(); ++i)
	{

		Point pp{ cent.x - w,cent.y - h };
		return pp;
	}
}
Point sw(const Graph_lib::Ellipse& ell)
{
	int h = ell.minor();
	int w = ell.major();
	Point cent = ell.center();

	for (int i = 0; i < ell.number_of_points(); ++i)
	{

		Point pp{ cent.x - w,cent.y + h };
		return pp;
	}
}
Point se(const Graph_lib::Ellipse& ell)
{
	int h = ell.minor();
	int w = ell.major();
	Point cent = ell.center();

	for (int i = 0; i < ell.number_of_points(); ++i)
	{

		Point pp{ cent.x + w,cent.y + h };
		return pp;
	}
}
Point ne(const Graph_lib::Ellipse& ell)
{
	int h = ell.minor();
	int w = ell.major();
	Point cent = ell.center();

	for (int i = 0; i < ell.number_of_points(); ++i)
	{

		Point pp{ cent.x + w,cent.y - h };
		return pp;
	}
}
Point center(const Graph_lib::Circle& c)
{
	//int rad = c.radius();
	Point center = c.center();

	for (int i = 0; i < c.number_of_points(); ++i)
	{
		Point pp = center;
		return pp;
	}
}
Point n(const Graph_lib::Circle& c)
{
	int rad = c.radius();
	Point center = c.center();

	for (int i = 0; i < c.number_of_points(); ++i)
	{
		Point pp{ center.x,center.y - rad };
		return pp;
	}
}
Point w(const Graph_lib::Circle& c)
{
	int rad = c.radius();
	Point center = c.center();

	for (int i = 0; i < c.number_of_points(); ++i)
	{
		Point pp{ center.x - rad,center.y };
		return pp;
	}
}
Point s(const Graph_lib::Circle& c)
{
	int rad = c.radius();
	Point center = c.center();

	for (int i = 0; i < c.number_of_points(); ++i)
	{
		Point pp{ center.x ,center.y + rad };
		return pp;
	}
}
Point e(const Graph_lib::Circle& c)
{
	int rad = c.radius();
	Point center = c.center();

	for (int i = 0; i < c.number_of_points(); ++i)
	{
		Point pp{ center.x + rad ,center.y };
		return pp;
	}
}
Point nw(const Graph_lib::Circle& c)
{
	int rad = c.radius();
	Point center = c.center();

	for (int i = 0; i < c.number_of_points(); ++i)
	{
		Point pp{ center.x - rad ,center.y - rad };
		return pp;
	}
}
Point sw(const Graph_lib::Circle& c)
{
	int rad = c.radius();
	Point center = c.center();

	for (int i = 0; i < c.number_of_points(); ++i)
	{
		Point pp{ center.x - rad ,center.y + rad };
		return pp;
	}
}
Point se(const Graph_lib::Circle& c)
{
	int rad = c.radius();
	Point center = c.center();

	for (int i = 0; i < c.number_of_points(); ++i)
	{
		Point pp{ center.x + rad ,center.y + rad };
		return pp;
	}
}
Point ne(const Graph_lib::Circle& c)
{
	int rad = c.radius();
	Point center = c.center();

	for (int i = 0; i < c.number_of_points(); ++i)
	{
		Point pp{ center.x + rad ,center.y - rad };
		return pp;
	}
}

Point n(const Box& c)
{
	int h = c.height();
	int w = c.weight();
	Point p{ c.nw().x-w/2, c.nw().y };
	
	return p;
}

Point s(const Box& c)
{
	int h = c.height();
	int w = c.weight();
	Point p { c.nw().x - w / 2, c.nw().y + h };

	return p;
}

Point w(const Box& c)
{
	int h = c.height();
	int w = c.weight();
	Point p{ c.nw().x - w , c.nw().y + h/2 };

	return p;
}

Point e(const Box& c)
{
	int h = c.height();
	int w = c.weight();
	Point p{ c.nw().x, c.nw().y + h / 2 };

	return p;
}


