#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>
namespace Space_of_Histogram
{// start of namespace Histogram

const int x_max = 800; //ширина окна
const int y_max = 600; //высота окна


const int typical_field = 100; //обычное поле
const Point start{typical_field,typical_field}; //начало окна

const int left_field = typical_field;
const int right_field = x_max-typical_field;

const int up_field = typical_field;
const int down_field = y_max-typical_field;

const Point graphic_start {left_field,down_field}; //старт графика


class Column //класс столбиков
{
	double hide; //высота
	Color color{0}; //цвет
	string label; //метка
	public:
	double view_hide() const {return hide;}
	Color view_color() const {return color;}
	string view_label() const {return label;}
	
	Column () {}
	Column (double h, Color c, string l) : hide(h), color(c), label(l) {}
};


class Histogram : public Shape
{
	vector<Column>his; //яШычек
	void calc(); //вычислительная работа - основная полезная функция
	int scale; //масштабирование
 	public:
	void draw_lines() const; //рЫсование
	Histogram(const vector<Column>& h, const int& s) : his(h), scale(s) { calc ();}
	Histogram () {}
};

void Histogram::calc()
{
	Point p;
	int length_of_col = (x_max-(typical_field*2))/his.size(); 	//ширина столбца расчитывется так, чтобы занять всю ось абсцысс
	for (int i = 0, j = 1; i < his.size(); ++i, ++j)
	{
	p.x = graphic_start.x+(length_of_col*j); 					//размещаем базовые точки столбцов - правый вернхний угол
																//рассчитывается как начало графика + ширина столбца*на их число
	p.y = down_field-his[i].view_hide()*scale; 						//просто вычисляем высоту как разницу 
																//координаты нижнего поля и заданной высоты и масштабируем
	Shape::add(p);
	}
	}

void Histogram::draw_lines() const
{
	Axis x {Axis::x,graphic_start,x_max-(typical_field*2),int(his.size())}; //ось х
	x.set_color(Color::red);
	fl_color(FL_RED);
	x.draw_lines();
	
	Axis y {Axis::y,graphic_start,y_max-(typical_field*2),((y_max-(typical_field*2))/(10*scale))};
																			//ось у
	y.set_color(Color::red);
	y.draw_lines();
	
	
	int width = (x_max-(typical_field*2))/his.size(); 						//ширина столбца
	int hide = 0;
	Point p;
	
	for (int i =0; i < number_of_points(); ++i)
	{
		
		p.x = point(i).x-width;
		p.y = point(i).y;
		hide = down_field-p.y;
		
		fl_color(FL_RED); 													//пишем метку своим цветом
		fl_draw(his[i].view_label().c_str(),p.x+(width/2),p.y);
		
		fl_color(his[i].view_color().as_int()); 									//закрашиваем рамку
		fl_rectf(p.x,p.y,width,hide);
		
		fl_color(FL_BLACK); 												//рисуем рамку
		fl_rect(p.x,p.y,width,hide);
	}
	}


Color return_color(const string& color)
{
	Color clr{0};
	if (color=="red") 			return Color::red;
	if (color=="blue") 			return Color::blue;
	if (color=="green")			return Color::green;
	if (color=="yellow") 		return Color::yellow;
	if (color=="white") 		return Color::white;
	if (color=="black") 		return Color::black;
	if (color=="magenta") 		return Color::magenta;
	if (color=="cyan") 			return Color::cyan;
	if (color=="dark red") 		return Color::dark_red;
	if (color=="dark green")	return Color::dark_green;
	if (color=="dark yellow") 	return Color::dark_yellow;
	if (color=="dark blue") 	return Color::dark_blue;
	if (color=="dark magenta") 	return Color::dark_magenta;
	if (color=="dark cyan") 	return Color::dark_cyan;
	return clr;
}
ifstream& operator >> (ifstream&ist, Column& c)
{

	char ch1,ch2,ch3,ch4,ch5,ch6 = 0;
	char chm = 0;
	
	double h = 0;
	string color;
	Color clr{0};
	string s;
	ist >> ch1 >> h >> ch2 >> ch3;
	if (ist.fail()) {return ist;}
	
	while (chm != ')') {ist >> chm; if (chm!= ')') color+=chm;}
	if (chm==')') ist.putback(chm);
	ist >> ch4 >> ch5;
	
	chm = 0;
	while (chm != ')') {ist >> chm; if (chm!= ')') s+=chm;}
	if (chm==')') ist.putback(chm);
	ist >> ch6;
	
	if (ch1 != '(' || ch2 != ')' || ch3 != '(' || ch4 != ')' || ch5 != '(' || ch6 !=')')
	{ist.clear(ios_base::failbit); return ist;}
	
	
	clr = return_color(color);
	c = Column{h,clr,s};
	ist.clear();
	
	return ist;
}


} // end of namespace Histogram

int main () try {
using Space_of_Histogram::start;
using Space_of_Histogram::x_max;
using Space_of_Histogram::y_max;
using Space_of_Histogram::left_field;
using Space_of_Histogram::down_field;
using Space_of_Histogram::up_field;
using Space_of_Histogram::right_field;
using Space_of_Histogram::Histogram;
using Space_of_Histogram::graphic_start;
using Space_of_Histogram::typical_field;
using Space_of_Histogram::Column;
Simple_window win {start,x_max,y_max,"Kansas"};


string path = "D:\\Programms\\15\\ex\\6 - histogram\\data\\2.txt";
vector<Column>vc;

ifstream ist {path};
if (!ist) error ("Cant open file");

for(Column col; ist >> col;) 	vc.push_back(col);



Histogram h{vc,1};

win.attach(h);
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