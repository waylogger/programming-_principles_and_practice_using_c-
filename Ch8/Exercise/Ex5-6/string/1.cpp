/*
//Название программы: переворачивалка
//Цель программы: Реализовать обработку отдельных элементов вектора
//Автор: Антонюк И.В.
//Дата начала написания: 05.12.2016
//Дата окончания написания:06.12.2016
//Номер версии: 1.0
//Фрагменты кода, которые могут вызвать проблемы: функция свопа векторов
//Основные идеи проекта: перемешать значения вектора и расположить их в обратном порядке, используя там где возможно ссылки
//Способ организации кода: функция main класс rec и ряд полезных функций
//Предположения о вводных данных: string

*/
#include <std_lib_facilities.h>
void comunication () { //Программа должна общаться!

cout << "Insert any word, and proggram swop it, twice!!!!\n";
}
char come () {//Вводим обработку всех символов, чтобы видеть и пробелы и знак перевода на новую строку
char c = ' ';
while (true) {
cin.get(c); 
return c;
}

}
void recurs (const vector<string>& v1, vector<string>v2) { //свопим в новый вектор
	string a = "";
	for (int i = 1; i<=v1.size();++i) {
	a = v1[v1.size()-i];
	v2.push_back(a); //переносим содержимое первого вектора во второй начиная с конца
	}
	for (int i = 0; i<v2.size();++i) // и выводим его
		cout << v2[i];
		cout << '\n';
	

}	
void true_recurs (vector<string>& v1) { //свопим сам вектор: представим вектор в виде ленты и двух кареток
	int i =0;							//начальная позиция кареток по краям вектора, суть в том, что элементы на которые встают каретки меняются местами
	while (i<v1.size()/2) {	 //перемещаем каретку к центру
		
	string a =v1[0+i]; // каретка 1
	string b =v1[v1.size()-1-i]; // каретка 2
	 
	swap(a,b); //меняем значения местами
	v1[0+i]=a; //присваиваем их
	v1[v1.size()-1-i]=b;
	++i;
	
	}
	for (int i = 0; i<v1.size();++i) //выводим на печать
		cout << v1[i];
		cout << '\n';
}
class rec { //а чтобы на дороге не валялись
	public:
vector<string>v1; //основна
vector<string>v2; 
void pushing (); //вносим значения в вектор
 
};
void rec::pushing () { //вносим значения в вектор
	char ch = ' ';
	string c = " ";
	while (ch!='\n') {
	ch = come();
	if (ch=='\n') return;
	else c =+ ch; //посимвольная конкатенация
	rec::v1.push_back(c);
	}
	
	
}
int main ()
try{ //что-то обрабатываем

rec V;
comunication ();
while (true) {
V.pushing ();
recurs(V.v1,V.v2);
true_recurs(V.v1);
V.v1.clear (); // чистим вектор
}
keep_window_open("~");
}
catch (exception& e) {
	cerr << e.what() << '\n';
	keep_window_open();
}
