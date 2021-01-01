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
#include <D:\Programms\Ch9\Rep\ISBN\ISISBN.h>
#include <D:\Programms\Ch9\Rep\Date\Date.cpp>
#include <D:\Programms\Ch9\Rep\Name\Name.h>
using Chrono::Date;


enum class Ganre 
{
fantastic=1,prose,periodic,biography,childlhood
};
 class Book{														//open class Book
	
	private:
	string ISBN = "";
	Name names;
	string autor = "";
	Date date_reg;
	Ganre ganre;
	bool issuing;
	
	public:
	Book(string is, Name n, string a, Date dr, Ganre g, bool iss); 
	Book () {};
	
	
	//���������������� �������
	bool is_issue() const;
	string list_of_gares (int i) const;
	string fISBN () const {return  ISBN;};
	Name fname ()const{return names;};
	string fautor ()const{return autor;};
	Date fdate_reg ()const {return date_reg;};
	Ganre fganre()const{return ganre;};
};																//close class Book
string Book::list_of_gares (int i) const 
{
	setlocale(0,"");
	if (i==1) return  "����������\n";
	if (i==2) return  "���������\n";
	if (i==3) return  "�������������� ����������\n";
	if (i==4) return  "������� ����������\n";
	return "���� �� ���������\n";
}
Book::Book (string is, Name n, string a, Date dr, Ganre g, bool iss) : ISBN(is), names(n), autor(a), date_reg(dr), ganre(g), issuing(iss)
{
	is_isbn ab;
	ab.isbn(is);
	
}; 
istream& operator >> (istream& is, Book& a)
{
	setlocale(0,"");
	string isbn,t,issue;
	Name names;
	Date g;
	bool iss;
	int ganre;
	cout << "ISBN\n";
	is >> isbn;
	is_isbn ab;
	ab.isbn(isbn);
	cout << "��������\n";
	is >> t;
	cout << "�����\n";
	cin >> names;
	cout << "���� ����������� ��������� ����\n";
	is >> g;
	cout << "����: 1 - ����������, 2-���������, 3-��������������, 4 - ������� ����������\n";
	is >> ganre;
	cout << "������? Y/N\n";
	is >> issue;
	if(issue=="Y") iss=true;
	else if (issue=="N") iss=false;
	else {cout << "����������������� ��������\n"; throw exception {};};
	a = Book(isbn,names,t,g,Ganre(ganre),iss);
	return is;
}
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
	if (d.is_issue()) cout << "������\n";
	else cout << "�� ������\n";
	return os << "ISBN -" << d.fISBN() << '\n'
			  << "�������� - " << d.fname() << '\n'
			  << "����� - " << d.fautor() << '\n'
			  << "���� - "  << d.list_of_gares(int(d.fganre())) 
			  << "���� ����������� ��������� ���� - " <<d.fdate_reg() << '\n';
			 
} 																//open ostream& operator<< (ostream&, Book d)


bool Book::is_issue()const 	{									//open Book::is_issue(string s)
	if (issuing) return true;
	return false;
} 										//close Book::is_issue(string s)


int main () 
try
{																//open main
Book b;
cin >> b;
cout << b;

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















