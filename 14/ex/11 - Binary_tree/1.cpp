/*
Суть программы - нарисовать бинарное дерево, с опционной формой узлов,
опционными направлениями путей и стилем и цветом соединительных линий

основные сложности возникли при расположении узлов с минимальными пересечениями
*/

#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>
#include <D:\\Programms\\14\\ex\\11 - Binary_tree\\arrow.cpp>
const int space = 15;
const int rad = 40;
 enum class Direction
{
	down,up,no
};
pair<Point,Point>legacy(const Point& p, const int& x,const int& y) 		//  создаем пару сыновей из получнной точки, с корректировкой по х и у
{
	pair<Point,Point>a;
	a.first = Point{p.x-x,p.y+y}; 										//указанные корректировки нужны для того, чтобы избежать пересечений узлов
	a.second = Point {p.x+x,p.y+y};
	return a;
}
class Binary_tree : public Shape
{
	public:
	Binary_tree(Point xy, int lev, Color c, Line_style ls, Direction d);
	
	void draw_lines() const;
	virtual void draw_nodes() const;
	
	private:
	Point p;
	int levels;
	Color color_line;
	Line_style lst;
	Direction dir;
	string name;
	vector<string>names;
	void set_names (vector<string>&);
};
void Binary_tree::set_names (vector<string>&names) 								//задаем имена
{
	for (int i =0; i < number_of_points(); ++i)
		names.push_back(" "); 													//заполняем вектор пробелами
	names.push_back("r");
	for (int i =0, j = 1, k = 2; k < number_of_points(); i+=1,j+=2,k+=2) 		//изменяем пробелы под нужное имя
	{
		names[j]=names[i]+"l"; 													//имя всегда равно имени предка плюс направление
		names[k]=names[i]+"r";
	}
	
}
Binary_tree::Binary_tree(Point xy, int lev, Color c, Line_style ls, Direction d) //основные вычисления производит конструктор
	: p(xy), levels(lev), color_line(c), lst(ls), dir(d)
	{
		int x = space; 															//корректировка по х
		int y = space; 															//корректировка по у
		add(p);
		pair<Point,Point>l;
		

		for (int i =0; i < pow(2,levels)-1 ;++i)
		{
		l = legacy(point(i),x+=rad,y+=rad);
		add(l.first);
		add(l.second);
		
		}
		set_names(names);
		
	}	
void Binary_tree::draw_nodes() const
{
for (int i = 0; i < number_of_points(); ++i)
	{
		fl_circle(point(i).x,point(i).y,rad); 									//рисуем круги под глазами
		fl_draw(names[i].c_str(),point(i).x+20,point(i).y); 					//выводим имя узла - путь
	}

}
void Binary_tree::draw_lines() const
{
	draw_nodes(); 																//рисуем узлы в стиле определенном виртуальной функцией
	fl_line_style(lst.style(),lst.width());
	fl_color(color_line.as_int());
	Arrow a;
	if (dir==Direction::down) 													//рисуем стрелки вниз
	{
	for (int i = 0, j =1, k = 2; k < number_of_points(); i+=1,j+=2,k+=2)
	{
		a.add(Point{point(i).x,point(i).y}, Point {point(j).x,point(j).y});
		a.add(Point{point(i).x,point(i).y}, Point {point(k).x,point(k).y});
	}
	}
	if (dir==Direction::up) 													//рисуем стрелки вверх
	{
	for (int i = 0, j =1, k = 2; k < number_of_points(); i+=1,j+=2,k+=2)
	{
		a.add(Point{point(j).x,point(j).y}, Point {point(i).x,point(i).y});
		a.add(Point{point(k).x,point(k).y}, Point {point(i).x,point(i).y});
	}
	}
	
	if (dir==Direction::no) 													//рисуем линии без стрелок
	{
	for (int i = 0, j =1, k = 2; k < number_of_points(); i+=1,j+=2,k+=2) 		//рисуем соединительные линии
	{
		fl_line(point(i).x,point(i).y,point(j).x,point(j).y);
		fl_line(point(i).x,point(i).y,point(k).x,point(k).y);
	}
	}
	a.draw_lines();
}
class Binary_tree_sqrt : public Binary_tree 									//узлы в форме квадратиков
{
	public:
	Binary_tree::Binary_tree;
	void draw_nodes() const;
};
void Binary_tree_sqrt::draw_nodes() const
{
	for (int i = 0; i < number_of_points(); ++i)
	{
		fl_rect(point(i).x-(rad/2),point(i).y,rad,rad); 						//рисуем квадратные узлы под глазами
	}
}
int main () try {
	
Simple_window win {Point{10,10},1000,1000,"Kansas"};

for (int i =0; i < 20; ++i)
{
Binary_tree btq {Point{500,200},i,Color::red,Line_style(Line_style::solid,2),Direction::down};
btq.set_color(Color::red);
win.wait_for_button();
win.attach(btq);
}




}
catch (exception& e){
	cerr << e.what() << '\n';
	keep_window_open();
}
catch (...){
	cerr << "Unknown error" << '\n';
	keep_window_open();
}