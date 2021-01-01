#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <FLTK\\Window.h>
#include <FLTK\\Graph.h>
#include <algorithm>
#include <D:\\Programms\\22\\15 - name pair\\history_guard.h>
#include <D:\\Programms\\22\\15 - name pair\\Language_stream.h>



using Graph_lib::Window;
using Graph_lib::Point;
using Graph_lib::gui_main;
using Graph_lib::Axis;
using Graph_lib::Color;
using Graph_lib::Vector_ref;
using Graph_lib::Text;



namespace lang_history {

const Point	begin_of_system = Point{50,700};

struct Prog_lang_Window : Graph_lib::Window{
	vector<name_pair> collect_of_names;
	Vector_ref<Text> represent_of_names;
	Axis* axis_x = nullptr;
	Axis* axis_y = nullptr;
	Prog_lang_Window(Point p);
	
	Text* str_to_shape(const Point& p, const name_pair& s);
	void paint_history();
};

Prog_lang_Window::Prog_lang_Window(Point p) : 
Window {p,1024,768,"History of programming languages"},
axis_x(new Axis{Axis::x,begin_of_system,800,800/10,"years"}),
axis_y(new Axis{Axis::y,begin_of_system,600,600/10,"just"})
{
		size_range(1024,768,1024,768);
		
		ifstream ifs{"D:\\data\\1.txt"};
		Language_stream{ifs}.read(Language_stream::file,collect_of_names);
		std::sort(collect_of_names.begin(),collect_of_names.end(),
					[](name_pair b, name_pair e){return b.second() < e.second();});
			
		
		
		axis_x->set_color(Color::black);
		attach(*axis_x);
		axis_y->set_color(Color::black);
		attach(*axis_y);
		
		paint_history();
		for (int i =0; i < represent_of_names.size(); ++i){
		attach(represent_of_names[i]);
		}
} 

Text* Prog_lang_Window::str_to_shape(const Point& p, const name_pair& s){
	std::ostringstream ost;
	ost << s;
	return new Text{p,ost.str()};
}

void Prog_lang_Window::paint_history(){
	int x_step = begin_of_system.x;
	int y_step = begin_of_system.y;
	for (int i =0; i < collect_of_names.size();++i) {
		x_step = x_step + 40;
		y_step = y_step - 20;
		represent_of_names.push_back(str_to_shape(Point{x_step,y_step},collect_of_names[i]));
	}
	
	for (int i =0; i < represent_of_names.size(); ++i)
		represent_of_names[i].set_color(Color::black);
	
}


} // end of namespace

int main()
{

	lang_history::Prog_lang_Window qwe (Point{100,100});
	
	gui_main();
	
	
}