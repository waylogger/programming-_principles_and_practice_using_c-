#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>



/*
При выполнении данного задания я столкнулся с множеством сложностей:
1.  VBA на работе внес хаос в мое отложенное С++ мышление
2. 	Возникли сложности с наследованием контсруктора класса Function в результате чего класс Fct стал производным классом
класса Shape
3. Так же возникли сложности из-за нахождения вычислений внутри контсруктора, что не давало изменять параметры после конструирования объекта
так чтобы вслед за ним изменялись и сохраненные объекты
4. Поэтому вычисления были вынесены в отдельную функцию, которая срабатывает каждый раз при изменении любого параметра
5. Перед новым вычислением удаляются все вычисленные ранее точки

*/


namespace Ex
{
	
class Fct : public Shape
{
	public:
	Fct (Graph_lib::Fct ff, double r1, double r2, Point xy, int count = 100, double xscale = 25, 
	double yscale = 25, double fin=1);
	
	void set_start (const Point& p) {start = p; calc();}
	void set_diap (const pair<double,double>& d) {diap=d; calc();}
	void set_count (const int& i) {num_of_count=i;calc();}
	void set_scale (const pair<double,double>ss) {scale=ss; calc();}
	
	void set_fct (Graph_lib::Fct ff) {f=ff;calc();}
	
	void add(const Point& p) {ps.push_back(p);}
	void draw_lines() const; //рисует линии
	private:
	
	void calc(); //выполняет все основные вычисления
	Graph_lib::Fct* f;
	pair<double,double>diap;
	pair<double,double>scale;
	Point start;
	int num_of_count;
	vector<Point>ps; //хранит вычисленные точки
	vector<Point>p_of_graph() const {return ps;}
	double fn;
}; 


Fct::Fct (Graph_lib::Fct ff, double r1, double r2, Point xy, int count , double xscale, double yscale,double fin)
	: 	f (ff), diap{r1,r2}, start(xy),	num_of_count (count), scale{xscale,yscale}, fn(fin)
{
	calc();	
}

void Fct::calc()
{
	ps.erase(ps.begin(),ps.end());
	if (diap.second-diap.first<=0) error("bad graphing range");
		if (num_of_count<=0) error("non-positive graphing count");
		double dist = ((diap.second-diap.first)/num_of_count)*fn;
		double r = diap.first;
		for (int i = 0; i<num_of_count; ++i) {
		add(Point{start.x+int(r*scale.first),start.y-int(f(r)*scale.second)});
		r += dist;
		
	}

}

void Fct::draw_lines () const
{
	for(int i = 0, j = 1; j < p_of_graph().size();++i,++j)
	{
		Point a = p_of_graph()[i];
		Point b = p_of_graph()[j];
		fl_begin_line();
		fl_line(a.x,a.y,b.x,b.y);
		fl_end_line();
	}
}


} // namespace Ex


int main () try {
	
	

Simple_window win {Point{20,20},800,800,"Kansas"};

for (double i = 0; i < 1; i+=0.01)
{
	Ex::Fct f {sin,-11,10,Point{200,200},100,25,25,i};
	win.attach(f);
	f.set_color(Color::red);
	win.wait_for_button();
	win.detach(f);
}



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