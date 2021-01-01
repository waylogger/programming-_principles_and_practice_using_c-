#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>

class Smiley : public Circle{
public:
using Circle::Circle;
void draw_lines() const override;
//Smiley (Point p, int r) : center(p), rad(r) {}
};
void Smiley::draw_lines() const {
	Point l_eye {center().x-radius()/2,center().y-radius()/3}; //центр левого глаза
	Point r_eye {center().x+radius()/2,center().y-radius()/3}; //центр правого глаза
	Point mouth {center().x-radius()/2,center().y+radius()/3}; //центр рта
	fl_color(FL_RED);
	fl_circle(center().x,center().y,radius()); 					//рисуем голову
	fl_arc(l_eye.x,l_eye.y,30,15,0,360);						//рисуем левый глаз
	fl_arc(r_eye.x,r_eye.y,30,15,0,360);						//рисуем правы глаз
	fl_arc(mouth.x,mouth.y,radius(),50,180,360);				//рисуем рот
}
class Frowny : public Circle{
public:
using Circle::Circle;
void draw_lines() const override;
};
void Frowny::draw_lines() const {

	Point l_eye {center().x-radius()/2,center().y-radius()/3}; //центр левого глаза
	Point r_eye {center().x+radius()/2,center().y-radius()/3}; //центр правого глаза
	Point mouth {center().x-radius()/2,center().y+radius()/3}; //центр рта
	fl_color(FL_RED);
	fl_circle(center().x,center().y,radius()); 					//рисуем голову
	fl_arc(l_eye.x,l_eye.y,30,15,0,360);						//рисуем левый глаз
	fl_arc(r_eye.x,r_eye.y,30,15,0,360);						//рисуем правы глаз
	fl_arc(mouth.x,mouth.y,radius(),50,0,180);					//рисуем рот
}

class Smiley_with_hat : public Smiley{
	using Smiley::Smiley;
	void draw_lines() const override;	
};

void Smiley_with_hat::draw_lines() const{
Smiley::draw_lines();
fl_arc(center().x-radius(),center().y-radius(),radius()*2,20,0,360);
}


class Frowny_with_hat : public Frowny{
	using Frowny::Frowny;
	void draw_lines() const override;	
};

void Frowny_with_hat::draw_lines() const{
Frowny::draw_lines();
fl_arc(center().x-radius(),center().y-radius(),radius()*2,20,0,360);
}

int main () try {
Simple_window win {Point{100,100},1000,800,"Kansas"};


Smiley_with_hat s {Point {200,350},100};

Frowny_with_hat f {Point {500,350},100};



win.attach(s);
win.attach(f);
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