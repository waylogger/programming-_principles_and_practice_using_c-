#include <std_lib_facilities.h>

int main () {

int a = 1.0;
int n = 1.0;
while (a)
{
cout << "Vvedite chislo\n";
cin >> a;
n=a%2;
'\n';
cout << "Ostatok ot deleniya = " << n;
if (n==0)
cout << "\nvvedennoy chislo - " << "Chetnoye\n";
else
cout << "\nvvedennoy chislo - " << "Ne chetnoye\n";
}
}