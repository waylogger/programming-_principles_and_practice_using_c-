#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>
#include <random>

/*
Программа состоит из:
1. Окно
2. Одна кнопка;
3. Изображение на кнопке

При нажатии на кнопку кнопка и изображение синхронно смещаются по координатам
определенным генератором случайных чисел
*/


inline int rand_int(int min, int max) //генератор случайных чисел
{	
	static default_random_engine ran;
	return uniform_int_distribution<>(min,max)(ran);
}

struct Rand_window : Window
{
	Rand_window(Point p, int w, int h, const string& s);
	static void cb_move(Address,Address pw) {reference_to<Rand_window>(pw).move();}
	void move ();
	private:
	Button im;
	Image m;
};
Rand_window::Rand_window(Point p, int w, int h, const string& s)
:
Window{p,w,h,s},
im{Point{w/2,h/2},100,100,"Move image", cb_move},
m{Point{w/2,h/2},"D:\\Programms\\16\\ex\\3 - rand\\1.jpg"}
	{
		m.set_mask(Point{w/2,h/2},100,100);
		attach(im);
		attach(m);
	}
	
void Rand_window::move ()
{
	int x =rand_int(-25,25);
	int y =rand_int(-25,25);
	m.move(x,y);
	im.move(x,y);
}
int main () try {
	
Rand_window rw{Point{20,20},800,600,"Kansas"};

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