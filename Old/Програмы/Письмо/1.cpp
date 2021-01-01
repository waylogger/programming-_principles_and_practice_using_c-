#include <std_lib_facilities.h>

int main () {
cout << "Input adressat and push 'enter':\n";
string first_name;
string friend_name;
string tvoe_imya;
cin >> first_name;
cout << "Input friend name ";
cin >> friend_name;
char friend_sex = 0;
cout << "\nPlease, input sex of friend \n";
cin >> friend_sex;
cout << "Tvoe imya \n";
cin >> tvoe_imya;
'\n';
int age = 0;
cout << "Please input age of your friend \n";
cin >> age;
cout <<"\nDear " << first_name << ", how are you? Whats app? How are your cat?? How much time ago you are meet " << friend_name << "?\n"; 
if (friend_sex=='m')
cout << "Can you ask him to wtite to me? \n";
if (friend_sex=='w') 
cout << "Can you ask her to wtite to me? \n";
cout << "I am hear what you nearly meet birst day and you " << age << " years!!!";
if (age==0)
simple_error ("Are you kidding?\n");
if (age>110)
simple_error ("Are you kidding?\n");
if (age<=12)
cout << "Next year tebe budet " << ++age << " let?\n";
if (age==17)
cout << "V sleduyushem gody bydesh golosovat? \n";
if (age>70)
cout << "Nadeyus ti ne skuchaesh na pensii \n";
cout << "Iskrenne tvoy " << tvoe_imya << ".\n";
keep_window_open ();
}