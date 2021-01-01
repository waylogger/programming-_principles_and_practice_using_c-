/*
В принципе проблем при написании указанной программы не было, из ошибок возникли только синтаксические и были устаранены.
Можно так же отметить как проблему, запуск программы без функции win.wait_for_button(), что вызвало преждевременное закрытие окна.
Так же я допустил ошибку когда указал модификатор "const" у функции move(int x,int y), следовало сначала убедиться в отсутствии указанного модификатора у
функции базового класса. Помогло обнаружить пробоему использование модификатора "override"

*/


#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>


class Immobile_circle : public Circle
{
	public:
	using Circle::Circle;
	void move(int x,int y) override { error ("Immobile_circle can't move");}
};

int main () try {

Simple_window win {Point{10,10},1000,800,"Kansas"};
Immobile_circle ic {Point {500,500},150};
ic.set_color (Color::red);

ic.set_style(Line_style(Line_style::solid,3));
ic.move(100,100);
win.attach(ic);

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