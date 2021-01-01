/*

����������� ����� Book
�����:
1. �������� ���� ISBN
2. ��������
3. ������� ������
4. ���� ����������� ��������� ����
5. ������ � ��� ������ �� ����� �� ���� � �����
5. ������� ������� ������������ ��� ������
6. ������� �������, ����������� ������ �� ����� �� ����
7. ������������� ���������: ISBN n-n-n-x, ��� n - ����� �����; x - ����� ��� �����, ������� ISBN ��� srting
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
	if (d.is_issue()) cout << "������\n";
	else cout << "�� ������\n";
	return os << "ISBN -" << d.fISBN() << '\n'
			  << "�������� - " << d.fname() << '\n'
			  << "����� - " << d.fautor() << '\n'
			  << "���� ����������� ��������� ���� - " <<d.fdate_reg() << '\n';
			 
} 																//open ostream& operator<< (ostream&, Book d)
void Book::insert(Book& b){										//open void Book::is_correct()
	setlocale(0,"");
	string issue = " ";
	is_isbn a; //��������� ��� ISBN
	cout << "ISBN\n";
		cin >> ISBN;
		a.isbn(ISBN);

	cout << "��������\n";
		cin >> name;
	
	cout << "�����\n";
		cin >> autor;
	
	cout << "���� ������������ ��������� ����\n";
		cin >> date_reg;
	
	cout << "������? Y/N\n";
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















