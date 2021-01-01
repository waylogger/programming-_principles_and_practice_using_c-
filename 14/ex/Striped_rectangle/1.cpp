/*
Совершено пара аналитических ошибок. Я начал рассуждать о решении задачи, решая в том числе следующее, сходное с этим задание.
Решил запустить программу без заполненной функции main;
Решил запустить программу бу функции win.wait_for_button();

*/


#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>

class Striped_rectangle : public Rectangle {
public:
using Rectangle::Rectangle;
void draw_lines() const;
};

void Striped_rectangle::draw_lines() const
{
	Graph_lib::Rectangle::draw_lines();
	
	for (int i =1; i < height(); i+=4)
	{
		fl_color(FL_RED);
		fl_line(point(0).x,point(0).y+i,point(0).x+width(),point(0).y+i);
	}
}


int main () try {

Simple_window win {Point{10,10},1000,800,"Kansas"};
Striped_rectangle sr {Point{400,300},400,200};
sr.set_color(Color::red);
win.attach(sr);
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