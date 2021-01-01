#include <std_lib_facilities.h>

int main () {
int a = 1;
while (a) {
cout << "\nVvedite chislo 1-4 \n";

cin >> a;

if (a==1)
cout << '\n' << "one";
else if (a==2)
cout << '\n' << "two";
else if (a==3)
cout << '\n' << "tree";
else if (a==4)
cout << '\n' << "four";
else
cout << "\n I am dont know this number - i am studid PC";
}
}