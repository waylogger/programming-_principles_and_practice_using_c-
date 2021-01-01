/*
Спецификация структуры Transactions
1. Включает члены классов Book, Patron и класс Date;
2. Вектор объектов класса Transaction включается в  Library;
3. Чтобы сконструировать объект типа Transaction необходимо, чтобы 
	пользователь был клиентом библиотеки
	книга принадлежала ее фондам
	у пользователя не было задолженности по уплаче членских взносов
4. Если все условия выполняются, то создается объект класса Transaction и помещается в вектор объектов класса Transaction. 
*/


#include <std_lib_facilities.h>
#include <D:\Programms\Ch9\Rep\Date\Date.h>
#include<D:\Programms\Ch9\Rep\Name\Name.h>
#include<D:\Programms\Ch9\Ex\8-Patron\Patron.h>
#include<D:\Programms\Ch9\Ex\5-7-Book\Book.h>

struct Transaction;

class Library 
{
	private:
	vector <Book>books;
	vector<Patron>clients;
	vector<Name>deptors;
	vector<Transaction>transact;
	public:
	vector <Book>&see_books=books;
	vector<Patron>&see_clients=clients;
	vector<Name>&see_deptors=deptors;
	vector<Transaction>&see_transact=transact;
	
	void add_client(); //добавляем клиента в библиотеку
	void add_books (); //добавляем книги
	void add_deptors (const Library&b) ; //вычисляем должников
	void add_transact( Library&b) ; //выдаем книги
		
	void print (); //печатаем всё
		
	bool is_client (const Library& d, const Patron& p) const; //возвращает true если клиент есть в списках
	bool in_fond (const Library& d,const Book& b) const; //возвращает truе если книга в фондах
	bool is_paid (const Library& d,const Patron& p) const; //возвращает true если оплата поступила
	};
struct Transaction //класс выдачи книг
{
	Book a;
	Patron b;
	Date c;
	Library d;
	
	bool transaction (const Library& d, const Book& a, const Patron& b) const;
	
	Transaction () {}
	Transaction(Library& dd, Book aa, Patron bb, Date cc) : d (dd), a(aa), b(bb), c(cc)
	{
		if (!transaction(dd,aa,bb)) cout << "Uncorrect transaction\n"; //небольшой инвариант
	}
	
};
bool Transaction::transaction(const Library& dd, const Book& a, const Patron& c) const 
{
		
		if(!d.is_client(dd,c)) cout << "Client not conformed\n";
		if(!d.in_fond(dd,a)) cout << "Boon not found\n";
		if(!d.is_paid(dd,c)) cout << "Payments not conformed\n";
		if(d.is_client(dd,c)&&d.in_fond(d,a)&&d.is_paid(d,c)) return true; //возвращает true если клиент есть в списках, 
																			//книга есть в фондах и поступила оплата
		return false;
	}
bool Library::is_client (const Library& dd,const Patron& p) const 
	{
		cout << "clients.size() = " << clients.size() << '\n';
		for (int i =0; i<clients.size();++i) if(p.fusername()==clients[i].fusername())return true;
		return false;
	};
bool Library::in_fond (const Library& dd,const Book& b) const 
	{
		cout << "book.size() = " << books.size() << '\n';
		for (int i =0; i<books.size();++i) if(b==books[i])return true;
		return false;
	};
bool Library::is_paid (const Library& dd,const Patron& p) const 
	{
		for (int i =0; i<clients.size();++i) if(p.fusername()==clients[i].fusername()&&clients[i].is_paid()==true)return true;
		return false;
	};
ostream& operator  << (ostream& os, const Transaction& t)
{
	return os << "The book - " << t.a.ftitle() << '(' << t.a.fname() << ')'
			  << "\nISBN - " << t.a.fISBN()
			  << "\nwas given to - " << t.b.fusername() << "\nCN - " << t.b.fcartnum () << '\n' << t.c << '\n'; 
						   
}
void Library::add_books() 
{
	Book b;
	cin >> b;
	books.push_back(b);
}
void Library::add_client () 
{
	Patron p;
	cin >>p;
	clients.push_back(p);
}
void Library::add_deptors (const Library& p) 
{
	for (int i =0; i<clients.size();++i)
		if (clients[i].payments()==false) deptors.push_back(clients[i].fusername());
}
void Library::add_transact(Library&b) 
{
	Library& c = b;
	Date a = {2011,Chrono::Month::jun,11};
	Transaction t = {c, b.see_books[0], b.see_clients[0],a};
	transact.push_back(t);
}
void Library::print ()
{
	cout << "Books list\n";
	for (int i=0;i<books.size();++i) 
		 cout << books [i] << '\n';
	if (books.size()==0) 
		cout << "You are haven't any books for now\n";
	
	cout << "Clients list\n";
	for (int i=0;i<clients.size();++i) 
		cout << clients [i] << '\n';
		if (clients.size()==0) 
		cout << "You are haven't any clients for now\n";
	
	cout << "Transaction list\n";
	for (int i=0; i<transact.size();++i) cout << transact[i] << '\n';
		if (transact.size()==0) cout << "You are haven't any transaction for now\n";
	
	cout << "Deptors list\n";
	for (int i=0;i<deptors.size();++i) cout  << deptors [i] << '\n';
		if (deptors.size()==0) cout << "You are haven't any deptors for now\n";
}
int main () 
try
{
	
	Library b;
	
	int i = 0;
	while (true)
	{
	cout << "Insert: 1 - client\n"
		 << "Insert: 2 - book\n"
		 << "Insert: 3 - transcation\n"
		 << "Insert: 4 - exit\n";
	cin >> i;
	if (i==1)
	{
		b.add_client();
	}
	if (i==2)
	{
		b.add_books ();
	}
	if (i==3)
	{
		b.add_transact(b);
	}
	if (i==4) break;
	}
	b.add_deptors (b);
	b.print();
	keep_window_open();

}
catch (exception& e)
{
	cerr << e.what () << '\n';
	keep_window_open("~~");
}
catch (...)
{
	cerr << "Unknown exception\n";
	keep_window_open("~~");
}