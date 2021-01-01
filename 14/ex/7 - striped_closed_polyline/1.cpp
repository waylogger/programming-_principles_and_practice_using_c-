#include <std_lib_facilities.h>
#include <Graph.h>
#include <Simple_window.h>
/*
Поставленная задача - создать класс - заштрихованной любой фигуры
Мной было выработано 2 решения.
Первое заключалось в вычислении координат каждой точки, принадлежащей линии и соединении равных по y
Второе заключалось в использовании координатной решетки для вычисления координат начала и окончания штриха, и соедения их попарно
ближайших по х с равными у

Второе решение было проще, так как вычислить всю совокупность точек, по которым проходят линии конечно можно,
 но крайше сложно обеспечить нужный шаг, в следствие чего координаты разнились по у и штрих получался не ровным
 
 Во второй версии программы я столкнулся с проблемой сортировки точек в контейнере всех пересечений точек фигуры с
 координатной решеткой.
 Сначала был выбран путь: соотносим 1 линию с решеткой, но из-за возникших сложностей с полседующим упорядочиванием
 окончательного списка было решено сделать следующее.
 Взять одну линию решетки и вычислить все точки пересечения со всеми линиями фигуры.
 Таким образом, мы получили разрозненный список точек, который необходимо было так же отсортировать.
 В результате сортировки точки были упорядочены по координате х и попарно образовали линии штриха.
 
 Так же можно было изменить порядок следования вершин, но это показалось менее естественным для штрихования цельных фигур.
 
 нерешенная проблема: если шаг сетки 5, то точки пересечения определяются с погрешностью равной 5, что очень сильно портит штрих

*/
vector<Point> grid(const int& s, const int& rlim,  const int& dlim)  //Горизонтальная сетка, аргументы:													
{	
	vector <Point>v;												//1. Шаг сетки - расстояние между линиями
	for (int i = 0; i < dlim;i+=s)									//2. Правый предел, 
																	//3. Нижний предел;
	{
		v.push_back(Point{0,i});
		v.push_back(Point{rlim,i});
	}
	return v;
}
Point p_of_int (const Point& p1, const Point& p2, const Point& p3, const Point& p4){
	int x1 = p1.x; 	int x2 = p2.x;
	int x3 = p3.x;	int x4 = p4.x;
	int y1 = p1.y;	int y2 = p2.y;
	int y3 = p3.y;	int y4 = p4.y;
	int x =0;		int y =0;
	double denom = ((y4 - y3)*(x2-x1) - (x4-x3)*(y2-y1));
	if (denom==0) return Point{0,0};
		pair<double,double>	u	
							(((x4-x3)*(y1-y3) - (y4-y3)*(x1-x3))/denom,
							((x2-x1)*(y1-y3) - (y2-y1)*(x1-x3))/denom);
	if (u.first < 0 || u.first > 1 || u.second < 0 || u.second > 1) return Point{0,0}; //определяем пересекаются ли точки вообще
	
	x = x1 + u.first*(x2 - x1); 														//вычисляем координату х
	y = y1 + u.first*(y2 - y1); 														//вычисляем координату у
	return Point{x,y};
}

vector<Point>allintersect(const vector<Point>& grid, const vector<Point>&vertexs) 		//вычисляем все пересечения всех вершин с каждой линией разметки
{
	vector<Point>alli;
	Point p;
	for (int i =0, j =1; i < grid.size() && j < grid.size();i+=2,j+=2)					//выбираем линию разметки
	{
		
		for (int i2=0, j2=1;  j2 < vertexs.size(); i2+=1, j2+=1) 						//сравниваем её с каждой линией
		{
			
			p = p_of_int(vertexs[i2],vertexs[j2],grid[i],grid[j]); 						//определяем точку пересечения, если она есть
																						//если она есть, то вносим её в вектор	
			if (p.x != 0 && p.y !=0)
			{
				alli.push_back(p);
			}								
		}
	}
	return alli;
}
void swap_points(Point& p1, Point& p2) 									//меняем местами левую и правую координаты
{
	Point buffer;
	
		buffer = p1;
		p1=p2;
		p2=buffer;	
	
}
bool is_sort_of_x (const vector<Point>& ps) 							//проверяем сортирован ли вектор по координате х
{
	bool sort {true};
	
	for (int i = 0, j = 1; j < ps.size(); ++i,++j)
	{
		 if (ps[i].y == ps[j].y && ps[i].x > ps [j].x) return false; 	//если хоть одна левая координата х больше правой, то вектор не сортирован
	}
	return sort;
}
void sort_of_x (vector<Point>& ps)
{
	while (!is_sort_of_x(ps))
	{
	for (int i = 0, j = 1; j<ps.size(); ++i, ++j)
		if (ps[i].y==ps[j].y &&ps[i].x>ps[j].x) swap_points(ps[i],ps[j]);
	}
}
class Striped_closed_polyline : public Closed_polyline
{
	Closed_polyline::Closed_polyline;
	void draw_lines() const override;
};
void Striped_closed_polyline::draw_lines() const
{
	Closed_polyline::draw_lines();
	vector<Point>g = grid(6,1500,1500);
	vector<Point>vertexs;
	vector<Point>s;
	for (int i = 0; i < number_of_points();++i)
	{
		vertexs.push_back(point(i));
	}
	vertexs.push_back(point(0));
	s = allintersect(g,vertexs);
	sort_of_x(s);
	fl_color(FL_BLUE);
	for (int i = 0, j = 1; j < s.size(); i+=2, j+=2)
	{
		fl_line(s[i].x,s[i].y,s[j].x,s[j].y);
	}
	
}
int main ()
{

	
	Simple_window win {Point{10,10},1000,1000,"Kansas"};
	Striped_closed_polyline sct;
	sct.add(Point{500,500});
	sct.add(Point{700,250});
	sct.add(Point{900,500});
	sct.add(Point{700,300});
	sct.set_color(Color::red);
	win.attach(sct);
	
	win.wait_for_button();

	
}




















