#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>
#include <D:\\Programms\\16\\fun\\nangle.h>

const int to_down = 50;
int std_wb = 70;
int std_hb = 20;

/*
Моя первая попытка написать графический пользовательский интерфейс
получился простенький до убожества графический редактор
Возможности:
Вставить круг, эллипс, прямоугольник, nугольник
Раскрасить и перетащить


*/


struct Drawning_window : Window
{
	Drawning_window(const Point& p, const int& x, const int& y, const string& s);
	enum Direction {up,down,right,left};
	
	
	void quit();
		
	void draw_circle();
	void draw_rect();
	void draw_ellipse();
	void draw_nangle();

	//общие функции перемещение и закраска
	void fill_shape(Color c);
	void move_shape(Direction d);
	
	//низкоуровневый код
	static void cb_draw_circle(Address,Address pw)		{reference_to<Drawning_window>(pw).draw_circle();}
	static void cb_draw_rect(Address,Address pw)		{reference_to<Drawning_window>(pw).draw_rect();}
	static void cb_draw_ellipse(Address,Address pw)		{reference_to<Drawning_window>(pw).draw_ellipse();}
	static void cb_draw_nangle(Address,Address pw)		{reference_to<Drawning_window>(pw).draw_nangle();}
	
	static void cb_fill_red(Address,Address pw)			{reference_to<Drawning_window>(pw).fill_shape(Color::red);}
	static void cb_fill_blue(Address,Address pw)		{reference_to<Drawning_window>(pw).fill_shape(Color::blue);}
	static void cb_fill_green(Address,Address pw)		{reference_to<Drawning_window>(pw).fill_shape(Color::green);}
	static void cb_fill_white(Address,Address pw)		{reference_to<Drawning_window>(pw).fill_shape(Color::white);}
	static void cb_fill_black(Address,Address pw)		{reference_to<Drawning_window>(pw).fill_shape(Color::black);}
	
	static void cb_move_up(Address,Address pw)		{reference_to<Drawning_window>(pw).move_shape(Direction::up);}
	static void cb_move_down(Address,Address pw)	{reference_to<Drawning_window>(pw).move_shape(Direction::down);}
	static void cb_move_right(Address,Address pw)	{reference_to<Drawning_window>(pw).move_shape(Direction::right);}
	static void cb_move_left(Address,Address pw)	{reference_to<Drawning_window>(pw).move_shape(Direction::left);}
	
	
	
	
	private:
	
	Menu chose_shape; 										//выбираем фигуру
	Menu fill_of_shape;										//выбираем цвет
	Menu move_to; 											//перемещения
	Button quit_button; 									//выход
	In_box rad; 											//вводим радиус
	In_box angles; 											//вводим число углов н-угольника
	In_box xofshape; 										//ширина
	In_box yofshape; 										//высота
	Vector_ref<Shape>sh; 									//вектор фигур
	void attaching (Vector_ref<Shape>&sh); 					//передаем все фигуры окну
	Point start; 											//точка спауна
 
	
};

void Drawning_window::attaching (Vector_ref<Shape>&sh)
{
	for (int i = 0; i < sh.size(); ++i)
	{
		attach(sh[i]);
	}
}
void Drawning_window::quit()
{
	hide();
}

void Drawning_window::draw_circle()
{
	int r = rad.get_int();
	sh.push_back(new Circle {start,r});
	attaching(sh);
	redraw();
}

void Drawning_window::draw_rect()
{
	int h = yofshape.get_int();
	int w = xofshape.get_int(); 
	sh.push_back(new Graph_lib::Rectangle {Point{start.x-w/2,start.y-h/2},w,h});
	attaching(sh);
	redraw();
}

void Drawning_window::draw_ellipse()
{
	int h = yofshape.get_int();
	int w = xofshape.get_int(); 
	sh.push_back(new Graph_lib::Ellipse {Point{start.x,start.y},w,h});
	attaching(sh);
	redraw();
}

void Drawning_window::draw_nangle()
{
	sh.push_back(new Nangle{start,double(rad.get_int()),angles.get_int()});
	attaching(sh);
	redraw();
}




void Drawning_window::fill_shape(Color c)
{
	sh[sh.size()-1].set_fill_color(c);
	sh[sh.size()-1].set_color(c);
	redraw();
}

void Drawning_window::move_shape(Direction d)
{
	switch (d)
	{
	case up:
	sh[sh.size()-1].move(0,-10);
	redraw();
	break;
	case down:
	sh[sh.size()-1].move(0,10);
	redraw();
	break;
	case left:
	sh[sh.size()-1].move(-10,0);
	redraw();
	break;
	case right:
	sh[sh.size()-1].move(10,0);
	redraw();
	break;
	}
	
}

Drawning_window::Drawning_window (const Point& p, const int& x, const int& y, const string& s) :
Window{p,x,y,s},

chose_shape{Point{0,std_hb*2},std_wb,std_hb,Menu::vertical,"Shaping"},

fill_of_shape{Point{x-std_wb,std_hb*2},std_wb,std_hb,Menu::vertical,"Color"},

move_to{Point{x/2,y-std_hb*5},std_wb,std_hb,Menu::vertical,"Move"},

quit_button{Point{0,0},std_wb,std_hb,"Quit",
					[] (Address,Address pw) {reference_to<Drawning_window>(pw).quit();}},
xofshape{Point{std_wb,std_hb*8},std_wb,std_hb,"Width"},
yofshape{Point{std_wb,std_hb*9},std_wb,std_hb,"Hidth"},
rad{Point{std_wb,std_hb*10},std_wb,std_hb,"Radius"},
angles{Point{std_wb,std_hb*11},std_wb,std_hb,"Angles"},
start(Point{x/2,y/2})
{
	

	chose_shape.attach(new Button{Point{0,0},std_wb,std_hb,"Circle",cb_draw_circle});
	chose_shape.attach(new Button{Point{0,0},std_wb,std_hb,"Ellipse",cb_draw_ellipse});
	chose_shape.attach(new Button{Point{0,0},std_wb,std_hb,"Rect",cb_draw_rect});
	chose_shape.attach(new Button{Point{0,0},std_wb,std_hb,"Nangles",cb_draw_nangle});
	
	fill_of_shape.attach(new Button{Point{0,0},std_wb,std_hb,"Red",cb_fill_red});
	fill_of_shape.attach(new Button{Point{0,0},std_wb,std_hb,"Blue",cb_fill_blue});
	fill_of_shape.attach(new Button{Point{0,0},std_wb,std_hb,"Green",cb_fill_green});
	fill_of_shape.attach(new Button{Point{0,0},std_wb,std_hb,"Black",cb_fill_black});
	fill_of_shape.attach(new Button{Point{0,0},std_wb,std_hb,"White",cb_fill_white});
	
	move_to.attach(new Button{Point{0,0},std_wb,std_hb,"Up",cb_move_up});
	move_to.attach(new Button{Point{0,0},std_wb,std_hb,"Down",cb_move_down});
	move_to.attach(new Button{Point{0,0},std_wb,std_hb,"Left",cb_move_left});
	move_to.attach(new Button{Point{0,0},std_wb,std_hb,"Right",cb_move_right});
	
	
	
	attach(chose_shape);
	attach(fill_of_shape);
	attach(quit_button);
	attach(move_to);
	attach(xofshape);
	attach(yofshape);
	attach(rad);
	attach(angles);
	attaching(sh);
		
}


int main () try {
	
Drawning_window dw(Point{50,50},800,600,"Kansas");
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