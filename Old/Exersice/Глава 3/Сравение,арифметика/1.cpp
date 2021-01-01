#include <std_lib_facilities.h>

int main () {
double val1 = 1;
double val2 = 1;
while (val1&&val2) {
cout << "\nVveedile znachenit 1.0\n";

cin >> val1;

cout << "\nVveedile znachenie 2.0 \n";

cin >> val2;

if (val1>val2) cout << val1 << " is biggest\n";
else cout << val2 << " is biggest\n";

cout << "SUM " << val1+val2 << '\n';

cout << "- " << val1-val2 << '\n';

cout << "* " << val1*val2 << '\n';

cout << "/ " << val1/val2 << '\n';


keep_window_open ();
}
}