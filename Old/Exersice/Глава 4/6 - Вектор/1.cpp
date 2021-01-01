#include <std_lib_facilities.h>

int main () {

vector<string>chisla;

chisla.push_back ("zero");
chisla.push_back ("one");
chisla.push_back ("two");
chisla.push_back ("three");
chisla.push_back ("four");
chisla.push_back ("five");
chisla.push_back ("six");
chisla.push_back ("seven");
chisla.push_back ("eight");
chisla.push_back ("nine");
chisla.push_back ("ten");

int a = 0;
while (a!=64868488455652) {
cout << "Vvedite chislo ot 0 do 10\n";
cin >> a;

if (a==0)
cout << chisla[0] << '\n';

else if (a==1)
cout << chisla[1] << '\n';

else if (a==2)
cout << chisla[2] << '\n';

else if (a==3)
cout << chisla[3] << '\n';

else if (a==4)
cout << chisla[4] << '\n';

else if (a==5)
cout << chisla[5] << '\n';

else if (a==6)
cout << chisla[6] << '\n';

else if (a==7)
cout << chisla[7] << '\n';

else if (a==8)
cout << chisla[8] << '\n';

else if (a==9)
cout << chisla[9] << '\n';

else if (a==10)
cout << chisla[10] << '\n';
}
}