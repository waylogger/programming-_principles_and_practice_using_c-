#include <std_lib_facilities.h>




class Patron
{
string username = "";
string cartnum = "";
double pay = 0;
bool paid;
public:
Patron() {};
Patron(string us, string cn, bool p) : username(us), cartnum(cn), paid(p) {};
string fusername () {return username;}
string fcartnum () {return cartnum;}
double fpay () {return pay;}
void in_pay (){pay = 5;};
bool is_paid () {if (paid) return true; return false;}
};



int main () 
{
	Patron b = {"Mark", "312", false};
	b.in_pay();
	if (b.is_paid()) cout << "Paid\n";
	else cout << "Dept\n";
	cout << b.fcartnum() << '\n';
	keep_window_open();
}
//bool he_pay();
