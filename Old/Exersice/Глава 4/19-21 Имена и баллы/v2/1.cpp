// »мена и баллы
/*
Вторая версия программы должна отвечать тем же требованиям, но её реализация должна быть следующей.

1. Приём из потока имени и счета;
2. Помещение их в вектор
3. Вывод по запросу.

1. Создаем класс Имя_Счет
2. Создаем Вектор типа <Имя_Счет>
3. Создаем фунцию анализа ввода;
4. Создаем фунцию проверки и помещения в вектор значений;
5. Создаем функцию вывода по запросу
*/

#include <std_lib_facilities.h>
const char print = '='; // символическая константа выхода из ошибки
class namesandscore { //класс лексемм
	public:
	string names; //имена
	int score; //очки
	namesandscore(string n, int s) : names(n), score(s) { } //конструируем лексему
};
class streams { //считывание и игнорирование
	public:
	namesandscore get (); // считываем данные из потока
	void ignoring(char c); //игнорируем символы
};
class tables { //вектор и операции с ним
	public:
	vector<namesandscore>NS;
	void push(string a, int b); //внесение в вектор
	void back(); //вывод из вектора
};
streams ts;
tables tl;
void continuerun () { //функция восстановления после ошибки
	ts.ignoring(print);
}
void tables::push (string a, int b) try { //внесение в вектор
	
	setlocale(0, "");
	for (int i = 0; i<NS.size(); ++i) {
	if (NS[i].names==a) error ("Повторное имя");} //А не повторились ли мы?
	NS.push_back(namesandscore(a,b));
	
}
catch (exception& e) {
	cerr << e.what() << endl;
	continuerun ();
	}
void tables::back () { //вывод из вектора
	for (int i = 0; i<NS.size(); ++i) 
		cout << NS[i].names << " - " << NS[i].score << "\n";
	return;
};
void streams::ignoring (char c) { //игнорирование
	char ch;
	while (cin >> ch)
	if (ch == c) return;
}
namesandscore streams::get () { //считывание из потока ввода
	
	setlocale(0, "Russian");
		string names;
		int score;
	while (cin && names!="noname" && score!=0) { //выход из ввода при noname 0
		cout << "Введите имя и счет\n";
		cin >> names >> score;
		if (names!="noname"&&score!=0) tl.push(names,score);
		cout << tl.NS.size();
		}
	return namesandscore(names, score);
	}
int main () //точка входа
try {
	ts.get();
	tl.back();
	keep_window_open ("~~");
}
catch (exception& e) {
	cerr << e.what() << endl;
	keep_window_open("!");
	}
catch (...) {
	cerr << "Ups...." << '\n';
	keep_window_open("!");
	}