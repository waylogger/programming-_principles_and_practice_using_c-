#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>


/*
Простая программа, позволяющая выводить на рисунок температуру по нескольким городам

Основная сложность - работа с вектором векторов, для меня это было впервые, мне понравилось

Основная слабость программы - несвязанность данных о городе с температурой  и месяцем
из-за того, что эти данные в разных контейнерах
хорошо бы разработать специальный класс, но сейчас не до того
*/


const int xmax = 800; //ширина окна
const int ymax = 600; //высота окна

const Point start_window {40,40}; //начинаем окно

const int typical_field = 100; //обычное поле

//поля
const int up_field = ymax-(ymax-typical_field);
const int right_field = xmax-typical_field;
const int down_field = ymax-typical_field;
const int left_field = typical_field;

//старт графика
const Point start_graphic(left_field,down_field);

const int length_of_graphic = xmax-(typical_field*2);
const int height_of_graphic = ymax-(typical_field*2);
//абзацный отступ
const int parag = 15;


class Temp_of_city : public Shape
{
	vector<vector<string>>data; //данные мы рисуем в виде таблицы
	vector<string> cols;
	vector<string> raws;
	public:
	Temp_of_city(const vector<string>&cities, const vector<string>& month)
					: raws(cities), cols(month) {}
	void to_data(const vector<string>&v) {data.push_back(v);} //добавляем города
	void to_edge(); //заполняем неиспользованные поля
	void draw_lines() const override;
	
};
void Temp_of_city::to_edge()
{
	vector<string> v (12,"-");
while (data.size() < raws.size())
	{
		data.push_back(v);
	}
}
void Temp_of_city::draw_lines() const
{
	fl_color(FL_RED);
	Axis x {Axis::x,start_graphic,length_of_graphic,int(cols.size()),"Month"};
	x.label.move(0,parag);
	x.set_color(Color::red);
	x.draw_lines();
	
	Axis y {Axis::y,start_graphic,height_of_graphic,int(raws.size()),"Cities"};
	y.set_color(Color::red);
	y.draw_lines();
	
	const int xstep = length_of_graphic/cols.size(); //шаг столбца
	const int ystep = height_of_graphic/raws.size(); //шаг строки
	
	Point p {start_graphic.x+(xstep/3),start_graphic.y+parag}; //пишем заголовок стоблца
	
	for (int i = 0; i < cols.size(); ++i)
	{
		fl_draw(cols[i].c_str(),p.x,p.y);
		p.x+=xstep;
	}
	
	p = {start_graphic.x-parag*5,start_graphic.y-(ystep/3)};
	
	for (int i =0; i < raws.size(); ++i) //пишем заголовок строки
	{
		fl_draw(raws[i].c_str(),p.x,p.y);
		p.y-=ystep;
	}
	
	Point print {start_graphic.x+(xstep/3),start_graphic.y+(ystep/2)};
	
	for (int i = 0; i < data.size(); ++i) //заполняем данные о температуре
	{
		print.x=start_graphic.x+(xstep/3);
		print.y-=ystep;
		for (int j = 0; j <data[i].size(); ++j)
		{
			fl_draw(data[i][j].c_str(),print.x,print.y);
			print.x+=xstep;
		}
	}
	  
	
	
	
}

int main () try {

Simple_window win {start_window,xmax,ymax,"Kansas"};

const vector<string>month{"jan","feb","mar","apr","may","jun","jul","aug",
					"sep","oct","nov","dec"};
					
const vector<string>cities{"Old Oskol", "Gubkin"};

const vector<string>oo {"-5.2C","-2.9C","2.9C","13.4C","22.2C","24.5C",
						"27.0C","26.5C","18.8C","9.9C","3.5C","2.4C"};
const vector<string>g {"-6.9C","-3.6C","+2.4C","+7.8C","+15.5C","17.9C",
					   "20.4C","19.6C","12.9C","4.1C","-0.6C","-3.6C"};
Temp_of_city tc {cities,month};

tc.to_data(oo);
tc.to_data(g);
tc.to_edge();
win.attach(tc);



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