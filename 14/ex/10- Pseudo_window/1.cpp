#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>
#include <D:\\Programms\\14\\ex\\10- Pseudo_window\\box.cpp>
#include <D:\\Programms\\14\\ex\\10- Pseudo_window\\icons.cpp>
#include <D:\\Programms\\14\\ex\\9 - Group\\1.cpp>

class Pseudo_window : public Group
{
	public:
	Pseudo_window(Point xy, int w, int h, string l);
	private:
	Point p;
	int high;
	int width;
	string lab;
};

Pseudo_window::Pseudo_window(Point xy, int w, int h, string l)
: p(xy), high(h), width(w), lab(l)
{
	add(new Box (p,high,width,lab));
	add(new Icons(Point{p.x+width,p.y-icon_size/2}));
}

int main () try {
Simple_window win {Point{10,10},800,600,"Kansas"};

Pseudo_window pw {Point{500,200},200,200,"Kansas"};
for (int i =0; i < pw.size(); ++i)
{
	pw.number(i).set_color(Color::red);
	win.attach(pw.number(i));
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