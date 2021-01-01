#include <std_lib_facilities.h>

class Patron
{ 																				//open class Patron
Name username; //клиент
string cartnum = ""; //номер карты
double pay = 0; //размер платежа
bool paid; //был ли платеж
public:
Patron(Name us, string cn, bool p) : username(us), cartnum(cn), paid(p) {};
Patron(Name us, string cn) : username(us), cartnum(cn) {};
Patron() {};

Name fusername () const {return username;}
string fcartnum () const {return cartnum;}
bool payments () const {return paid;}
bool  is_paid () const {if (paid) return true; return false;}
void in_pay ();
};  																			//close class Patron

void Patron::in_pay () 
{  																				//open Patron::in_pay () 
cout << "Pay = ?";
cin >> pay;	
}  																				//open Patron::in_pay () 

bool operator == (const Name b, const Name a)
{  																				// open bool operator == (const Name b, const Name a)
string s = b.ffname()+b.fsname();
string k = a.ffname()+a.fsname();
return s==k;	
}  																				// open bool operator == (const Name b, const Name a)


ostream& operator << (ostream& os, const Patron& pt)
{ 																				// open ostream& operator << (ostream& os, const Patron& pt)
	os << "username - " << pt.fusername() << "\ncard number - " << pt.fcartnum() << '\n';
	if (pt.is_paid()) cout << "Membership fees paid was paid\n";
	else cout << "Membership fees not paid\n";
	return os;	
} 																				// close ostream& operator << (ostream& os, const Patron& pt)

istream& operator >> (istream&is, Patron& b)
{ 																				//open istream& operator >> (istream&is, Patron& b)
	setlocale(0,"");
	Name username;
	string cardnum,is_paid;
	bool paid;
	cout << "Name of client\n";
	is >> username;
	cout << "Number of card \n";
	is >> cardnum;
	cout << "Membership fees paid? Y/N? \n";
	is >> is_paid;
	if (is_paid=="Y") paid = true;
	else if (is_paid=="N") paid = false;
	else error ("Непредусмотренное значение");
	b = Patron(username,cardnum,paid);
	return is;
} 																				//close istream& operator >> (istream&is, Patron& b)


/*
int main () 
{	
	Patron b;
	cin >> b;
	cout << b;
	keep_window_open();
}
*/