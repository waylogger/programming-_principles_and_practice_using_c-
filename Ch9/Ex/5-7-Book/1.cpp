/*

Разработать класс Book
Члены:
1. Хранение кода ISBN
2. Название
3. Фамилия автора
4. Дата регистрации авторских прав
5. Данные о том выдана ли книга на руки и когда
5. Создать функции возвращающие эти данные
6. Создать функцию, проверяющая выдана ли книга на руки
7. Предусмотреть инвариант: ISBN n-n-n-x, где n - целое число; x - цифра или буква, хранить ISBN как srting
*/


#include <std_lib_facilities.h>
//#include <D:\Programms\Rep\Date\Date.cpp>
#include <D:\Programms\Rep\ISBN\ISISBN.h>


enum class Ganre 
{
fantastic=1,prose,periodic,biography,childlhood
};



 class Book{														//open class Book
	private:
	string ISBN = "";
	string name = "";
	string autor = "";
	string date_reg = "";
	Ganre ganre;
	bool issuing;
	vector<Book>books;
	public:
	Book(string is, string n, string a, string dr, Ganre g, bool iss); 
	Book() {};
	void insert(Book& b);
	void print(Book& d);
	bool is_issue() const;
	string fISBN () const {return  ISBN;};
	string fname ()const{return name;};
	string fautor ()const{return autor;};
	string fdate_reg ()const {return date_reg;};
	Ganre fganre()const{return ganre;};
	vector<Book>see_books = books;
};																//close class Book

Book::Book (string is, string n, string a, string dr, Ganre g, bool iss) : ISBN(is), name(n), autor(a), date_reg(dr), ganre(g), issuing(iss)
{
	is_isbn ab;
	ab.isbn(is);
	
}; 

bool operator == (const Book& a, const Book& b)
{
return a.fISBN() == b.fISBN();
}


bool operator != (const Book& a, const Book&b)
{
return !(a.fISBN()==b.fISBN());
}




ostream& operator<< (ostream& os, const Book& d){ 					//open ostream& operator<< (ostream&, Book d)
	setlocale(0,"");
	if (d.is_issue()) cout << "Выдана\n";
	else cout << "не выдана\n";
	return os << "ISBN -" << d.fISBN() << '\n'
			  << "Название - " << d.fname() << '\n'
			  << "Автор - " << d.fautor() << '\n'
			  << "Жанр - "  << int(d.fganre()) << '\n'
			  << "Дата регистрации авторских прав - " <<d.fdate_reg() << '\n';
			 
} 																//open ostream& operator<< (ostream&, Book d)

void Book::print(Book& b){												//open void Book::print()
	for (int i =0;i<b.see_books.size();++i) cout << b.see_books[i];
}										//void Book::print()
bool Book::is_issue()const 	{									//open Book::is_issue(string s)
	if (issuing) return true;
	return false;
} 										//close Book::is_issue(string s)
int main () 
try
{																//open main
Book b = {"978-225-154-1548","Honor","Buffi","12.12.2015", Ganre::periodic,false};
b.see_books.push_back(b);
b.print(b);
keep_window_open();
}																//close main

catch (exception& e) 
{ 																//open catch (exception& e) 
	cerr << e.what () << '\n';
	keep_window_open();
} 																//close catch (exception& e) 
catch (...)
{ 																//open catch (...) 
	cerr << "Ups..." << '\n';
	keep_window_open();
} 																//close catch (...) 















