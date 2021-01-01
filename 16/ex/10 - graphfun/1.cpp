/*

Окно рисующее графики функций
Заострить нужно внимание на 2 моментах.
1. Очистка окна функцией detach при рисовании новой функции
2. Работа только со строкой в виджете In_box из-за особенностей реализации данного виджета, не позволяющих использовать отрицательные числа



*/



#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>

pair<double,double>min_max(const string& s1, const string& s2)
//переводим строки в double
{
	string a,b;
	string fmax, fmin;
	ostringstream ostm {a};
	ostringstream ostx {b};
	ostm << s1;
	ostx << s2;
	
	for (int i =0; i<ostm.str().size();++i)
	{
		if (isdigit(ostm.str()[i])) fmin+=ostm.str()[i];
	}
	
	for (int i =0; i<ostx.str().size();++i)
	{
		if (isdigit(ostx.str()[i])) fmax+=ostx.str()[i];
	}
	
	istringstream istm {fmin};
	istringstream istx {fmax};
	double m=0,x=0;
	istm >> m;
	istx >> x;
	if (ostm.str()[0]=='-') m = -m;
	if (ostx.str()[0]=='-') x = -x;
	return pair<double,double>{m,x};
}


struct Cross : Shape

//рисуем хрестик
{
	Cross(Point p, int length, int natches =0);
	Axis& axis (int i) {return gr[i];}
	void draw_lines() const override;
	int number_of_axis () const {return gr.size();}
	
	private:
	Vector_ref<Axis>gr;
	Point start;
	int l;
	int n;
};

void Cross::draw_lines() const
{
	for (int i =0; i < number_of_axis();++i)
	{
		gr[i].draw_lines();
	}
}


Cross::Cross(Point p, int length, int natches) :
start(p), l(length), n(natches)
{
	gr.push_back(new Axis{Axis::x,start,l,n,"x"});
	gr.push_back(new Axis{Axis::y,start,l,n,"y"});
		
}


struct Graph_window : Window
{
	Graph_window(Point p, int w, int h, const string& s);
	static void cb_quit(Address, Address pw) {reference_to<Graph_window>(pw).quit();}
	static void cb_sin (Address, Address pw) {reference_to<Graph_window>(pw).draw_sin();}
	static void cb_cos (Address, Address pw) {reference_to<Graph_window>(pw).draw_cos();}
	static void cb_acos (Address, Address pw) {reference_to<Graph_window>(pw).draw_acos();}
	
	static void cb_tan (Address, Address pw) {reference_to<Graph_window>(pw).draw_tan();}
	static void cb_exp (Address, Address pw) {reference_to<Graph_window>(pw).draw_exp();}
	
	void quit () {hide();}
	void draw_sin();
	void draw_cos();
	void draw_acos();
	void draw_tan();
	void draw_exp();
	private:
	Vector_ref<Function>vrf;
	Point start;
	int width;
	int higth;
	string lab;
	Cross cr {Point{75,higth-50},int(width-50),width/10};
	Menu menu_function;
	Button quit_button;
	In_box max;
	In_box min;
	
};
void Graph_window::draw_sin()
{
	
	pair<double,double>mx=min_max(min.get_string(),max.get_string());
	double m = mx.first;
	double x = mx.second;
	for (int i =0; i <vrf.size();++i)
	{
		detach(vrf[i]);
	}

	vrf.push_back(new Function{sin,m,x,Point{width/2,higth/2}});
	attach(vrf[vrf.size()-1]);
	redraw();
}

void Graph_window::draw_cos()
{
	
	pair<double,double>mx=min_max(min.get_string(),max.get_string());
	double m = mx.first;
	double x = mx.second;
	for (int i =0; i <vrf.size();++i)
	{
		detach(vrf[i]);
	}
	vrf.push_back(new Function{cos,m,x,Point{width/2,higth/2}});
	attach(vrf[vrf.size()-1]);
	redraw();
}

void Graph_window::draw_acos()
{
	
	pair<double,double>mx=min_max(min.get_string(),max.get_string());
	double m = mx.first;
	double x = mx.second;
	for (int i =0; i <vrf.size();++i)
	{
		detach(vrf[i]);
	}
	vrf.push_back(new Function{acos,m,x,Point{width/2,higth/2}});
	attach(vrf[vrf.size()-1]);
	redraw();
}

void Graph_window::draw_tan()
{
	
	pair<double,double>mx=min_max(min.get_string(),max.get_string());
	double m = mx.first;
	double x = mx.second;
	for (int i =0; i <vrf.size();++i)
	{
		detach(vrf[i]);
	}
	vrf.push_back(new Function{tan,m,x,Point{width/2,higth/2}});
	attach(vrf[vrf.size()-1]);
	redraw();
}

void Graph_window::draw_exp()
{
	
	pair<double,double>mx=min_max(min.get_string(),max.get_string());
	double m = mx.first;
	double x = mx.second;
	for (int i =0; i <vrf.size();++i)
	{
		detach(vrf[i]);
	}
	vrf.push_back(new Function{exp,m,x,Point{width/2,higth/2}});
	attach(vrf[vrf.size()-1]);
	redraw();
}

Graph_window::Graph_window(Point p, int w, int h, const string& s) :
Window{p,w,h,s}, start(p), width(w), higth(h),
quit_button{Point{0,0},70,20,"quit",cb_quit},
menu_function(Point{0,60},70,20,Menu::vertical,"Functions"),
min {Point{0,20},70,20,""},
max {Point{0,40},70,20,""}
{
	attach(quit_button);
	attach(min);
	attach(max);
	menu_function.attach(new Button{Point{0,0},0,0,"sin",cb_sin});
	menu_function.attach(new Button{Point{0,0},0,0,"cos",cb_cos});
	menu_function.attach(new Button{Point{0,0},0,0,"acos",cb_acos});
	menu_function.attach(new Button{Point{0,0},0,0,"tg",cb_tan});
	menu_function.attach(new Button{Point{0,0},0,0,"exp",cb_exp});
	attach(menu_function);
	
		
	for (int i =0; i < cr.number_of_axis(); ++i)
	{
		cr.axis(i).set_color(Color::red);
		attach(cr.axis(i));
	}
}

int main () try {

Graph_window wg {Point{20,20},800,600,"Kansas"};




gui_main();


}
catch (exception& e){
	cerr << e.what() << '\n';
	keep_window_open();
}
catch (...){
	cerr << "Unknown error" << '\n';
	keep_window_open();
}