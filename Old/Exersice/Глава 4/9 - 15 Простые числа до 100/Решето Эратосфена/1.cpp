// решето эратосфена
#include <std_lib_facilities.h>

int main () {

int a = 2;
int b = 2;
int ext = 0;
int i = -2;

int v = 0;

vector<int>all = {2,3,7};

cout << "Vvedite znachenie\n";
cin >> ext;
ext=ext-1;


while (i<ext) {
while (i<ext) {
++i;
if (a%b!=0&&a%3!=0&&a%5!=0&&a%7!=0&&a%9!=0)
all.push_back (a);
++a;


}
++b;
}

for (int v : all)
cout << v << "\n";
keep_window_open ();
}
 