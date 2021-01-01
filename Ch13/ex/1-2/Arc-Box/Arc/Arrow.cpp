const double pi = 3.1415;

class Arrow : public Shape
{
	public:
	Arrow() { }
	void add(Point a,Point b) { Shape::add(a), Shape::add(b); }
	void draw_lines() const;
}; // блядские стрелочки
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




	//cout << c << '\\n';
	//cout << b << '\\n';
	//cout << vec.x << ' ' << vec.y << '\\n';
	//cout << a << '\\n';
	//cout << ceil(a)  << '\\n';
} //Какой градус?
Point lpls(const int& grad, const int & ex, const int & ey)
{
	int fx = ex + 7;
	int fy = ey + 10;
	Point p;
	p.x = ex + (fx - ex)*cos(grad * pi / 180) - (fy - ey)*sin(grad * pi / 180);
	p.y = ey + (fy - ey)*cos(grad * pi / 180) + (fx - ex)*sin(grad * pi / 180);
	
	return p;
	
} //Левый лепесток
Point rpls(const int& grad, const int & ex, const int & ey)
{
	int fx = ex - 7;
	int fy = ey + 10;
	Point p;
	p.x = ex + (fx - ex)*cos(grad * pi / 180) - (fy - ey)*sin(grad * pi / 180);
	p.y = ey + (fy - ey)*cos(grad * pi / 180) + (fx - ex)*sin(grad * pi / 180);
	return p;
}//Правый лепесток
void Arrow::draw_lines() const
{
	
	for (int i = 0; i < number_of_points(); i += 2)
		if (i + 1 < number_of_points())
		{
				
				
				fl_line(point(i).x, point(i).y, point(i+1).x, point(i+1).y); 
				int grad = what_grad(point(i).x, point(i).y, point(i + 1).x, point(i + 1).y); // градус наклона относительно оси Y
				//cout << grad << '\\n';

				Point clpls = lpls(grad, point(i + 1).x, point(i + 1).y);
				fl_line(point(i + 1).x, point(i + 1).y, clpls.x, clpls.y);
				Point crpls = rpls(grad, point(i + 1).x, point(i + 1).y);
				fl_line(point(i + 1).x, point(i + 1).y, crpls.x, crpls.y);
			
				
		}
			
}