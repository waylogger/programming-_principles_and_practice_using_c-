extern int foo;
void print_foo();
void print (int);


#include <std_lib_facilities.h>
#include <C:\Users\wLr\Desktop\Programming\Tasks\Task1\my.h>

void print_foo () {
cout << foo << '\n';
}
void print(int i) {
cout << i << '\n';
}



#include <C:\Users\wLr\Desktop\Programming\Tasks\Task1\my.cpp>
#include <iostream>
using namespace std;

int main () {
char cc; 
cin >> cc;
foo = 7;
print_foo();
print(99);
}