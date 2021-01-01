/*
Проблемы с навигацией, иногда забываю в какой функции нахожусь, технически, а не идейно.
Не определил все переменные и запустил программу.
*/


#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>
const double pi = 3.14;

class Striped_circle : public Circle
{
	public:
	using Circle::Circle;
	void draw_lines() const override;
};

double hordes_length (const double& rad,const double& angle) 							//вычисляем длинну хорды
{
	double l = 2*rad*sin((angle*pi/180)/2);
	return l;
}


double hordes_heigth(const double& hordes_length, const double& side) 					//вычисляем высоту на которой хорда удалена от центра
{
	 double h = sqrt(pow(side,2)-pow(hordes_length,2)/4);
	 return h;
}

pair<Point,Point> horde (const Point&center, const double& rad,const double& angle){ 	//вычисляем координаты хорды
	
	Point left;
	Point right;
	double l = hordes_length(rad,angle); 												//левый
	double h = hordes_heigth(l,rad);													//правый
	left.x=center.x-l/2;
	if (angle>=180) left.y=center.y+h;
	if (angle<180)  left.y=center.y-h;
	right.x=center.x+l/2;
	if (angle>=180) right.y=center.y+h;
	if (angle<180)  right.y=center.y-h;
	return pair<Point,Point>(left,right);
}

void Striped_circle::draw_lines() const 												//рисуем заштрихованную окружность
{
	Circle::draw_lines();
	for (int i =0; i<=360;i+=10)
	{
	pair<Point,Point>hrd = horde(center(),radius(),i);
	double x1 = hrd.first.x;
	double y1 = hrd.first.y;
	double x2 = hrd.second.x;
	double y2 = hrd.second.y;
	fl_color(FL_RED);
	fl_line(x1,y1,x2,y2);
	}
	
	
}


int main () try {
Simple_window win {Point{10,10},1000,800,"Kansas"};
Striped_circle sc {Point{350,300},200};
sc.set_color(Color::red);
sc.set_style(Line_style(Line_style::solid,3));
win.attach(sc);
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