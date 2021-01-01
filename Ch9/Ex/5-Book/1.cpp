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
 class Book{														//open class Book
	private:
	string ISBN = " ";
	string name = " ";
	string autor = " ";
	string date_reg = " ";
	bool issuing;
	vector<Book>books;
	public:
	Book() {};
	void insert(Book& b);
	void print();
	bool is_issue();
	string fISBN () {return ISBN;};
	string fname (){return name;};
	string fautor (){return autor;};
	string fdate_reg (){return date_reg;};
};																//close class Book




ostream& operator<< (ostream& os, Book& d){ 					//open ostream& operator<< (ostream&, Book d)
	if (d.is_issue()) cout << "Выдана\n";
	else cout << "не выдана\n";
	return os << "ISBN -" << d.fISBN() << '\n'
			  << "Название - " << d.fname() << '\n'
			  << "Автор - " << d.fautor() << '\n'
			  << "Дата регистрации авторских прав - " <<d.fdate_reg() << '\n';
			 
} 																//open ostream& operator<< (ostream&, Book d)
void Book::insert(Book& b){										//open void Book::is_correct()
	setlocale(0,"");
	string issue = " ";
	is_isbn a; //инвариант для ISBN
	cout << "ISBN\n";
		cin >> ISBN;
		a.isbn(ISBN);

	cout << "название\n";
		cin >> name;
	
	cout << "автор\n";
		cin >> autor;
	
	cout << "дата регистранции авторских прав\n";
		cin >> date_reg;
	
	cout << "Выдана? Y/N\n";
		cin >> issue;
		if (issue == "Y") issuing = {true};
		else issuing = {false};
	books.push_back(b);
}																//void Book::is_correct()
void Book::print(){												//open void Book::print()
	for (int i =0;i<books.size();++i) cout << books[i];
}										//void Book::print()
bool Book::is_issue(){ 											//open Book::is_issue(string s)
	if (issuing) return true;
	return false;
} 										//close Book::is_issue(string s)
int main () 
try
{																//open main
Book b;

while (true){ 													//open while (true)
	b.insert(b);
	b.print();
	} 															//close while (true)
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















