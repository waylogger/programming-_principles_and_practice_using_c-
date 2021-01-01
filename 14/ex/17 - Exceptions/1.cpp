#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>
#include <D:\\Programms\\14\\ex\\17 - Exceptions\\Group.cpp>
#include <D:\\Programms\\14\\ex\\17 - Exceptions\\Box.cpp>

/*
на самом деле очень простая программа, предназначенная для закрепления понимания наследования
и взаимодействия, а главное взаимодополнения классов предка и наследника

сложности тут и возникли, когда возникла необходимость выполнения других вычислений при конструировании объекта
класса Text_box, чем те, которые выполняются при конструировании объекта класса Box

было решено использовать механизм наследования и не дублировать класс предок, а изменить класс таким образом, чтобы производить
необходимые вычисления по ходу работы класса
*/



class Text_box : public Box 										//коробка заполненная текстом
{
	public:
	Box::Box; 														//используем конструктор предка
	void add (const string& s); 									//полезная функция добавляющая текст построчно
	void draw_lines() const override;
	private:
	Vector_ref<Text>vrt; 											//хранилише текста
	Point xy {Point{point(0).x,point(0).y+(standart_radius*3)}}; 	//текущее положение ползунка для размещения внутреннего текста

};

void Text_box::add(const string& s) 
{
	vrt.push_back(new Text{Point{xy.x,xy.y},s});					// добавляем текст и 
	xy = Point{xy.x,xy.y+(standart_radius*2)}; 						//перемещаем ползунок вниз
}



void Text_box::draw_lines() const
{
	Box::draw_lines();
	for (int i =0; i < vrt.size(); ++i) 							//печатаем текст
	{
		int x = vrt[i].point(0).x;									//увеличиваем, но делаем понятнее код
		int y = vrt[i].point(0).y;
		string s = vrt[i].label();
		fl_draw(s.c_str(),x,y);
	}
	
}

class Group_print : public Group 									//класс предназначен для передачи в окно всех объектов включенных в группу
{
	public:
	Group_print(Simple_window& win, Group& g);
	private:
	Simple_window& w;
	Group& gr;
};

Group_print::Group_print(Simple_window& win, Group& g) : w(win), gr(g) //всю полезную работу выполняет конструктор
{
	for (int i = 0; i < gr.size(); ++i)
	{
		w.attach(gr.number(i));
	}
}

class Group_color : public Group 										//раскрашиваем линии всей группы в один цвет
{
	public:
	Group_color(Group& g, Color c);
	private:
	Group& gr;
	Color cl;
};

Group_color::Group_color(Group& g, Color c) : gr(g), cl(c)
{
	for (int i = 0; i < gr.size(); ++i)
	{
		gr.number(i).set_color(cl);
	}
}


int main () try {

Simple_window win {Point{20,20},1000,1000,"Kansas"};
Group g;
Text_box exc	 {Point{300,150},200,100,"Exceptions"};
Text_box le 	 {Point{150,350},150,200,"Logic_error"};
Text_box re 	 {Point{400,350},150,200,"Runtime_error"};
Text_box rest	 {Point{650,350},150,200,"Other_error"};

exc.add("logic_error"); exc.add("runtime_error"); exc.add("others_error");
le.add("invalid_argument"); le.add("domain_error"); le.add("length_error"); le.add("out_of_rang"); le.add("future_error");
re.add("renge_error"); re.add("overflow_error"); re.add("underflow_error"); re.add("system_error"); re.add("|____ios_base_failture");
rest.add("bad_cast"); rest.add("bat_type_id"); rest.add("bad_weak"); rest.add("bad_function_call"); rest.add("bad_alloc"); 
rest.add("|____bad_array_new_length"); rest.add("bad_exceptions"); rest.add("ios_base_failture");
g.add(exc);
g.add(le);
g.add(re);
g.add(rest);
Group_color(g,Color::red);
Group_print(win,g);


win.wait_for_button();

}
catch (exception& e){
	cerr << e.what() << '\n';
	keep_window_open();
}
catch (...){
	cerr << "Unknown error" << '\n';
	keep_window_open();
}