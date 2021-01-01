#include <std_lib_facilities.h>

class numbers {
public:
int get();
void ignore(int ch);
};

numbers number;

void numbers::ignore (int num) {
if (num>=100) return;
};

void clean_up_mess () {
int ch = 0;
number.ignore(ch);
};

int numbers::get() 
try {
int num = 0;
while(cin >> num) {
if (num > 100) 
{error ("веденное число больше 100!!!\n"); 
cin.putback(num);}
else return num;
}
	return num;
	}
catch (exception& e) {
cerr << e.what ();
clean_up_mess ();
}

int main () {
setlocale (0, "");
cout << "¬ведите число до 101\n";
int t = number.get();
while (true) {
if (t <= 100) cout << t+1 << '\n';
t = number.get();
}
};


