#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

#include <FLTK\\Window.h>
#include <FLTK\\Graph.h>
#include <FLTK\\GUI.h>

#define Vector vector

struct Token{
	char kind;
	unsigned int val;
	std::string key;
	
	Token(const char k) : kind{k}, val{0}, key("") {}
	Token(const unsigned int v) : val{v}, kind{'8'}, key{""} {}
	Token(const std::string& k) : key{k}, kind{'w'}, val{0} {}
	
	
};
class Token_stream{
	std::istream& ist;
	public:
	enum alpha_perm {yes,no};
	Token_stream(std::istream& i) : ist{i} {}
	
	Token get(alpha_perm);
	void clear_buffer(){
		ist.ignore(ist.rdbuf()->in_avail());
	}
	
	bool eof() const {return ist.eof();}
};
Token Token_stream::get(Token_stream::alpha_perm a_permiss){
	char c = 0;
	ist.get(c);
	if (ist.eof())
		return Token{'0'};
	
	switch(c){
		case '0': case '1': case '2':
		case '3': case '4': case '5':
		case '6': case '7': case '8':
		case '9': {
			ist.putback(c);
			unsigned int val = 0;
			ist >> val;
				return Token{val};
		}
		case '{': case '}': case '(':
		case ')': case ',': case '\n':
			return Token{c};
		case '-':{ //встроенный интерпритатор
			ist.putback(c);
			std::string s;
			while (true){
				ist.get(c);
				if (c == '\n' || c == ' ' || c == '\t') break;
					s += c;
			}
				return Token{s};
		}
		default:
			if (std::isalpha(c)){  
				switch (a_permiss){ //проверка разрешения на ввод имён
					case alpha_perm::yes:{ //ввод имён разрешен
						ist.putback(c);
						std::string s;
							while (true) {
								ist.get(c); 
								if (c == ')' || c == '(' || c == ',' || c == '\n') break;
									s += c;
								}
								ist.putback(c);
						return Token{s};
					}
					case alpha_perm::no: //ввод имён не разрешен
					std::cout << "Alpha is not permissed\n";
					clear_buffer();
					break;	
				}
			}
			else {
				std::string s;
				while (c != '\n')
				{ist.get(c); s += c;}
			
				std::cout << s << '-' << "Unknown charaster\n";
				clear_buffer();
			}
	}
	return Token{'0'};
}
struct Lang_name{
	std::string name;
	unsigned int birth_day;
	std::vector<std::string> prec;
	public:
	std::string get_name() const {return name;}
	unsigned int get_year() const {return birth_day;}
	
	std::vector<std::string> get_prec() const {return prec;}
	
	enum quality {bad};
	Lang_name(const std::string& s, unsigned int bd, const std::vector<std::string>& p) :
			name {s}, birth_day{bd}, prec{p} {}
			
	Lang_name(quality q){
		switch(q){
			case bad:
				name = "bad_name";
				birth_day = 1;
				return;
		}
	}
	bool operator == (Lang_name ln) {return (name == ln.name)&&(birth_day == ln.birth_day);}
	bool operator != (Lang_name ln) {return !(*this == ln);}
	
};
class Lang_name_stream{
	Token_stream ts ;
	Lang_name wrong_input(Token_stream& ts, const std::string& s);
	Lang_name wrong_input(Token_stream& ts, const char s);
	Lang_name expression();
	
	public:
	Lang_name_stream(std::istream& ist) : ts{ist} {}
	
