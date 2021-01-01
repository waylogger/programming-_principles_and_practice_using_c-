#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>

/*
Простая программа - 16 кнопок при нажатии меняется цвет кнопки

*/

struct My_window : Simple_window
{
	My_window(Point p, int w, int h, const string& s);
	 

	static void cb_quit_button(Address,Address pw) {reference_to<My_window>(pw).quit();}
	static void cb_work_0 (Address,Address pw) {reference_to<My_window>(pw).work(0);}
	static void cb_work_1 (Address,Address pw) {reference_to<My_window>(pw).work(1);}
	static void cb_work_2 (Address,Address pw) {reference_to<My_window>(pw).work(2);}
	static void cb_work_3 (Address,Address pw) {reference_to<My_window>(pw).work(3);}
	static void cb_work_4 (Address,Address pw) {reference_to<My_window>(pw).work(4);}
	static void cb_work_5 (Address,Address pw) {reference_to<My_window>(pw).work(5);}
	static void cb_work_6 (Address,Address pw) {reference_to<My_window>(pw).work(6);}
	static void cb_work_7 (Address,Address pw) {reference_to<My_window>(pw).work(7);}
	static void cb_work_8 (Address,Address pw) {reference_to<My_window>(pw).work(8);}
	static void cb_work_9 (Address,Address pw) {reference_to<My_window>(pw).work(9);}
	static void cb_work_10 (Address,Address pw) {reference_to<My_window>(pw).work(10);}
	static void cb_work_11 (Address,Address pw) {reference_to<My_window>(pw).work(11);}
	static void cb_work_12 (Address,Address pw) {reference_to<My_window>(pw).work(12);}
	static void cb_work_13 (Address,Address pw) {reference_to<My_window>(pw).work(13);}
	static void cb_work_14 (Address,Address pw) {reference_to<My_window>(pw).work(14);}
	static void cb_work_15 (Address,Address pw) {reference_to<My_window>(pw).work(15);}
	private:
	void quit() {hide();} 				//выход
	void work(const int& i); 			//работа
	Vector_ref<Shape>mosaic; 			//контейнер всех изображений
	vector<Color>cols; 					//все цвета
	void flow_col(); 					//заполняем вектор цветов
	int last_col = 0; 					//индекс последнего использованного цвета
	void attaching(); 					//передаем все фигуры окну
	void drawing (); 					//вычисляем фигуры
 	Button qb;
	Menu first;
	Menu second;
	Menu third;
	Menu fourth;
};
void My_window::flow_col()
{
	cols.push_back(Color::red);
	cols.push_back(Color::dark_red);
	cols.push_back(Color::blue);
	cols.push_back(Color::dark_blue);
	cols.push_back(Color::green);
	cols.push_back(Color::dark_green);
	cols.push_back(Color::yellow);
}
void My_window::work(const int& i)
{
	mosaic[i].set_fill_color(cols[last_col]);
	++last_col;
	if (last_col>cols.size()-1) last_col =0;
	
}

void My_window::attaching() 
{
	for (int i =0; i < mosaic.size();++i) 
	{
		attach(mosaic[i]);
	}
}

void My_window::drawing()
{
	int x = 100;
	int y = 100;
	for (int i =1; i <= 4;++i)
	{
		x+=100;
		y=100;
		for (int j =1; j <= 4;++j)
		{
		mosaic.push_back(new Graph_lib::Rectangle{Point{x,y},100,100});
		y+=100;
		
		}
	}
}

My_window::My_window(Point p, int w, int h, const string& s)
: Simple_window{p,w,h,s}, 
qb{Point{w-70,20},70,20,"Quit", cb_quit_button},
first{Point{200,100},100,100,Menu::vertical,"One"},
second{Point{300,100},100,100,Menu::vertical,"Two"},
third{Point{400,100},100,100,Menu::vertical,"thirth"},
fourth{Point{500,100},100,100,Menu::vertical,"fourth"}

	{
		flow_col();
		drawing();
		attaching();
		first.attach(new Button{Point{0,0},0,0,"1",cb_work_0});
		first.attach(new Button{Point{0,0},0,0,"2",cb_work_1});
		first.attach(new Button{Point{0,0},0,0,"3",cb_work_2});
		first.attach(new Button{Point{0,0},0,0,"4",cb_work_3});
		
		second.attach(new Button{Point{0,0},0,0,"5",cb_work_4});
		second.attach(new Button{Point{0,0},0,0,"6",cb_work_5});
		second.attach(new Button{Point{0,0},0,0,"7",cb_work_6});
		second.attach(new Button{Point{0,0},0,0,"8",cb_work_7});
		
		third.attach(new Button{Point{0,0},0,0,"9",cb_work_8});
		third.attach(new Button{Point{0,0},0,0,"10",cb_work_9});
		third.attach(new Button{Point{0,0},0,0,"11",cb_work_10});
		third.attach(new Button{Point{0,0},0,0,"12",cb_work_11});
		
		fourth.attach(new Button{Point{0,0},0,0,"13",cb_work_12});
		fourth.attach(new Button{Point{0,0},0,0,"14",cb_work_13});
		fourth.attach(new Button{Point{0,0},0,0,"15",cb_work_14});
		fourth.attach(new Button{Point{0,0},0,0,"16",cb_work_15});
		
		attach(qb);
		attach(first);
		attach(second);
		attach(third);
		attach(fourth);
	}



int main () try {

My_window mw{Point{20,20},800,600,"Kansas"};

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