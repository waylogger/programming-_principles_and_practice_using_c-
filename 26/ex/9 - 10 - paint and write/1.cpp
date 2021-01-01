/*
Antonyuk I.V. 
Belgorod

06/05/2018

PPP C++ B.Stroustrup

ex.26.8


*/


#include <		FLTK\\Window.h		>
#include <		FLTK\\Gui.h			>
#include <		FLTK\\Graph.h		>
#include <		regex				>
#include <		MY\\help.h			>

using namespace Graph_lib;


struct Text_window : Graph_lib::Window{
	int last_unit = 0;
	Out_box ib;
	Button exit_b;
	Button drawing_b;
	Button clearing_b;
	Vector_ref<Shape>vr;
	Text_window() : Graph_lib::Window	{Point{500,100},800,600,"Text"		},
					ib					{Point{100,0},600,25,""				},
					exit_b				{Point{700,0},100,25,"exit",cb_exit	},
					drawing_b			{Point{0,0},100,25,"draw",cb_draw	},
					clearing_b			{Point{0,25},100,25,"clear",cb_clear}

					{
						attach(ib);
						attach(exit_b);
						attach(drawing_b);
						attach(clearing_b);
						boil();
					}
					
	static void cb_exit(Address, Address pw) {exit(0);}
	static void cb_draw(Address, Address pw) {reference_to<Text_window>(pw).drawing();}
	static void cb_clear(Address, Address pw) {reference_to<Text_window>(pw).clearing();}
	
	void drawing();
	void clearing(){
		for (int i =0 ; i < vr.size(); ++i){
			detach(vr[i]);
		}
		
		last_unit = 0;
		redraw();
		
	}
	void boil();
	
	
};


void Text_window::drawing(){
	
	if (last_unit >= vr.size()) 
		return;
	attach(vr[last_unit]);
	string to_out;
	
	auto& t = vr[last_unit];
	string tn = typeid(t).name();
	if (( tn == "struct Graph_lib::Circle")){
		
	Circle* tt = dynamic_cast<Circle*>(&t);	
	
	to_out 	+= "Circle{Point{" + MY::to_string_from<int>(tt->center().x) + ":"
			+	MY::to_string_from<int>(tt->center().y) + "} "
			+	MY::to_string_from<int>(tt->radius()) + "} ";
	ib.put(to_out);
	}
	
	else if (( tn == "struct Graph_lib::Rectangle")){
		Graph_lib::Rectangle* tt = dynamic_cast<Graph_lib::Rectangle*>(&t);	
	
			to_out 	+= "Rectangle{Point{" + MY::to_string_from<int>(tt->point(0).x) + ":"
			+	MY::to_string_from<int>(tt->point(0).y) + "} "
			+	MY::to_string_from<int>(tt->width()) + " "
			+ 	MY::to_string_from<int>(tt->height()) + "}";
			ib.put(to_out);
	}
	
	
	redraw();
	++last_unit;
}
		
void Text_window::boil(){
	
	vr.push_back(new Graph_lib::Rectangle(Point{50,100},50,50));
	vr.push_back(new Circle(Point{150,100},50));
	vr.push_back(new Circle(Point{200,200},75));
	vr.push_back(new Circle(Point{450,200},90));
	vr.push_back(new Circle(Point{350,300},50));
	
	
	for (int i =0; i < vr.size(); ++i)
		vr[i].set_color(Color::black);
	
}


int main(){
	Text_window tw;
	
	
	gui_main();
	
	
	}