	std::vector<Lang_name> read();
	
};
Lang_name Lang_name_stream::wrong_input(Token_stream& ts, const std::string& s){
	//ts.clear_buffer();
	std::cout << "Expected - '" + s + "'" << '\n';
	return Lang_name{Lang_name::quality::bad};
	
}
Lang_name Lang_name_stream::wrong_input(Token_stream& ts, const char s){
	//ts.clear_buffer();
	std::cout << "Expected - '" << s << "'" << '\n';
	return Lang_name{Lang_name::quality::bad};
	
}
Lang_name Lang_name_stream::expression(){
	std::string name;
	unsigned int year = 0;
	std::vector<std::string>anc;
	
	Token t = ts.get(Token_stream::alpha_perm::no);
		if (t.kind != '{')
				return wrong_input(ts,'{');
			
	//-----------------------------------------------------		
	t = ts.get(Token_stream::alpha_perm::yes);
		if (t.kind != 'w')
				return wrong_input(ts,"name");
					else   
						name = t.key;
	//-----------------------------------------------------
	t = ts.get(Token_stream::alpha_perm::no);
		if (t.kind != '(')
				return wrong_input(ts,'(');	
	//-----------------------------------------------------	
	t = ts.get(Token_stream::alpha_perm::yes);
		if (t.kind != 'w' && t.kind != ')')
			return wrong_input(ts,"')' or name");
		//-----------------------------------------------------	
		else if (t.kind == 'w'){
			while (t.kind != ')'){
				anc.push_back(t.key);
					t = ts.get(Token_stream::alpha_perm::no);
					
						if (t.kind == ',') {
								t = ts.get(Token_stream::alpha_perm::yes);
								if (t.kind != 'w') 
									return wrong_input(ts,"name");	
						}
						else if (t.kind != ')')
								return wrong_input(ts,')');	
				}
			}

	//-----------------------------------------------------
	t = ts.get(Token_stream::alpha_perm::no);
		if (t.kind != '8')
				return wrong_input(ts,"number");
					else year = t.val;
	//-----------------------------------------------------				
	t = ts.get(Token_stream::alpha_perm::no);
		if (t.kind != '}')
				return wrong_input(ts,'}');
	//-----------------------------------------------------		
	
	return Lang_name{name,year,anc};
}
std::vector<Lang_name> Lang_name_stream::read(){
	std::vector<Lang_name> vln;
	
	while (!ts.eof()){
			
		Lang_name ln = expression();
			if (ln == Lang_name{Lang_name::quality::bad}) break;
		
		ts.get(Token_stream::alpha_perm::no); //newline
		vln.push_back(ln);
	}
	return vln;
}

struct Includes{
	int x1 = 0;
	int x2 = 0;
	
	Includes(int i, int ii) : x1{i}, x2{ii} {}
};

struct Lang_window : Graph_lib::Window{
	Graph_lib::Axis* ax_x = nullptr;
	Graph_lib::Axis* ax_y = nullptr;
	std::vector<Lang_name> data;
	Graph_lib::Vector_ref<Graph_lib::Text> dates;
	Graph_lib::Vector_ref<Graph_lib::Text> objects;
	Graph_lib::Vector_ref<Graph_lib::Line> lns;
	
	Lang_window() : 
	Graph_lib::Window{Graph_lib::Point{200,100},1024,768,"History of programming language"}, 
	ax_x{new Graph_lib::Axis{Graph_lib::Axis::x,Graph_lib::Point{70,700},900,65/5}},
	ax_y{new Graph_lib::Axis{Graph_lib::Axis::y,Graph_lib::Point{70,700},650,65/5}}
	{
		
	ax_x->set_color(Graph_lib::Color::black);
	attach(*ax_x);
	ax_y->set_color(Graph_lib::Color::black);
	attach(*ax_y);
	
	std::ifstream ifs {"D:\\data\\4.txt"};
	Lang_name_stream lns {ifs};
	
	data = lns.read();
	std::sort(data.begin(),data.end(),
		[](Lang_name a, Lang_name b) {return a.birth_day < b.birth_day;});
	
	place_date();
	place_obj();
	std::vector<Includes> is = calc_includes();
	make_line(is);
	
	for (int i =0; i < objects.size(); ++i){
	objects[i].set_color(Graph_lib::Color::blue);
	objects[i].set_font_size(20);
	
		attach(objects[i]);
}
	
	
	}
	
	
	void place_date();
	void place_obj();
	std::vector<Includes> calc_includes();
	void make_line(const std::vector<Includes>&); 
	
};



