#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>


struct Lines_window : Window
{
	Lines_window (Point xy, int w, int h, const string& title);
	
	static void cb_red(Address, Address pw) 
	{reference_to<Lines_window>(pw).red_pressed();}
	static void cb_blue(Address, Address pw)
	{reference_to<Lines_window>(pw).blue_pressed();}
	static void cb_black(Address, Address pw)
	{reference_to<Lines_window>(pw).black_pressed();}
	static void cb_menu(Address, Address pw)
	{reference_to<Lines_window>(pw).menu_pressed();}
	
	
	static void cb_style(Address, Address pw)
	{reference_to<Lines_window>(pw).style_pressed();}
	
	static void cb_dash(Address, Address pw)
	{reference_to<Lines_window>(pw).dash_pressed();}
	static void cb_solid(Address, Address pw) 
	{reference_to<Lines_window>(pw).solid_pressed();} 
	static void cb_dot(Address, Address pw) 
	{reference_to<Lines_window>(pw).dot_pressed();}
	static void cb_dashdot(Address, Address pw) 
	{reference_to<Lines_window>(pw).dashdot_pressed();}
	static void cb_dashdotdot(Address, Address pw) 
	{reference_to<Lines_window>(pw).dashdotdot_pressed();}
	
	
	void change (Color c) {lines.set_color(c);}
	void change_style (Line_style ls) {lines.set_style(ls);}
	
	void red_pressed() {change(Color::red); redraw(); hide_menu();}
	void blue_pressed() {change(Color::blue); redraw(); hide_menu();}
	void black_pressed() {change(Color::black); redraw(); hide_menu();}
	void menu_pressed() {menu_button.hide(); style_menu_button.hide(); color_menu.show();}
	void style_pressed() {style_menu_button.hide(); menu_button.hide(); style_menu.show();}
	
	void dash_pressed()	{change_style(Line_style::dash); redraw(); hide_style_menu();}
	void solid_pressed(){change_style(Line_style::solid); redraw(); hide_style_menu();}
	void dot_pressed()	{change_style(Line_style::dot); redraw(); hide_style_menu();}
	void dashdot_pressed()	{change_style(Line_style::dashdot); redraw(); hide_style_menu();}
	void dashdotdot_pressed()	{change_style(Line_style::dashdotdot); redraw(); hide_style_menu();}
	
	void hide_menu () {color_menu.hide(); style_menu_button.show(); menu_button.show(); } 
	void hide_style_menu() {style_menu.hide(); style_menu_button.show(); menu_button.show();}
	
	
	
	
	private:
	Open_polyline lines;
	
	Button next_button;
	Button quit_button;
	In_box next_x;
	In_box next_y;
	Out_box xy_out;
	Menu color_menu;
	Menu style_menu;
	Button menu_button;
	Button style_menu_button;
	
	void next();
	void quit();
};

Lines_window::Lines_window (Point xy, int w, int h, const string& title)
: 	Window{xy,w,h,title}, 
	next_button{Point{x_max()-150,0},70,20,"Next_point", 
					[] (Address,Address pw) {reference_to<Lines_window>(pw).next();}},
	quit_button{Point{x_max()-70,0},70,20,"Quit_point", 
					[] (Address,Address pw) {reference_to<Lines_window>(pw).quit();}},
	next_x{Point{x_max()-310,0},50,20,"next x:"},
	next_y{Point{x_max()-210,0},50,20,"next y:"},
	xy_out{Point{100,0},100,20,"current(x,y)"},
	color_menu{Point{x_max()-70,40},70,20,Menu::vertical, "color"},
	menu_button{Point{x_max()-80,30},80,20,"color menu", cb_menu},
	style_menu{Point{x_max()-70,60},70,20,Menu::vertical, "style"},
	style_menu_button{Point{x_max()-80,50},80,20,"style menu", cb_style}
	
{
	attach(next_button);
	attach(quit_button);
	attach(next_x);
	attach(next_y);
	attach(xy_out);
	xy_out.put("no point");
	attach(lines);
	
	color_menu.attach(new Button{Point{0,0},0,0,"red",cb_red});
	color_menu.attach(new Button{Point{0,0},0,0,"blue",cb_blue});
	color_menu.attach(new Button{Point{0,0},0,0,"black",cb_black});
	
	style_menu.attach(new Button{Point{0,0},0,0,"solid",cb_solid});
	style_menu.attach(new Button{Point{0,0},0,0,"dash",cb_dash});
	style_menu.attach(new Button{Point{0,0},0,0,"dot",cb_dot});
	style_menu.attach(new Button{Point{0,0},0,0,"dashdot",cb_dashdot});
	style_menu.attach(new Button{Point{0,0},0,0,"dashdotdot",cb_dashdotdot});
	
	
	attach(color_menu);
	attach(style_menu);
	attach(menu_button);
	attach(style_menu_button);
	
	color_menu.hide();
	style_menu.hide();
	
	;
	
}

void Lines_window::quit()
{
	hide();
}

void Lines_window::next()
{
	int x = next_x.get_int();
	int y = next_y.get_int();
	
	lines.add(Point{x,y});
	lines.set_color(Color::red);
	
	ostringstream ss;
	ss << '(' << x << ',' << y << ')';
	xy_out.put (ss.str());
	redraw();
}

int main () try {

Lines_window win {Point{50,50},800,600,"Kansas"};

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