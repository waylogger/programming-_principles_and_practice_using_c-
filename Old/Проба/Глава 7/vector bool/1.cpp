#include <std_lib_facilities.h>

class Variable {
public:
string name;
bool constants;
Variable(bool c, string n) : constants(c), name(n) { }
Variable(string n) : name(n) { }
};

vector<Variable>names;

Variable get () {
bool c;
string s;
char ch;
cin >> ch;

if (isalpha(ch)) {

s += ch;

if (s=="const") c = {true};
else c = {false};
}
while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) 
s+=ch;
if (c) return Variable (c, s);
else return Variable (s);
};

void insert () {
	Variable t = get ();
	names.push_back(t);
};

void output () {
for (int i = 0; i<names.size(); ++i) {
	cout << names[i].constants << "Константы\n";
	cout << names[i].name << "Константы\n";
	return;
}
};



int main () {
	setlocale(0 ," ");
	cout << "Константа, имя\n";
	while (cin) {
		output ();
	}
		
};