#include <std_lib_facilities.h>

int main () {
cout << "Please, input number of integer\n";
int n;
cin >> n;
cout << "n== " << n << "\nn+1 " << n+1 << "\n 3ple n " << n*3 << "\n dounle n " << n+n << "\n n^2 " << n*n << "\n half of n " << n/2 << "\n Rest of n " << n%2;
double s=n;
cout << "\n root of n " << sqrt(s) << '\n';
keep_window_open ();
}