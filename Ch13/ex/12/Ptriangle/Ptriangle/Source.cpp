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

	Vector_ref<Graph_lib::Rectangle>vr;
	
	for (int i = 0; i < 16; ++i)
	{
		for (int j = 0; j < 16; ++j)
		{
			
			vr.push_back(new Graph_lib::Rectangle{ Point{i * 40,j * 40},40,40 });
			vr[vr.size() - 1].set_color(Color::invisible);
			vr[vr.size() - 1].set_fill_color(i * 16 + j);
			win.attach(vr[vr.size() - 1]);
		}
	}













	win.wait_for_button();
}