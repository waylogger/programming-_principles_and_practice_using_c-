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
	
	In_box ib;
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
					}
					
	static void cb_exit(Address, Address pw) {exit(0);}
	static void cb_draw(Address, Address pw) {reference_to<Text_window>(pw).drawing();}
	static void cb_clear(Address, Address pw) {reference_to<Text_window>(pw).clearing();}
	
	void drawing();
	void clearing(){
		for (int i =0 ; i < vr.size(); ++i){
			detach(vr[i]);
		}
		vr.erase();
		redraw();
		
	}
	
	
};


void Text_window::drawing(){
	
	string type = ib.get_string();
	regex reg {R"([A-Za-z]+)"};
	smatch match;
	
	
	if (!regex_search(type,match,reg)){
		cout << "Wrong input\n";
		return;
	}
	
	if (match[0] == "Rectangle"){
		//Rectangle{ { Point: 50:50 } 50 50 }
		type = match.suffix();
		smatch rec_m;
		regex rec_pat{R"(\{ \{ Point: (\d+):(\d+) \} (\d+) (\d+) \})"};
		if (regex_match(type,rec_m,rec_pat)){
			int x = MY::from_string_to<int>(rec_m[1]);
			int y = MY::from_string_to<int>(rec_m[2]);
			Point p {x,y};
			int width = MY::from_string_to<int>(rec_m[3]);
			int height = MY::from_string_to<int>(rec_m[4]);
			
			vr.push_back(new Graph_lib::Rectangle{p,width,height});
			vr[vr.size()-1].set_color(Color::black);
			attach(vr[vr.size()-1]);
			
			redraw();
			
		}
		else
			cout << "Wrong input\n";
		
	}
	
	else if (match[0] == "Circle"){
		cout << match[0] << '\n';
	}
	else if (match[0] == "Ellipse"){
		cout << match[0] << '\n';
	}
	
	else if (match[0] == "Line"){
		//Line{ { Point: 50:50 } { Point: 60:60 } }
		type = match.suffix();
		regex l_pat(R"(\{ \{ Point: (\d+):(\d+) \} \{ Point: (\d+):(\d+) \} \})");
		smatch l_match;
		if (regex_match(type,l_match,l_pat)){
			
			int x1 = MY::from_string_to<int>(l_match[1]);
			int y1 = MY::from_string_to<int>(l_match[2]);
			int x2 = MY::from_string_to<int>(l_match[3]);
			int y2 = MY::from_string_to<int>(l_match[4]);
			
			
			
			vr.push_back(new Line {Point{x1,y1},Point{x2,y2}});
			vr[vr.size()-1].set_color(Color::black);
			attach(vr[vr.size()-1]);
			
			redraw();
			
			
			
			
			
		}
		else
			cout << "Wrong input\n";
		
		
	}
	
	else if (match[0] == "Polygon"){
		cout << match[0] << '\n';
	}
	
	else{
		cout << "unknown type" << '\n';
		return;
	}
		}


int main(){
	Text_window tw;
	
	
	gui_main();
	
	
	}