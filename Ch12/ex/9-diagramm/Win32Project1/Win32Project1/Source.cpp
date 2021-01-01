#include <Graph.h>
#include <Simple_window.h>

int main()
{
	Simple_window win{ Point{ 80,80 },1000,800, "Kansas" };

	Axis ax{ Axis::x, Point{ 20,700 }, 800,50, "x axis" };
	ax.set_color(Color::red);
	win.attach(ax);

	Axis ay{ Axis::y, Point{ 20,700 }, 550,50, "y axis" };
	ay.set_color(Color::red);
	win.attach(ay);

/////////////////////////////////////////////////////////////////
	Graph_lib::Rectangle point_h{ Point {100,150},120,40 };
	point_h.set_color(Color::black);
	point_h.set_style(Line_style(Line_style::solid, 4));
	win.attach(point_h);

	Text point_h_text{ Point{100,140},"Point.h:" };
	point_h_text.set_color(Color::black);
	point_h_text.set_font_size(20);
	win.attach(point_h_text);

	Text point_h_text_in{ Point{ 105,175 },"struct Point {...};" };
	point_h_text_in.set_color(Color::black);
	point_h_text_in.set_font_size(12);
	win.attach(point_h_text_in);





	/////////////////////////////////////////////////////////////////
	
	Graph_lib::Rectangle graph_h{ Point{ 100,270 },140,60 };
	graph_h.set_color(Color::black);
	graph_h.set_style(Line_style(Line_style::solid, 4));
	win.attach(graph_h);

	Text graph_h_out{ Point{ 100,260 },"Graph.h:" };
	graph_h_out.set_color(Color::black);
	graph_h_out.set_font_size(20);
	win.attach(graph_h_out);

	Text graph_h_in{ Point{ 105,295 },"Graphic interphase" };
	graph_h_in.set_color(Color::black);
	point_h_text_in.set_font_size(12);
	win.attach(graph_h_in);

	Text graph_h_in2{ Point{ 105,310 },"struct Shape {...};" };
	graph_h_in2.set_color(Color::black);
	graph_h_in2.set_font_size(12);
	win.attach(graph_h_in2);

	/////////////////////////////////////////////////////////////////
	Graph_lib::Rectangle graph_cpp{ Point{ 50,450 },120,40 };
	graph_cpp.set_color(Color::black);
	graph_cpp.set_style(Line_style(Line_style::solid, 4));
	win.attach(graph_cpp);

	Text graph_cpp_out{ Point{ 50,442 },"Graph.cpp:" };
	graph_cpp_out.set_color(Color::black);
	graph_cpp_out.set_font_size(20);
	win.attach(graph_cpp_out);

	Text graph_cpp_in{ Point{ 55,470 },"Graphic code" };
	graph_cpp_in.set_color(Color::black);
	graph_cpp_in.set_font_size(12);
	win.attach(graph_cpp_in);


	/////////////////////////////////////////////////////////////////
	Graph_lib::Rectangle ch_12 { Point{ 100,600 },175,65 };
	ch_12.set_color(Color::black);
	ch_12.set_style(Line_style(Line_style::solid, 4));
	win.attach(ch_12);

	Text ch_12_out{ Point{ 105,593 },"Chapter_12.cpp:" };
	ch_12_out.set_color(Color::black);
	ch_12_out.set_font_size(20);
	win.attach(ch_12_out);

	Text ch_12_in1{ Point{ 105,615 },"#include <Graph.h>" };
	ch_12_in1.set_color(Color::black);
	ch_12_in1.set_font_size(12);
	win.attach(ch_12_in1);

	Text ch_12_in{ Point{ 105,630 },"#include <Sumple_window.h>" };
	ch_12_in.set_color(Color::black);
	ch_12_in.set_font_size(12);
	win.attach(ch_12_in);

	Text ch_12_in2{ Point{ 105,645 },"int main () {...}" };
	ch_12_in2.set_color(Color::black);
	ch_12_in2.set_font_size(12);
	win.attach(ch_12_in2);
	
	/////////////////////////////////////////////////////////////////
	Graph_lib::Rectangle headers{ Point{ 340,90 },120,40 };
	headers.set_color(Color::black);
	headers.set_style(Line_style(Line_style::solid, 4));
	win.attach(headers);

	Text t_headers{ Point{ 342,115 },"FLTK headers" };
	t_headers.set_color(Color::black);
	t_headers.set_font_size(18);
	win.attach(t_headers);
	/////////////////////////////////////////////////////////////////
	Graph_lib::Rectangle window_h{ Point{ 320,300 },140,70 };
	window_h.set_color(Color::black);
	window_h.set_style(Line_style(Line_style::solid, 4));
	win.attach(window_h);


	Text window_h_t_out{ Point{ 322,295 },"Window.h:" };
	window_h_t_out.set_color(Color::black);
	window_h_t_out.set_font_size(20);
	win.attach(window_h_t_out);

	Text window_h_t_in{ Point{ 322,330 },"Interphase window" };
	window_h_t_in.set_color(Color::black);
	window_h_t_in.set_font_size(12);
	win.attach(window_h_t_in);

	Text window_h_t_in2{ Point{ 322,345 },"class Window {...}" };
	window_h_t_in2.set_color(Color::black);
	window_h_t_in2.set_font_size(12);
	win.attach(window_h_t_in2);



	/////////////////////////////////////////////////////////////////
	Graph_lib::Rectangle window_cpp{ Point{ 200,400 },140,40 };
	window_cpp.set_color(Color::black);
	window_cpp.set_style(Line_style(Line_style::solid, 4));
	win.attach(window_cpp);

	Text window_cpp_t_out{ Point{ 202,395 },"Window.cpp:" };
	window_cpp_t_out.set_color(Color::black);
	window_cpp_t_out.set_font_size(20);
	win.attach(window_cpp_t_out);

	Text window_cpp_t_in{ Point{ 222,420 },"Window code" };
	window_cpp_t_in.set_color(Color::black);
	window_cpp_t_in.set_font_size(12);
	win.attach(window_cpp_t_in);

	/////////////////////////////////////////////////////////////////
	Graph_lib::Rectangle simple_window_h{ Point{ 215,500 },140,60 };
	simple_window_h.set_color(Color::black);
	simple_window_h.set_style(Line_style(Line_style::solid, 4));
	win.attach(simple_window_h);


	Text simple_window_h_t_out{ Point{ 217,495 },"Simple_window.h:" };
	simple_window_h_t_out.set_color(Color::black);
	simple_window_h_t_out.set_font_size(16);
	win.attach(simple_window_h_t_out);

	Text simple_window_h_t_in{ Point{ 217,520 },"Window interphase" };
	simple_window_h_t_in.set_color(Color::black);
	simple_window_h_t_in.set_font_size(12);
	win.attach(simple_window_h_t_in);

	Text simple_window_h_t_in1{ Point{ 217,535 },"class Simple_window {...}" };
	simple_window_h_t_in1.set_color(Color::black);
	simple_window_h_t_in1.set_font_size(12);
	win.attach(simple_window_h_t_in1);


	/////////////////////////////////////////////////////////////////
	Graph_lib::Rectangle code_fltk{ Point{ 510,150 },140,40 };
	code_fltk.set_color(Color::black);
	code_fltk.set_style(Line_style(Line_style::solid, 4));
	win.attach(code_fltk);

	Text code_fltk_t{ Point{ 535,173 },"FLTK code" };
	code_fltk_t.set_color(Color::black);
	code_fltk_t.set_font_size(20);
	win.attach(code_fltk_t);

	/////////////////////////////////////////////////////////////////
	Graph_lib::Rectangle gui_h { Point{ 480,350 },140,60 };
	gui_h.set_color(Color::black);
	gui_h.set_style(Line_style(Line_style::solid, 4));
	win.attach(gui_h);

	Text gui_h_t_out{ Point{ 482,345 },"GUI.h:" };
	gui_h_t_out.set_color(Color::black);
	gui_h_t_out.set_font_size(18);
	win.attach(gui_h_t_out);

	Text gui_h_t_in1{ Point{ 482,370 },"GUI interphase" };
	gui_h_t_in1.set_color(Color::black);
	gui_h_t_in1.set_font_size(14);
	win.attach(gui_h_t_in1);

	Text gui_h_t_in2{ Point{ 482,385 },"struct In_box{...};" };
	gui_h_t_in2.set_color(Color::black);
	gui_h_t_in2.set_font_size(14);
	win.attach(gui_h_t_in2);


	/////////////////////////////////////////////////////////////////

	Graph_lib::Rectangle gui_cpp{ Point{ 500,450 },90,40 };
	gui_cpp.set_color(Color::black);
	gui_cpp.set_style(Line_style(Line_style::solid, 4));
	win.attach(gui_cpp);

	Text gui_cpp_t_out{ Point{ 502,445 },"GUI.cpp:" };
	gui_cpp_t_out.set_color(Color::black);
	gui_cpp_t_out.set_font_size(18);
	win.attach(gui_cpp_t_out);


	Text gui_cpp_t_in{ Point{ 502,475 },"GUI code" };
	gui_cpp_t_in.set_color(Color::black);
	gui_cpp_t_in.set_font_size(16);
	win.attach(gui_cpp_t_in);

	/////////////////////////////lines////////////////////////////////////
	
	Line l1{ Point{ 160,190 },Point{ 160,270 } };
	l1.set_color(Color::black);
	l1.set_style(Line_style(Line_style::solid, 3));
	win.attach(l1);

	Line l2{ Point{ 160,270 },Point{ 400,130 } };
	l2.set_color(Color::black);
	l2.set_style(Line_style(Line_style::solid, 3));
	win.attach(l2);

	Line l3{ Point{ 390,300 },Point{ 160,190 } };
	l3.set_color(Color::black);
	l3.set_style(Line_style(Line_style::solid, 3));
	win.attach(l3);

	Line l4{ Point{ 390,300 },Point{ 400,130 } };
	l4.set_color(Color::black);
	l4.set_style(Line_style(Line_style::solid, 3));
	win.attach(l4);

	Line l5{ Point{ 510,170 },Point{ 460,110 } };
	l5.set_color(Color::black);
	l5.set_style(Line_style(Line_style::solid, 3));
	win.attach(l5);

	Line l6{ Point{ 550,350 },Point{ 400,130 } };
	l6.set_color(Color::black);
	l6.set_style(Line_style(Line_style::solid, 3));
	win.attach(l6);

	Line l7{ Point{ 550,350 },Point{ 460,330 } };
	l7.set_color(Color::black);
	l7.set_style(Line_style(Line_style::solid, 3));
	win.attach(l7);

	Line l8{ Point{ 270,400 },Point{ 355,370 } };
	l8.set_color(Color::black);
	l8.set_style(Line_style(Line_style::solid, 3));
	win.attach(l8);

	Line l9{ Point{ 285,500 },Point{ 390,370 } };
	l9.set_color(Color::black);
	l9.set_style(Line_style(Line_style::solid, 3));
	win.attach(l9);

	Line l10{ Point{ 285,500 },Point{ 550,410 } };
	l10.set_color(Color::black);
	l10.set_style(Line_style(Line_style::solid, 3));
	win.attach(l10);

	Line l11{ Point{ 560,450 },Point{ 550,410 } };
	l11.set_color(Color::black);
	l11.set_style(Line_style(Line_style::solid, 3));
	win.attach(l11);

	Line l12{ Point{ 110,450 },Point{ 170,330 } };
	l12.set_color(Color::black);
	l12.set_style(Line_style(Line_style::solid, 3));
	win.attach(l12);

	Line l13{ Point{ 190,600 },Point{ 230,560 } };
	l13.set_color(Color::black);
	l13.set_style(Line_style(Line_style::solid, 3));
	win.attach(l13);

	Line l14{ Point{ 190,600 },Point{ 170,330 } };
	l14.set_color(Color::black);
	l14.set_style(Line_style(Line_style::solid, 3));
	win.attach(l14);





	win.wait_for_button();
}