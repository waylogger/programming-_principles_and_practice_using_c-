#include <std_lib_facilities.h>

int main () {
double a = 1;
double b = 1;
string first = " ";
string second = " ";
int change = 0;

string operation = " ";

cout << "Viberite stil vvods: 1-slova; 2-chisla\n";
cin >> change;

if (change==1)
while (first!="eleven") {
cout << "Vvedite operator, and 2 numbers\n";
cin >> operation >> first >> second;

if (first=="zero")
a=0;
else if (first=="one")
a=1;
else if (first=="two")
a=2;
else if (first=="three")
a=3;
else if (first=="four")
a=4;
else if (first=="five")
a=5;
else if (first=="six")
a=6;
else if (first=="seven")
a=7;
else if (first=="eight")
a=8;
else if (first=="nine")
a=9;
else if (first=="ten")
a=10;

if (second=="zero")
b=0;
else if (second=="one")
b=1;
else if (second=="two")
b=2;
else if (second=="three")
b=3;
else if (second=="four")
b=4;
else if (second=="five")
b=5;
else if (second=="six")
b=6;
else if (second=="seven")
b=7;
else if (second=="eight")
b=8;
else if (second=="nine")
b=9;
else if (second=="ten")
b=10;

double plus =a+b;
double minus = a-b;
double mul = a*b;
double dev = a/b;

if (operation == "+")
cout << "Summa " << a << " i " << b << " ravna " << plus << '\n';

else if (operation == "-")
cout << "Raznitsa " << a << " i " << b << " ravna " << minus << '\n';

else if (operation == "*")
cout << "Proizvedenie " << a << " i " << b << " ravno " << mul << '\n';

else if (operation == "/")
cout << "Chastnoye " << a << " i " << b << " ravno " << dev << '\n';
}

if (change==2)
while (a&&b) {
cout << "Vvedite operator, and 2 numbers\n";
cin >> operation >> a >> b;

double plus =a+b;
double minus = a-b;
double mul = a*b;
double dev = a/b;

if (operation == "+")
cout << "Summa " << a << " i " << b << " ravna " << plus << '\n';

else if (operation == "-")
cout << "Raznitsa " << a << " i " << b << " ravna " << minus << '\n';

else if (operation == "*")
cout << "Proizvedenie " << a << " i " << b << " ravno " << mul << '\n';

else if (operation == "/")
cout << "Chastnoye " << a << " i " << b << " ravno " << dev << '\n';
}
}