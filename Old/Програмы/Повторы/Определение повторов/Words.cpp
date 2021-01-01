#include <std_lib_facilities.h>

int main () {
string previous = " ";
string current;
int number_of_word = 0;
while (cin>>current) {
++number_of_word;
if (current==previous) cout << "Repeat!!!! " << current << " after " << number_of_word << "Words" << '\n';
previous = current;
}
}