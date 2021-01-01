#include <std_lib_facilities.h>

char get ()
{
char n;
cin >> n;
return n;
};

int main ()
try
{
setlocale(0, "");
bool a = {false};
char d1;
char d2;
char d3;
char d4;



cout << "Введите число\n";
	
while (a==false)
{

d1 = get ();
d2 = get ();
d3 = get ();
d4 = get ();

int z1 = d1 - '0';
int z2 = d2 - '0';
int z3 = d3 - '0';
int z4 = d4 - '0';

cout << z1 << z2 << z3 << z4 << " - это ";
cout << d1 << " - тысяч, ";
cout << d2 << " - сотен, ";
cout << d3 << " - десятков, ";
cout << d4 << " - единиц \n";
a=true;
}
keep_window_open ("~");
}

catch (exception& e)
{
cerr << e.what ();
keep_window_open ("~");
}