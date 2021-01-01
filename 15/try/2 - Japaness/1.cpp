#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>

struct Distribution
{
	int year, young, midle, old;
}; 

ifstream& operator>> (ifstream& ist,Distribution& d)
{
	
	char ch1 = 0;
	char ch2 = 0;
	char ch3 = 0;
	Distribution dd;
	if (ist >> ch1 >> dd.year
		>> ch2 >> dd.young >> dd.midle
		>> dd.old >> ch3 )
		{
			if (ch1!='(' || ch2!= ':' || ch3!= ')')
			{
				ist.clear(ios_base::failbit);
				return ist;
			}
		}
		else 
			return ist;
			d=dd;
	return ist;
}

class Reading_distribution
{
	public:
	Reading_distribution (string& s);
	Distribution seem (const int& i) {return vd[i];}
	int size() {return vd.size();}
	private:
	string adress;
	vector<Distribution>vd;
	
};


Reading_distribution::Reading_distribution (string& s) : adress(s)
{
	ifstream r {adress};
	if (!r) error ("Cant open file");
	for (Distribution d; r >> d;)
	{
		if (d.young + d.midle + d.old != 100) error ("Percents are not convincet");
		vd.push_back(d);
		//cout << d.young << '\n' << d.midle << '\n' << d.old << '\n';
	}
		
		
}

class Scale
{
	int cbase;
	int vbase;
	double scale;
	public:
	Scale(int b,int vb, double s) :cbase(b), vbase(vb), scale(s)
	{}
	int operator () (int v) 
	{return cbase+(v-vbase)*scale;}
};



int main () try {


int xmax = 600;
int ymax = 400;

int xoffset = 100;
int yoffset = 60;

int xspace = 40;
int yspace = 40;

int xlength = xmax-xoffset-xspace;
int ylength = ymax-yoffset-yspace;

int base_year = 1960;
int end_year = 2040;
double xscale = double(xlength)/(end_year-base_year);
double yscale = double(ylength)/100;

Scale xs(xoffset,base_year,xscale);
Scale ys(ymax-yoffset,0,-yscale);

Graph_lib::Window win {Point{100,100},xmax,ymax,"Aging Japan"};

Axis x {Axis::x, Point{xoffset,ymax-yoffset},xlength,(end_year-base_year)/10,
"year 1960     1970        1980        1990        "
"2000     2010      2020      2030      2040"};

x.label.move(-100,0);


Axis y {Axis::y, Point{xoffset,ymax-yoffset}, ylength,10, "% of population"};

Line current_year {Point{xs(2016),ys(0)},Point{xs(2016),ys(100)}};


current_year.set_style(Line_style::dash);
current_year.set_color(Color::red);

x.set_color(Color::red);
y.set_color(Color::red);

Open_polyline children;
Open_polyline adults;
Open_polyline aged;

string s = "D:\\Programms\\15\\try\\2 - Japaness\\data\\1..txt";

Reading_distribution rd {s};

for (int i =0; i < rd.size();++i)
{
Distribution d = rd.seem(i);
const int xx = xs{d.year};
children.add(Point{xx,ys(d.young)});
adults.add (Point{xx,ys(d.midle)});
aged.add(Point{xx,ys(d.old)});
}

Text children_label {Point{20,children.point(0).y}, "age 0-14"};
children.set_color(Color::red);
children_label.set_color(Color::red);

Text adults_label {Point{20,adults.point(0).y}, "age 15-64"};
adults.set_color(Color::blue);
adults_label.set_color(Color::blue);

Text aged_label {Point{20,aged.point(0).y}, "age 65+"};
aged.set_color(Color::dark_green);
aged_label.set_color(Color::dark_green);

win.attach(children);
win.attach(adults);
win.attach(aged);

win.attach(children_label);
win.attach(adults_label);
win.attach(aged_label);

win.attach(x);
win.attach(y);
win.attach(x);
win.attach(y);
win.attach(current_year);

gui_main();










}
catch (exception& e){
	cerr << e.what() << '\n';
	keep_window_open();
}
catch (...){
	keep_window_open();
	cerr << "Unknown error" << '\n';
}
	