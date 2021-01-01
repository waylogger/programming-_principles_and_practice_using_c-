#include <std_lib_facilities.h>
class Patron
{ 																				//open class Patron
Name username; //клиент
string cartnum = ""; //номер карты
double pay = 0; //размер платежа
bool paid; //был ли платеж
public:
Patron(Name us, string cn, bool p) : username(us), cartnum(cn), paid(p) {};

Name fusername () const {return username;}
string fcartnum () const {return cartnum;}
bool payments () const {return paid};
bool  is_paid () const {if (paid) return true; return false;}
void in_pay ();
};  																			//close class Patron

void Patron::in_pay () 
{  																				//open Patron::in_pay () 
cout << "Pay = ?";
cin >> pay;	
}  																				//open Patron::in_pay () 

ostream& operator << (ostream& os, const Patron& pt)
{ 																				// open ostream& operator << (ostream& os, const Patron& pt)
	os << "username - " << pt.fusername() << "card number - " << pt.fcartnum() << '\n';
	if (pt.is_paid()) cout << "Paid\n";
	else cout << "Dept\n";
	return os;	
} 																				// close ostream& operator << (ostream& os, const Patron& pt)

istream& operator >> (istream&is, Patron& b)
{ 																				//open istream& operator >> (istream&is, Patron& b)
	setlocale(0,"");
	string username, cardnum,is_paid;
	bool paid;
	cout << "Введите имя клиента\n";
	is >> username;
	cout << "Введите номер карты\n";
	is >> cardnum;
	cout << "Уплачены ли членские взносы? Y\N \n";
	is >> is_paid;
	if (is_paid=="Y") paid = true;
	else if (is_paid=="N") paid = false;
	else error ("Непредусмотренное значение");
	b = (username,cardnum,paid);
	return is;
} 																				//close istream& operator >> (istream&is, Patron& b)



int main () 
{	
	Patron b = {n, "31215858487", false};
	cout << b;
	keep_window_open();
}
