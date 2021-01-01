#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>

class Cross : public Shape // класс рисует график координат
{
	Vector_ref<Axis>va;
	double length = 0;
	Point intersect;
	int natches = 0;
	string label_x;
	string label_y;
	public:
	Cross(Point inter, double l, int n, string lab_x="x", string lab_y="y");
	// конструктор задается координатой начала координат, длинной и числом делений, и именами осей
	void draw_lines() const override;
	void set_color(Color c);
	
	};


Cross::Cross(Point inter, double l, int n, string lab_x, string lab_y)
 : length(l), intersect(inter), natches(n), label_x(lab_x), label_y(lab_y)
{
	Point start_of_x {int(intersect.x-length/2),intersect.y};
	Point start_of_y {intersect.x,int(intersect.y+length/2)};
	
	va.push_back(new Axis{Axis::x,start_of_x,int(length),natches,label_x});
	va.push_back(new Axis{Axis::y,start_of_y,int(length),natches,label_y});
}

void Cross::draw_lines() const //рисуем линии
{
	for (int i =0; i <va.size();++i)
	{
		va[i].draw_lines();
	}
}

void Cross::set_color(Color c) //задаем цвет
{
	for (int i =0; i <va.size();++i)
	{
		Shape::set_color(c);
		va[i].set_color(c);
	}
}

double one (double x) {return 1;}

double slope(double x) {return x/2;}

double square (double x) {return x*x;}

double sloping_cos(double x) {return cos(x)+slope(x);}
	


int main () try {
int xmax = 600;
int ymax = 600;
int indentation = 100;
Point window_start {600,200};
string window_label = "Graphics of functions"; 
Simple_window win {window_start,xmax,ymax,window_label};

Cross cr {Point{300,300},400,20,"1 == 20 pixels","1 == 20 pixels"};
cr.set_color(Color::red);
win.attach(cr);


Function f1 {one,-10,11,Point{300,300},400,20,20};
f1.set_color(Color::red);
win.attach(f1);

Function f2 {slope,-10,11,Point{300,300},400,20,20};
f2.set_color(Color::red);
win.attach(f2);

Text t {Point{indentation,ymax-indentation},"x/2"};
t.set_color(Color::red);
win.attach(t);

Function f3 {square,-10,11,Point{300,300},400,20,20};
f3.set_color(Color::red);
win.attach(f3);

Function f4 {cos,-10,11,Point{300,300},400,20,20};
f4.set_color(Color::blue);
win.attach(f4);

Function f5 {sloping_cos,-10,11,Point{300,300},400,20,20};
f5.set_color(Color::green);
win.attach(f5);



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