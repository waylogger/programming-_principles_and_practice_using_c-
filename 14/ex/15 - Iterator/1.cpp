
#include <std_lib_facilities.h>

/*

внеграфический пример наследования

class Iter обслуживает контейнеры: list and vector и содержит 2 полезных функции:
1. печатаем следующий элемент
2. печатаем все элементы

Главные сложности были с освоением типа указателей и процесса их инициализации.
Кроме того, определенных усилий стоило разобраться с контейнером типа list



*/
class Iter  // класс итератор
{
	public:
	virtual double* next() = 0;
	virtual void print(Iter&) = 0;
	protected:
	Iter() {}
};

class Vector_iterators : public Iter
{
	public:
	Vector_iterators(vector<double>&vec) : v(vec) {}
	double* next() override;
	void print (Iter&) override;
	private:
	vector<double>v;
	double last{0};	 //используется для хранения последнего индекса
};

double* Vector_iterators::next()
{
	if (v.size()==0) {return new double(0);	}
	double* d = new double(v[last]);
	if(last<v.size()) ++last; //продолжаем индексацию до исчерпания всеъ элементов
	return d;
}

void Vector_iterators::print(Iter& it) //печатаем вектор
{
	if (v.size()==0)
	{
		cout << *it.next() << '\n';
	}
	for (int i =0; i<v.size();++i)
	{
		cout << *it.next() << '\n';
	}
}

class List_iterators : public Iter //итераторы списка
{
	public:
	List_iterators (list<double>ls) : l(ls) {}
	double* next () override;
	void print(Iter&) override ;
	private:
	list<double>l;
	list<double>::iterator it = l.begin(); //инициализируем итератор первым элементом, сохраняем текущее положение
};

double* List_iterators::next()  //выдаем следующий элемент
{
	if (l.size()==0) return new double(0);
	double* d = new double(*it);
	++it;
	return d;
}

void List_iterators::print(Iter& I) //печатаем список
{
	if (l.size()==0) cout << *I.next() << '\n';
	for (int i = 0; i < l.size();++i)
	{
		cout << *I.next() << '\n';
	}
}




int main () try {

list<double>a;
List_iterators li (a);
li.print(li);

keep_window_open();

}
catch (exception& e){
	cerr << e.what() << '\n';
	keep_window_open();
}
catch (...){
	cerr << "Unknown error" << '\n';
	keep_window_open();
}