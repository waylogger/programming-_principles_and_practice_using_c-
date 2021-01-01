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
	void add_client(const Patron& p) ;
	void add_books (const Book& b) ;
	void add_deptors (const Library& p) ;
	void add_transact(const Transaction& t) ;
		
	void print ();
	
	vector <Book>see_books= books;
	vector<Patron>see_clients=clients;
	vector<Name>see_deptors=deptors;
	vector<Transaction>see_transact=transact;
	
	
	bool is_client (const Library& d, const Patron& p) const;
	bool in_fond (const Library& d,const Book& b) const;
	bool is_paid (const Library& d,const Patron& p) const;
	};

struct Transaction
{
	Book a;
	Patron b;
	Date c;
	Library d;
	
	bool transaction (const Library& d, const Book& a, const Patron& b) const;
	
	Transaction () {}
	Transaction(Library& dd, Book aa, Patron bb, Date cc) : d (dd), a(aa), b(bb), c(cc)
	{
		//if (!transaction(d,aa,bb)) error ("Uncorrect transaction");
	}
	
};

istream& operator >> (istream& is,  Transaction& t)
{
	Library& a=t.d;
	Book b;
	Patron c;
	Date d;
	cout << "If you are want to make transaction, please insert ISBN of book\n";
	is >> b;
	cout << "Rider\n";
	is >> c;
	cout << "Insert date os transaction\n";
	is >> d;
	t = Transaction (a,b,c,d);
	return is;
}

int main () 
{
	Transaction t;
	cin >>t;
}