void Lang_window::place_date(){
	
	std::vector<int> vi;
	
	for (int i = 1945; i <= 2010; i += 5)
		vi.push_back(i);
	
	int step = 50;
	int x = 25;
	int y = 700;
	
	for (auto e : vi)
	{
		std::ostringstream ost;
		ost << e;
		dates.push_back(new Graph_lib::Text{Graph_lib::Point{x,y},ost.str()});
		y = y - 50;
	}
	
	for (int i =0; i < dates.size(); ++i){
		dates[i].set_color(Graph_lib::Color::dark_red);
		attach(dates[i]);
	}
		
	
}
void Lang_window::place_obj(){

	
	int mod_y = 0;
	int mod_x = 0;
	int x = 100;
	int y = 700;
	
	for (int i =0; i < data.size(); ++i)
	{
		std::ostringstream ost;
		ost << data[i].birth_day;
		mod_y = (data[i].birth_day-1945)*10;
		
		objects.push_back(new 
		Graph_lib::Text{Graph_lib::Point{x+rand()%540,y-mod_y},data[i].name + " - " + ost.str()});
	
	}
	
	for (int i =0, j = 1; j < objects.size(); ++i,++j){
		if (std::abs(objects[i].point(0).x - objects[j].point(0).x) < 100) {
			objects[i].move(450,0);
		}
	}
	

	for (int i =0; i < objects.size(); ++i){
			
		
		if (objects[i].label() == std::string("C++ - 1985"))
			objects[i].move(150,0);
		if (objects[i].label() == std::string("ISWIM - 1966"))
			objects[i].move(-150,0);
		if (objects[i].label() == std::string("Lisp - 1958"))
			objects[i].move(-40,0);
		if (objects[i].label() == std::string("B - 1969"))
			objects[i].move(30,0);
		if (objects[i].label() == std::string("C - 1972"))
			objects[i].move(230,0);
		if (objects[i].label() == std::string("BASIC - 1964"))
			objects[i].move(130,0);
		if (objects[i].label() == std::string("CPL - 1963"))
			objects[i].move(80,0);
		if (objects[i].label() == std::string("Perl - 1987"))
			objects[i].move(170,0);
		if (objects[i].label() == std::string("Haskell - 1990"))
			objects[i].move(-150	,0);
		if (objects[i].label() == std::string("Visual Basic - 1998"))
			objects[i].move(-100,0);
		if (objects[i].label() == std::string("SQL - 1986"))
			objects[i].move(300,0);
	}
	
	
	
}

std::vector<Includes> Lang_window::calc_includes(){
	std::vector<Includes> inc;
	
	for (int i =0; i < data.size(); ++i)
	{
		for (int j =i+1; j < data.size(); ++j)
		{
			for (int k = 0; k < data[j].prec.size();++k)
			{
				if (data[i].name == data[j].prec[k]) {inc.push_back(Includes{i,j});}
			}
		}
	}
	
	
	return inc;
}

void Lang_window::make_line(const std::vector<Includes>& inc){
	
	Graph_lib::Point x1;
	Graph_lib::Point x2;
	
	for (int i =0; i < inc.size(); ++i)
	{
		x1 = Graph_lib::Point{objects[inc[i].x1].point(0).x,objects[inc[i].x1].point(0).y};
		x2 = Graph_lib::Point{objects[inc[i].x2].point(0).x,objects[inc[i].x2].point(0).y};
		

		lns.push_back(new Graph_lib::Line{x1,x2});
	}
	
	
	for (int i =0; i < lns.size(); ++i){
		lns[i].set_color(Graph_lib::Color::red);
		lns[i].set_style(Graph_lib::Line_style{Graph_lib::Line_style::Line_style_type::solid,1});
		attach(lns[i]);
	}

	
	
	
	
	
	
}



int main ()
{
	
	
	Lang_window lw{};
	
	Graph_lib::gui_main();
	
	
	
}