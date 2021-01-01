
namespace Time 
{


const int as = 6; //угол перемещения секундной стрелки
const int am = 6;//угол перемещения минутной стрелки
const int ah = 15;//угол перемещения чесовой стрелки

class Time //базовый класс хранящий время и прибавляющий секунду
{
	private:
	int sec = 0;
	int min = 0;
	int hour = 0;
	public:
	Time () {}
	Time (int h, int m, int s) : sec(s), min(m), hour (h) {}
	void show_time(int& s, int& m, int& h) {s=sec; m = min; h=hour;}
	int show_sec() const {return sec;}
	int show_min() const {return min;}
	int show_hour() const {return hour;}
	void set_sec (const int& i) {if (i<60) sec=i;}
	void set_min (const int& i) {if (i<60) min=i;}
	void set_hour (const int& i) {hour=i;}
	void to_def() {sec = 0; min = 0; hour = 0;}
	void go(); //прибавляем секунду
};



void Time::go()
{

	if (sec<60) ++sec;
	if (sec>=60) {++min; sec =0;}
	if (min>=60) {++hour; min=0;}
	if (hour>23) {hour=0;}
	
	//cout << hour << ':' << min << ':' << sec << '\n';
}

Time curr_time() //системное время
{
time_t a;
time(&a);
struct tm* info;
info = localtime(&a);
int sec = info->tm_sec;
int min = info->tm_min;
int hour = info->tm_hour;
return Time{hour,min,sec};
}


struct Dial : Shape //Программируем циферблат
{
	Dial(Point p, double r);
	void draw_lines() const;
	void set_color(Color c);
	void move(int dx, int dy);
	private:
	Point start;
	Point dest;
	double radius;
	Vector_ref<Text>vrt;
	Color c{0};
};

Dial::Dial(Point p, double r) :
start(p),
dest{Point{p.x,int(p.y-r)}},
radius(r)
{
	Point d = dest;
	
	int a = 12;
	
	for (int i = 30; i <= 360; i+=30) //циферблат состоит из 12 расположенных по кругу цифр
	{
		string s;
		ostringstream ost {s};
		ost << a;
		vrt.push_back(new Text{Point{d.x-10,d.y},ost.str()});
		d = turn(start,dest,i); //задаем вращение
		if (a>=12) a =0;
		++a;
	}
	
}

void Dial::draw_lines() const
{
	for (int i =0; i < vrt.size(); ++i)
	{
		fl_color(c.as_int());
		vrt[i].draw_lines();
	}
		
}

void Dial::set_color(Color cc)
{
	c=cc;
}

void Dial::move(int dx, int dy)
{
	for (int i =0; i < vrt.size(); ++i)
	{
		vrt[i].move(dx,dy);
	}
}

struct Arrows : Shape //рисуем блядские стрелочки
{
	Arrows(Point p, double r);
	void draw_lines () const;
	void set_time (const int& h,const int& m, const int& s);
	void set_color(Color cc) {c=cc;}
	private:
	Color c{0};
	Point start;
	Point dest;
	double radius;
	vector<Point>p;
	
};

Arrows::Arrows(Point p,double r)
: 
start (p),
dest(Point{p.x,int(p.y-r*0.9)}),
radius(r)
{
set_time(0,0,0);
}

void Arrows::set_time (const int& h,const int& m, const int& s)
{
	p.erase(p.begin(),p.end());
	Point destofhour = Point{dest.x,int(start.y-(radius/2))};
	p.push_back(turn(start,destofhour,h*30));
	p.push_back(turn(start,dest,m*6));
	p.push_back(turn(start,dest,s*6));
	
	
}

void Arrows::draw_lines() const
{
	for (int i =0; i < p.size(); ++i)
	{
	fl_color(c.as_int());
	fl_line_style(FL_SOLID,5);
	fl_line(start.x,start.y,p[i].x,p[i].y);
	}
}

struct Cloak : Shape //объединяем циферблат и блядские стрелочки
{
	Cloak::Cloak(Point p, double r);
	void draw_lines() const;
	void go();
	Time show_time() const {return t;}
	private:
	Point spawn;
	double rad;
	Time t = curr_time();
	Arrows a;
	Dial d;
	
};

Cloak::Cloak(Point p, double r) :
a{p,r},
d{p,r}
{
	
}

void Cloak::draw_lines() const
{
	a.draw_lines();
	d.draw_lines();
}

void Cloak::go()
{
	t.go();
	a.set_time(t.show_hour(),t.show_min(),t.show_sec());
}

struct Watch_window : Window //окно с часами
{
	Watch_window(Point p, int w, int h, const string&s);
	static void cb_go (Address,Address pw) {reference_to<Watch_window>(pw).go();}
	void go ();
	private:
	Cloak c;
	Button button_go;
};
Watch_window::Watch_window(Point p, int w, int h, const string&s)
:
Window{p,w,h,s},
c{Point{200,200},150},
button_go{Point{0,0},50,70,"GO",cb_go}
{
	
	attach(c);
	attach(button_go);
}
void Watch_window::go() //анимация
{
	bool a {false};
	while(true)
	{
	c.go();
	redraw();
	if (a==false)
	{
		Fl::wait(); //контроль - окну
		Sleep(1000); //ждем-с
		a=true; //контроль - системе
	}		
	a=false;
	}
	
}
} //end of Time