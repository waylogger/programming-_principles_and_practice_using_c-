#include <std_lib_facilities.h>
#include <Graph.h>
#include <Simple_window.h>

int main()
{
	Simple_window win{ Point{400,200},1000,800,"Kansas" };
	Lines ls;


	for (int i = 0; i < 900; i = i + 100)
	{
		ls.add(Point{ 800,i }, Point{ 0,i });
		ls.add(Point{ i,800 }, Point{ i,0 });
	}

	ls.set_color(Color::red);
	ls.set_style(Line_style(Line_style::solid, 3));
	win.attach(ls);

	Vector_ref<Graph_lib::Rectangle> vrec;
	for (int i = 0; i < 900; i = i + 100)
	{
		vrec.push_back(new Graph_lib::Rectangle{ Point{0 + i,0 + i},100,100 });
	}
	

	for (int i = 0; i < vrec.size(); ++i)
	{
		vrec[i].set_fill_color(Color::red);
		win.attach(vrec[i]);
	}

	Vector_ref<Graph_lib::Image> ims;

	const string adress_images = "C:\\Users\\wLr\\Documents\\Visual Studio 2015\\Projects\\13\\task\\honda.jpg";
	const string adress_images1 = "C:\\Users\\wLr\\Documents\\Visual Studio 2015\\Projects\\13\\task\\renaut.jpg";

	for (int i = 0; i < 800; i = i + 200)
	{
		ims.push_back(new Image{ Point{0 + i,200 + i}, adress_images });
	}

	for (int i = 0; i < ims.size(); ++i)
	{
		ims[i].set_mask(Point{ 150,200 }, 200, 200);
		win.attach(ims[i]);
	}
	
	Image img123 {Point{200,200}, adress_images1};
	img123.set_mask(Point{ 450,200 }, 100, 100);
	win.attach(img123);
	while (true) 
	{ 
		img123.move(100, 0);
		win.wait_for_button(); 
	}
}
