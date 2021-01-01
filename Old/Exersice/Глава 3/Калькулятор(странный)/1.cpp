#include <std_lib_facilities.h>

int main () {

string operation;
int b = 1;
int c = 1;
while (b&&c)
{
cout << "\nVvelite simvol operazii i operandi\n";

cin >> operation >> b >> c;

int plus = b+c;
int minus = b-c;
int mul =  b%c;
int dev = b/c;

if (operation=="+")
cout << '\n' << plus << "\n";

else if (operation=="-")
cout << '\n' << minus << "\n";

else if (operation=="%")
cout << '\n' << mul << "\n";

else if (operation=="/")
cout << '\n' << dev << "\n";

}
}

