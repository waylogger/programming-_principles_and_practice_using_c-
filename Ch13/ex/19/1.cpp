#include <Graph.h>
#include <Simple_window.h>
const double pi = 3.1415;


Point turn (const int& i,double x0,double y0,double x1,double y1)
{
	Point p;
	p.x = x0+(x1-x0)*cos(i*pi/180)-(y1-y0)*sin(i*pi/180);
	p.y = y0+(y1-y0)*cos(i*pi/180)+(x1-x0)*sin(i*pi/180);
	return p;
}


class Star : public Shape
{
	public:
	Star(Point c,int n, double r_l,double r_h, int lc, int fc) 
		: center(c), num(n), r_low(r_l),r_hight(r_h), line_color(lc), fill_color(fc) {}
	void draw_lines() const;
	private:
	int num;
	Point center;
	double r_low;
	double r_hight;
	int line_color;
	int fill_color;
};

void Star::draw_lines() const
try
{
	if (num<3 || num >20) error ("Too many or less rays"); 	//у звезды не может быть менее 3 лучей, и более 20
	Point a; 												// точка на большей окружности
	Point b; 												// точка на меньшей
	vector<Point>as; 										//все точки большей окружности
	vector<Point>bs; 										//все точки меньшей окружности
	vector<Point>star; 										//все точки рисуемой звезды
	double angel = 360/num;									//шаг угла
	double x0=center.x; 									//start
	double y0=center.y;										//start
	double x1=center.x; 									//dest дальней точки
	double y1=center.y+r_hight; 							//dest дальней точки
	double x2=center.x;										//dest ближней точки
	double y2=center.y+r_low;								//dest ближней точки
	fl_color(line_color);										//цвет линий
	fl_line_style(FL_SOLID,5);								//стиль линий
	
	for (int i =angel;i<=360;i+=angel)		
		{
			a=turn(i,x0,y0,x1,y1); 	as.push_back(a); 		//вычисляем все дальние точки звезды
		}
	for (int i =(angel/2);i<=360;i+=angel)	
		{
			b=turn(i+angel,x0,y0,x2,y2); 	bs.push_back(b);//вычисляем все ближние точки звезды
		}
	for (int i =0; i<as.size() || i<bs.size();++i)
		{
		star.push_back(as[i]);	star.push_back(bs[i]);		//объединяем все точки
		}
		
		;
	for (int i =0; i< star.size();++i)
		{
			
		if (i+1>star.size()-1) 								//чтобы не было ошибки дипазона дорисовываем и break
		{
			fl_line(star[0].x,star[0].y,star[star.size()-1].x,star[star.size()-1].y);
			break;	
		}
			fl_line(star[i].x,star[i].y,star[i+1].x,star[i+1].y);//рисуем
		}
	
	
	fl_begin_complex_polygon();									//начинаем выделение
	fl_color(fill_color);										//закрашиваем фигуру
	for (int i =0; i<star.size();++i)
	{
	fl_vertex(star[i].x,star[i].y);								//добавляем вершины к закраске
	}
	fl_end_complex_polygon();									//завершаем выделение

}
catch(exception& e)
{
	cerr << e.what() <<'\n';
	keep_window_open();
	exit(0);
}

catch(...)
{
	cerr << "Unknown error" <<'\n';
	keep_window_open();
}


int main () 
try
{
	Simple_window win{Point{400,200},1000,800,"Kansas"};
	
	for (int i =3; i<18;++i)
	{
	Star s{Point{450,200},i,40,150,1000000,50000};
	win.attach(s);
	Star s1{Point{700,200},i+1,40,150,5000000,6400000};
	win.attach(s1);
	Star s2{Point{200,200},i+2,40,150,3000000,8000000};
	win.attach(s2);
	win.wait_for_button();
	}
		win.wait_for_button();
}
catch(exception& e)
{
	cerr << e.what() << '\n';
	keep_window_open();
}

catch(...)
{
	cerr << "Unknown error" << '\n';
	keep_window_open();
}






















