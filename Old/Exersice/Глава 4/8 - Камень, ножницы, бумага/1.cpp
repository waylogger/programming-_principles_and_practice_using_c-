#include <std_lib_facilities.h>

int main () {

string go = " ";
int i = 0;

cout	<< "Kamenb, nozhnitsi, bumaga, 1, 2, 3\n"
	<< "Gotov? Pishi - go\n";
while (i<7000)
{ 
cin >> go;
++i;
if (i==3||i==5||i==7||i==9||i==11||i==13||i==15)
	cout << "kamenb\n";

if (i==2||i==4||i==6||i==8||i==10||i==12||i==14||i==16)
	cout << "nozhnitsi\n";

if(i==1||i==17||i==18||i==19||i==20||i==21||i==22||i==23||i==24||i==25)
	cout << "bumaga\n";
}
}
