#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>
#include <D:\\Programms\\16\\fun\\Graph_red\\nangle.h>
/*
Программа создающая фигуры и перемещающая их по окну

Да, тут я обленился, она выглядит очень плохо
*/
struct Shaping_window : Window
{
	Shaping_window(Point p, int w, int h, const string& s);
	void move();
	void draw_rect();
	void draw_circle();
	void draw_triangle();
	void draw_oct();
	void quit () {hide();}
	static void cb_quit(Address,Address pw) {reference_to<Shaping_window>(pw).quit();}
	
	static void cb_move(Address,Address pw) {reference_to<Shaping_window>(pw).move();}
	static void cb_draw_rect(Address,Address pw) {reference_to<Shaping_window>(pw).draw_rect();}
	static void cb_draw_circle(Address,Address pw) {reference_to<Shaping_window>(pw).draw_circle();}
	static void cb_draw_triangle(Address,Address pw) {reference_to<Shaping_window>(pw).draw_triangle();}
	static void cb_draw_oct(Address,Address pw) {reference_to<Shaping_window>(pw).draw_oct();}
	private:
	
	Vector_ref<Shape>vrs;
	void attaching () {for (int i =0; i < vrs.size(); ++i) attach(vrs[i]);}
	Menu shaping;
	Button button_quit;
	Button move_shape;
	In_box xspawn;
	In_box yspawn;
	In_box xmove;
	In_box ymove;
	
};
void Shaping_window::move()
{
	int w = xmove.get_int();
	int h = ymove.get_int();
	vrs[vrs.size()-1].move(w,h);
	attaching ();
	redraw();
}
void Shaping_window::draw_rect()
{
	int x = xspawn.get_int();
	int y = yspawn.get_int();
	int w = xmove.get_int();
	int h = ymove.get_int();
	vrs.push_back(new Graph_lib::Rectangle{Point{x,y},w,h});
	attaching ();
	redraw();
	
}

void Shaping_window::draw_triangle()
{
	int x = xspawn.get_int();
	int y = yspawn.get_int();
	int w = xmove.get_int();
	vrs.push_back(new Nangle{Point{x,y},double(w),3});
	attaching ();
	redraw();
}

void Shaping_window::draw_circle()
{
	int x = xspawn.get_int();
	int y = yspawn.get_int();
	int w = xmove.get_int();
	vrs.push_back(new Graph_lib::Circle{Point{x,y},w});
	attaching ();
	redraw();
	
}


void Shaping_window::draw_oct()
{
	int x = xspawn.get_int();
	int y = yspawn.get_int();
	int w = xmove.get_int();
	vrs.push_back(new Nangle{Point{x,y},double(w),6});
	attaching ();
	redraw();
}
Shaping_window::Shaping_window(Point p, int w, int h, const string& s)
: Window{p,w,h,s},
shaping{Point{0,200},70,20,Menu::vertical,"shaping"},
move_shape{Point{70,200},70,20,"Move",cb_move},
button_quit{Point{0,180},70,20,"Quit",cb_quit},
xspawn{Point{210,200},70,20,"Xspawn"},
yspawn{Point{210,220},70,20,"Yspawn"},
xmove{Point{210,240},70,20,"Xmove"},
ymove{Point{210,260},70,20,"Ymove"}
{
	shaping.attach(new Button{Point{0,0},0,0,"Rect",cb_draw_rect});
	shaping.attach(new Button{Point{0,0},0,0,"Circle",cb_draw_circle});
	shaping.attach(new Button{Point{0,0},0,0,"Triangle",cb_draw_triangle});
	shaping.attach(new Button{Point{0,0},0,0,"Octangle",cb_draw_oct});
	
	attach(shaping);
	attach(move_shape);
	attach(xspawn);
	attach(yspawn);
	attach(xmove);
	attach(ymove);
	attach(button_quit);
	
}
int main () try {

Shaping_window sw{Point{20,20},800,600,"Kansas"};

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