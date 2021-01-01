#include <std_lib_facilities.h>
#include <Graph.h>
#include <Simple_window.h>
#include <C:\\Users\\wLr\\Documents\\Visual Studio 2015\\Projects\\13\\ex\\1-2\\Arc-Box\\Arc\\Arrow.cpp>
#include <C:\\Users\\wLr\\Documents\\Visual Studio 2015\\Projects\\13\\ex\\1-2\\Arc-Box\\Arc\\Box.cpp>
#include <C:\\Users\\wLr\\Documents\\Visual Studio 2015\\Projects\\13\\ex\\1-2\\Arc-Box\\Arc\\Connecting.cpp>
#include <C:\\Users\\wLr\\Documents\\Visual Studio 2015\\Projects\\13\\ex\\1-2\\Arc-Box\\Arc\\Arct.cpp>




int main()
try
{
	Simple_window win{ Point{200,200},1000,800,"Kansas" };
	
	
	Box wi { Point{200,100},10,100,30,"Window" };
	wi.set_color(Color::red);
	Box ls{ Point{ 400,100 },10,100,30,"Line_style" };
	ls.set_color(Color::red);
	Box c{ Point{ 600,100 },10,100,30,"Color" };
	c.set_color(Color::red);
	Box sw{ Point{ 200,200 },10,100,30,"Simple_window" };
	sw.set_color(Color::red);
	Box sp{ Point{ 450,200 },10,100,30,"Shape" };
	sp.set_color(Color::red);
	Box pt{ Point{ 600,200 },10,100,30,"Point" };
	pt.set_color(Color::red);
	Box line { Point{ 200,400 },10,50,30,"Line" };
	line.set_color(Color::red);
	Box lines{ Point{ 300,400 },10,50,30,"Lines" };
	lines.set_color(Color::red);
	Box poly { Point{ 450,400 },10,100,30,"Polygon" };
	poly.set_color(Color::red);
	Box ax{ Point{ 550,400 },10,50,30,"Axis" };
	ax.set_color(Color::red);
	Box rec{ Point{ 680,400 },10,100,30,"Rectangle" };
	rec.set_color(Color::red);
	Box tx{ Point{ 800,400 },10,50,30,"Text" };
	tx.set_color(Color::red);
	Box im{ Point{ 880,400 },10,50,30,"Image" };
	im.set_color(Color::red);
	

	win.attach(wi);			win.attach(ls);		win.attach(c);		win.attach(sw);
	win.attach(sp);			win.attach(pt);		win.attach(line);	win.attach(lines);
	win.attach(poly);		win.attach(ax);		win.attach(rec);	win.attach(tx);
	win.attach(im);

	Arrow a;
	a.add(n(sw), s(wi));
	a.add(n(line), w(sp));
	a.add(n(lines), w(sp));
	a.add(n(poly), s(sp));
	a.add(n(ax), s(sp));
	a.add(n(rec), e(sp));
	a.add(n(tx), e(sp));
	a.add(n(im), e(sp));
	win.attach(a);
	a.set_color(Color::blue);

	
	win.wait_for_button();

		
}
catch (exception& e)
{
	cerr << e.what() << '\\n';
	keep_window_open();
}
catch (runtime_error& e)
{
	cerr << e.what() << '\\n';
	keep_window_open();
}

catch (...)
{
	cerr << "Unknown error\\n";
	keep_window_open(); 
}