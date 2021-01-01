#include <std_lib_facilities.h>
/*
Антонюк Игорь
08-09 декабря 2016 год
Этой простой программой я пытался построить класс, который из полученных координат строил квадрат
более или менее у меня это получилось, что потребовало:
1. Создать тип, принмающий парные значения - координаты;
2. Создать тип, который бы выстраивал нужную фигуру;
*/
class xy { //тип, принимающий координаты
	public:
	int x =0;
	int y =0;
};
class frame 
{
public:
void framing (int x, int y); //построение фигуры
xy get (); //получение координат
};
xy frame::get() //определение
{
xy b; 
cout << "Insert x and y\n";
cin >> b.x >> b.y; //вводим размер
//cout << b.x  << ' '<< b.y << '\n';
return b; //возвращаем переменную b типа xy
}
void frame::framing (int x, int y) //строим квадрат
{
string ibig;
frame b;
xy q = b.get(); //принимаем размер из cin
cout << "x - " << q.x << ' ' <<  " y - " << q.y << '\n' ; //проверяем его
cout << " "; //просто пробел
for (int i=0; i<=q.x;++i) //рисуем верхний икс
{
	cout << "-";
	if (i==q.x) cout << '\n';
	ibig+= " ";
}

for (int i=0; i<=q.y;++i) //рисуем края
{
	cout << "|" << ibig << "|" << '\n';
}
cout << " ";
for (int i=0; i<=q.x;++i) //рисуем нижний икс
{
	cout << "-";
	if (i==q.x) cout << '\n';
}
}
int main ()
{
frame b;
b.framing(0,0);
'\n';
keep_window_open();
}
