/*
1. �������� ����� Library. 
2. �������� � ���� ������� ������� ���k � ��tron. 
3. �������� ����� ��������� Transaction � ������������� � ���
����� ������� Book, Patron � ����� Date �� ������ ������ �����. 
4. �������� ������ �������� ������ Transaction. 
5. �������� �������. ����������� ������ � ������ � �������� ����������. � ����� � ���������
���� (������ �� ����� ��������) . 
6.���� ������������ ���� �����, ���������� ������ ���� �������,
��� ������������ �������� �� ��������, � ����� ����������� �� ������. 
���� ��� ������� �� �����������,
������� ��������� �� ������. 
7.��������� �����, ��� �� �
8.������������ ������������� �� ������ �������� ������� .
���� �������������
����, ������� ��������� �� ������ .
���� ���, ��������
������ ������ Transaction � ��������� ��� � ������ �������� ������
Transaction. 
9.�������� ����� �������. ������������ ������, ����������
����� ���� ��������, ������� ������������.
*/

#include <std_lib_facilities.h>
#include <D:\Programms\Ch9\Rep\Date\Date.h>
#include<D:\Programms\Ch9\Rep\Name\Name.h>
#include<D:\Programms\Ch9\Ex\8-Patron\Patron.h>
#include<D:\Programms\Ch9\Ex\5-7-Book\Book.h>
class Library{ 																				//open class Library
private:
vector <Book>books;
vector<Patron>clients;
vector<double>deptors;

public:
struct Transaction
{ 																							// open 	 struct Transaction					
	Book b;
	Patron p;
	Chrono::Date d;
	Transaction () {}
	Transaction(Patron p, Book b, Chrono::Date d);
}; 																							// close struct Transaction
private:
vector<Transaction>transac; 
public:
bool transaction (Transaction& t); //��������� ����������� ���� ���������� ��� ������ ����� �������
bool is_client (Patron& p); //��������� �������� �� ���������� ���� �������� ����������
bool in_fond (Book& b); //��������� ��������� �� ����� � ������ ����������
bool is_paid (Patron& p); // ��������� ������
void injector (const Transaction&t);

void add_book(); //��������� ����� � ����
void add_client(); //��������� ��������

const vector<Transaction>& see_transac = transac;
const vector<double>& see_deptors = deptors;
const vector<Book>&see_books = books;
const vector<Patron>&see_clients = clients;

void print(const vector<Book>& see_books, const vector<Patron>&see_clients, 
		   const vector<Transaction>&see_transac, const vector<double>&see_deptors);
		   
};  																						// close class Library
Library::Transaction::Transaction(Patron name, Book title, Chrono::Date date) 
									:  p(name), b(title), d(date)   {  
 																							//open Library::Transaction::Transaction(Patron name, 
																							//Book title, Chrono::Date date) :  p(name), b(title), d(date)
	
																	} 						//close Library::Transaction::Transaction(Patron name, 
 																							//Book title, Chrono::Date date) :  p(name), b(title), d(date)
ostream& operator << (ostream& os, const Library::Transaction& t){ 							//open ostream& operator << (ostream& os, Transaction& t)
	return os << "\nTransactions\n"
			  << "ISBN - " << t.b.fISBN()  << "\nTitle - " << t.b.ftitle()
			  << " (" << t.b.fname() << ")"
			  << '\n' << "The book received by " 
			  << t.p.fusername()
			  << "\nCard number - "
			  << t.p.fcartnum()
			  << "\nThe date of received - " 
			  << t.d;
																 }							// close ostream& operator << (ostream& os, Transaction& t)

																 
void Library::add_book(){  																	//open Library::add_book()
	setlocale(0,"");
	Name johnFiladelphia = {"John", "Filadelphia"};
	Date d = {2008,Chrono::Month::jul,16};
	Ganre g = Ganre::fantastic;
	Book a = {"978-413-552-0816", johnFiladelphia,"Homecoming",d, g,false};
	//cin >> a;
	books.push_back(a);		
						}																	// close Library::add_book()
	
					
void Library::add_client()  {  																//open void add_client()
Name un = {"John", "Milton"};
string cn = "3125487785488";
bool p = false;
Patron b = {un,cn,p};
//cin >> b;
clients.push_back(b);
							}																	 
														 
																 
void Library::injector (const Transaction&t){												//open void Library::injector (const Transaction&t)
transac.push_back(t);
											} 												//close void Library::injector (const Transaction&t)
bool Library::transaction (Transaction&t){ 													//open bool Library::transportation (Book b, Patron p)
	if (is_client(t.p)&&in_fond(t.b)&&is_paid(t.p)) return true;
	if (!is_client(t.p)) cout << "Client not found\n";
	if (!in_fond(t.b)) cout << "Book not found\n";
	if (!is_paid(t.p)) cout << "Payments not conformed\n";
	if (!is_client(t.p)||!in_fond(t.b)||!is_paid(t.p)) return false;
	return false;
											   }											// close bool Library::transportation (Book b, Patron p)			

bool Library::is_paid (Patron& p)
{
	
	if (p.is_paid()) {return true;}
	return false;
	
}
	
											   
											   
bool Library::is_client(Patron& p){ 														//open bool Library::is_client(Patron p)
for (int i =0; i<clients.size();++i)
{ 																							//open for (int i =0; i<clients.size();++i)
		if (p.fusername()==clients[i].fusername()) 
		return true;
}  																							//close for (int i =0; i<clients.size();++i)
return false;
} 																							//close bool Library::is_client(Patron p)
bool Library::in_fond(Book& b) { 															//open bool Library::in_fond()
	for (int i=0; i<books.size();++i)
	{ 																							//open for (int i=0; i<books.size();++i)
	if (b.fISBN()==books[i].fISBN()) return true;
	} 																							//close for (int i=0; i<books.size();++i)
	
	return false;
								}																//close bool Library::in_fond()
																							//close void add_client()
void Library::print(const vector<Book>& books, 
					const vector<Patron>&clients, 
					const vector<Transaction>&transac,
					const vector<double>&deptors){    										//open void Library::print(vector<Book>& books, vector<Patron>clients)
	//for (int i=0;i<books.size();++i) 
	//	cout << books [i]; 
	//for (int i=0;i<clients.size();++i) 
	//	cout << clients[i];
	for (int i=0;i<transac.size();++i) 
		cout << transac[i]; 
	for (int i=0;i<deptors.size();++i) 
		cout << deptors[i]; 					 }											// close void Library::print(vector<Book>& books, vector<Patron>clients)
int main () {																				//open int main()
	Library b;
	b.add_book();
	b.add_client();

	Name johnFiladelphia = {"John", "Filadelphia"};
	Date d = {2008,Chrono::Month::jul,16};
	Ganre g = Ganre::fantastic;
	Book a = {"978-413-552-0816", johnFiladelphia,"Homecoming",d, g,true};
	
	Name un = {"John", "Milton"};
	string cn = "3125487785488";
	Patron e = {un,cn};
	
	Date m = {2016,Chrono::Month::dec,24};
	Library::Transaction t  = {e,a,m};
	if (b.transaction(t)) b.injector(t);
	b.print (b.see_books, b.see_clients, b.see_transac,	b.see_deptors);
	
	keep_window_open();
			}																				//close int main()





















