/*#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>
*/
/*
Программа создающая контейнер класса Shape

Возникли сложности при работе с указателями и при расскраске шахматной доски - не сразу было понятно когда обращать цвет
функция r_size () помогла решить эту проблему.

Была предпринята попытка заполнить доску шашками, и это было сделано.






*/
const int chess_board_line = 8;
 
void inv (bool& c) 									//просто переворачиваем переменную типа bool
{
	if (c==true) 	{c=false;return;}
	if (c==false) 	{c=true;return;}
}

bool r_size(const int& q) 							//определяем лежит ли указатель на крайней справа клетке
{
	vector<int>rs;
	for (int i = chess_board_line-1; i <= pow(chess_board_line,2); i+=chess_board_line) 	//заполняем вектор номерами всех крайний клеткок
	{
		rs.push_back(i);
	}
	for (int i = 0; i < rs.size();++i)
		if(rs[i]==q) return false;					//если есть хоть одно совпадение, то переворачивать цвет не нужно.
	return true;
}

class Group
{
	public:
	Group () {}
	void add (Shape* s) {vr.push_back(s);}
	Shape& number (const int& i) {return vr[i];} 	//извлечение элемента из группы
	int size() {return vr.size();}					//добавление элемента в группу
	private:
	Vector_ref<Shape>vr;
};



class Chess_board : public Group
{
	
	public:
	Chess_board(Point s, int cs);
	private:
	Point start;
	int cell_size;
}; 

Chess_board::Chess_board(Point s, int cs) :  start (s),  cell_size(cs)
{
	bool c = true;
	for (int i = 0; i < chess_board_line; ++i) //добавляем клетки, рисующие доску
		for (int j = 0; j <chess_board_line;++j)
		{
			add(new Graph_lib::Rectangle{Point{start.x+(j*cell_size),start.y+(i*cell_size)},cell_size,cell_size});
		}
	for (int i = 0; i < size(); i += 1)
		{
		if (c==true) 	number(i).set_fill_color(Color::white);
		if (c==false)	number(i).set_fill_color(Color::black);
		if (r_size(i)) inv(c); 															//переворачиваем цвета только если номер клетки не является крайней справа
		number(i).set_color(Color::black);
		}
}

/*int main () try {
Simple_window win (Point{20,20},1000,1000,"Kansas");

Chess_board cb {Point{50,50},100};

Circle c {Point{100,100},40};
c.set_fill_color(Color::black);
c.move(100,100);


for (int i =0; i < cb.size();++i) win.attach(cb.number(i));
win.attach(c);

win.wait_for_button();



}
catch (exception& e){
	cerr << e.what() << '\n';
	keep_window_open();
}
catch (...){
	cerr << "Unknown error" << '\n';
	keep_window_open();
}*/