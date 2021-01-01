
#include <iostream>
#include <string>
#include <ctime>
using namespace std;


class Link
{
	private: //блок данных: строка, ключ и 4 указателя
	Link* succ 	{nullptr};
	Link* prev	{nullptr};
	Link* low	{nullptr};
	Link* high	{nullptr};
	string value = "";
	int key = 5;
	
	public:
	//константные функции доступа к блоку данных
	int what_key() 			const {return key;}
	string what_value() 	const {return value;}
	Link* next() 			const {return succ;}
	Link* previous() 		const {return prev;}
	Link* next_floor() 		const {return high;}
	Link*  prev_fliir() 	const {return low;}
	 
	
	//конструкторы, деструктор и операторы
	Link(int k, string v, Link* s, Link* p, Link* l , Link* h);
	Link();
	Link (const Link& p);
	Link (const Link* p);
	
	
	~Link();
 
	
	Link* operator=			(const Link*p);
	Link* operator=			(const Link&p);
	Link& operator=			(Link&& p);
	
	//полезный арсенал
	Link* search 			( const int&  i);
	Link* add_ordered  		( const Link* p);
	Link* erase  			( const Link* p);
	Link* add  				( Link* p);
	Link* insert  			( Link* p);
	Link* head();
	Link* last();
	
	//нумерация
	int closer (const int& k) ; //ближайший меньший ключ к введенному
	 

};
void print(Link* p); //объявление печатающей функции
int del = 0;
int create_ref = 0;
int create_ptr = 0;
int create_def = 0;
int create_norm = 0;

Link::~Link()
{



++del;
}

Link* Link::erase(const Link* a)
{
	Link q = this;
	
	Link* p = new  Link{q};
	
	p = p->search(a->key);

	
	
	if (p->prev && p->succ)
	{
		 
		p->prev->succ = p->succ;
		p->succ->prev = p->prev;
	}		

if (!p->prev && !p->succ) 
{
		 
	return nullptr;
}
else if (!p->succ) {p = p->prev; 	  return p;}
else if (!p->prev ){p = p->succ; 	  return p;}

	
	
	
	return p;
	
}
Link::Link(const Link& p)
{
	++create_ref;
	Link* t = this;
	Link* n = new Link{p.key,p.value,p.succ,p.prev,p.low,p.high};
	
	while (n)
	{

		t->key = n->key;
		t->value = n->value;
		if (n->succ) t->succ = new Link;
		t = t->succ;
		n = n->succ;
	}
	delete n;
	
}

Link::Link(const Link* p)
{
	++create_ptr;
	Link* t = this;
	Link* n = new Link{p->key,p->value,p->succ,p->prev,p->low,p->high};
	
	while (n)
	{

		t->key = n->key;
		t->value = n->value;
		if (n->succ) t->succ = new Link;
		t = t->succ;
		n = n->succ;
	}
	delete n;
	
}

Link::Link(int k, string v="", Link* s = nullptr, Link* p =nullptr, Link* l = nullptr, Link* h = nullptr) :
 key(k), value(v), succ (s), prev (p), low(l), high(h) //конструктор
{
	
	++create_norm;
	//cout << "Key is - "<<k << '\n';
}

Link::Link() : //конструктор по умолчанию
key(5), value(""), succ (nullptr), prev (nullptr), low(nullptr), high(nullptr)
{
	++create_def;
}



Link* Link::add ( Link* p)  //добавляем элемент после текущего
{
	Link* n = this;

	
	if (!n) return p;
	if (!p) return n;
	//если есть что дальше, то переводим указатели на вставляемый элемент
	if (n->succ)
	{
		n->succ->prev = p;
		p->succ = n->succ;
	}
	n->succ = p;
	p->prev = n;
	cout << "Done\n";
	return p;
	
}

Link* Link::insert(  Link* p)  //добавляем элемент до текущего

{	//защищаем данные

	Link* n = this;

	if (!n) return p;
	if (!p) return n;
	//если есть что до, то переводим указатели на вставляемый элемент
	if (n->prev)
	{
		n->prev->succ = p;
		p->prev = n->prev;
	}
	
	n->prev = p;
	p->succ = n;
	
cout << "Done\n";
	return p;
}



Link* Link::head() //в начало списка
{
	Link* p = this;
		
	while (p->prev)	p = p->prev;
	return p;
}

void print(Link* p) //печатаем
{
	p = p->head();
	
	while (p)
	{
		cout << p->what_key() << ' ' << p->what_value() << '\n';
		p = p->next();
	}
	
	
}

int Link::closer(const int& i) 
{
	
	Link* p = this;
	
	int min = 900000;
	int to_min = 900000;
	int buffer = 0;
	int min_buffer = 0;
	bool c {false};
	while (p)
	{
		
		if (p->key < i) //нас интересуют только ключи, которые меньше искомого
		{
			c = true;
			int g = i-p->key; //min должно выразить в итоге найменьшую по модулю разницу между ключами,
									//разница = расстояние, меньшая разница = ближайший ключ
			if (abs(g) < min) 
			{
				min = abs(g); //нашли меньшую разницу?
				buffer = p->key; //сохраняем ключ!
			}
		}
		if (!c && p->key > i)
			{
			int g = i-p->key;
			
			if (to_min > abs(g)) 
				{
				to_min = abs(g);
				min_buffer = p->key;
				}
			}
		if (p->key == i) 
		{
			return p->key;			
		}
		p=p->succ;
	}
	if (c) return buffer;
	else return min_buffer;
}


Link* Link::search(const int& i) //простая поисковая функция по номеру ключа
{
	Link* p = this;
	
		while(p)
			{
			if (p->key == i) 
				{
				while (p->succ && p->succ->key == i) 
				{
			 
					p=p->succ;
				}
				 
				return p;
				}
				 
				p=p->succ;
			}

	cout << "Search is failed";
	return nullptr;
}

Link* Link::add_ordered ( const Link* q) 
{
	Link a = q;
	Link* p = new Link{a};
	Link* n = this;
	//проверка на 0
	if (!n) return p;
	if (!p) return n;
	//поиск ближайшего узла
	
	int i = n->closer(p->key);
	//cout << "Closed to " << p->key << " - is -" << i << '\n';

	n = n->search(i);
	
	if (p->key >= i)
	{
		n = n->add(p);
	 
		delete p;
		return n;
	}		
		
	if (p->key < i) 
	{
		n = n->insert(p);
		 
		delete p;
		return n;
	}
	

	delete p;
	return n;
}


bool is_order( const Link*q)
{
	Link a = q;
	Link* p = new Link{a};
	while (p->next())
	{
		if (p->what_key() > p->next()->what_key()) 
		{
			delete p;
			return false;
		}
		p = p->next();
	}
	delete p;
	return true;	
	
}
 

int main ()
{

Link* p = new Link{1};

p = p->add_ordered(new Link{2});
p = p->head();
p = p->add_ordered(new Link{2});
p = p->head();
p = p->add_ordered(new Link{1242});

print(p);

	char c;
	cin >> c;
}



//cout << "Create by ref - "<<create_ref << '\n';
//cout << "Create by ptr - "<<create_ptr << '\n';
//cout << "Create by def - "<<create_def << '\n';
//cout << "Create by norm - "<<create_norm << '\n';
//cout << "Delete - "<< del << '\n';
 
	
 