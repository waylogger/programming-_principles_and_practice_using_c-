#include <Graph.h>
#include <Simple_window.h>
class Rec : public Shape
{
public:
	Rec() {  }
	void draw_lines() const;
};
void Rec::draw_lines() const
{
	int r = 0;	int g = 0;
	int b = 0;	int x = 100;
	int x_corr = 0;	int y_corr = 0;
	int y = 100;
	while (b <= 254)
			{
		fl_color(r, g, b);	fl_rectf(x + x_corr*2 , y+y_corr*2, 100, 100);
		++r;++y;
		if (r == 254) { ++g; r = 0; y = 100; ++x; }
		if (g == 254) { b += 5; g = 0; y = 100; x_corr += 1; y_corr += 1; x = 100; }
			}
					
	}
int main()
{
	Simple_window win{ Point{ 80,80 },1000,800, "Kansas" };
	Rec r;
	win.attach(r);
	win.wait_for_button();
}