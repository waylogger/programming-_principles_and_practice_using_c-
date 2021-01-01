#include "My\\Text_analys.h"
#include <FLTK\\Graph.h>
#include <FLTK\\Window.h>
#include <FLTK\\GUI.h>
#include <windows.h>
#include <string>
#include <vector>
#include <locale>

using Graph_lib::Window;
using Graph_lib::Button;
using Graph_lib::In_box;
using Graph_lib::Point;
using Graph_lib::Vector_ref;
using Graph_lib::Out_box;
using Graph_lib::Address;
using Graph_lib::reference_to;

using std::cout;
using std::cin;
using std::string;
using std::vector;

using My::Russian_dictionary;


class Text_window : Window{
	
	Vector_ref<Button> vb;
	Vector_ref<In_box> ibv;
	Out_box* text_box = nullptr;
	Russian_dictionary* rd = nullptr;
	public:
	
	void make_dictionary();
	void short_word() 	{text_box->put(rd->short_word());};
	void long_word()	{text_box->put(rd->long_word());};
	void often()		{text_box->put(rd->offen_word());};
	
	
	void count() {string s = ibv[2].get_string(); text_box->put(rd->count_of_words(s));}
	void startof();
	void num();
	
	static void cb_md(Address, Address pw) {reference_to<Text_window>(pw).make_dictionary();}
	static void cb_sh(Address, Address pw) {reference_to<Text_window>(pw).short_word();}
	static void cb_lg(Address, Address pw) {reference_to<Text_window>(pw).long_word();}
	static void cb_ot(Address, Address pw) {reference_to<Text_window>(pw).often();}
	static void cb_cn(Address, Address pw) {reference_to<Text_window>(pw).count();}
	Text_window(const Point& p);
	
};
	
	Text_window::Text_window(const Point& p) : Window{p,200,250,"Text Analyzer"},
	text_box {new Out_box{Point{0,200},200,50,""}} {

		vb.push_back(new Button{Point{0,0},100,50,"Dict",cb_md});
		vb.push_back(new Button{Point{0,50},100,25,"Long",cb_lg});
		vb.push_back(new Button{Point{0,75},100,25,"Short",cb_sh});
		vb.push_back(new Button{Point{0,100},100,25,"Count",cb_cn});
		vb.push_back(new Button{Point{0,125},100,25,"Often",cb_ot});
		vb.push_back(new Button{Point{0,150},100,25,"Num",0});
		vb.push_back(new Button{Point{0,175},100,25,"begin for",0});
		
		
		ibv.push_back(new In_box{Point{100,0},100,25,""});
		ibv.push_back(new In_box{Point{100,25},100,25,""});
		//ibv.push_back(new In_box{Point{100,50},100,25,""});
		//ibv.push_back(new In_box{Point{100,75},100,25,""});
		ibv.push_back(new In_box{Point{100,100},100,25,""});
		//ibv.push_back(new In_box{Point{100,125},100,25,""});
		ibv.push_back(new In_box{Point{100,150},100,25,""});
		ibv.push_back(new In_box{Point{100,175},100,25,""});
		
		
		for (int i =0; i < vb.size(); ++i)
			attach(vb[i]);
		
		for (int i =0; i < ibv.size(); ++i)
			attach(ibv[i]);
		
		attach(*text_box);
	}
	
	
	void Text_window::make_dictionary()
	{
		
		string in, out;
		in = ibv[0].get_string();
		out = ibv[1].get_string();
		if (in.size() == 0 || out.size() ==0) return;
		ifstream ifs {in};
		ofstream ofs {out};
				
		
		rd = new Russian_dictionary{ofs,ifs}; 
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

int main ()
{
	setlocale(0,"");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
	Text_window tw {Point{500,200}};
	
	Graph_lib::gui_main();
	
}