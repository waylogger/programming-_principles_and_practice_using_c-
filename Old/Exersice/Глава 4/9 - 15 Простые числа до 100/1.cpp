// программа поиска простых чисел до 100
#include <std_lib_facilities.h>

int main () {
int a = 2;
int b = 2;

int c = 0;
double i = 0;
int d = 0;
int e = 0;

double ext = 0;

vector<int>simp = {2, 3, 5, 7};

cout << "Pls enter ext number\n";
cin >> ext;
'\n';
ext=ext-1;
while (i<ext) {
while  (i<ext) {
++i;
if (a%b!=0&&a%3!=0&&a%4!=0&&a%5!=0&&a%6!=0&&a%7!=0&&a%8!=0&&a%9!=0)
simp.push_back (a);
++a;
}
++b;
}

for (int c : simp)
cout << c << "\n";

keep_window_open ();
}



