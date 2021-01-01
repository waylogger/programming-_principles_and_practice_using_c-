#include <std_lib_facilities.h>
int main () {
int p;
int s = 3;
s = s*2;
while (cout<<++s<<'\n') {
if (s!=++s) cout << "no!\n";
if (s>=2500) while(cout<<--s<<'\n');
} 
}