#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>

/*
Программа опредлеяющая работу контроллера цвета

сложности были связаны с определением смысла регулирования уровня цвета

ради справедливости - программа фуфло
*/

class Controller  //Обший класс, не абстрактный - возможны обшие контроллеры
{
	public:
	Controller () {}
	virtual void on() {ctrl = true;}
	virtual void off() {ctrl = false;}
	virtual void show();
	virtual void set_level(int);
	private:
	bool ctrl {false};
	int cur_level = 0; //текущий уровень
};

void Controller::show()
{
	if (ctrl == true) cout << "On\n";
	if (ctrl == false) cout << "Off\n";
	cout << "Currect level is - " << cur_level << '\n';
}

void Controller::set_level(int i)
{
	cur_level = cur_level * i;
}

class Status : public Controller //просто показываем статус
{
	public:
	Status (Controller&c) {c.show();}
	
};

class Level : public Controller //регулируем уровень цвета линий
{
	public:
	Level (Shape&s) : sh(s) {};
	void set_level(int i) 
	{sh.set_color(sh.color().as_int()*i);}
	private:
	Shape& sh;
};


class Fill_level : public Controller //регулируем уровень цвета заполнения
{
	public:
	Fill_level (Shape&s) : sh(s) {};
	void set_level(int i) 
	{sh.set_fill_color(sh.color().as_int()+1*i);}
	private:
	Shape& sh;
};


	



int main () try 
{

Simple_window win {Point{20,20},1000,1000,"Kansas"};

Circle c {Point{300,500},100};
c.set_color(Color::red);

Fill_level fl {c};
fl.set_level (125);

win.attach(c);
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