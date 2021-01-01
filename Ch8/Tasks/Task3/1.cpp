#include <iostream>
using namespace std;
namespace X {
	int var =0;
	void print ();
}

namespace Y {
	int var =0;
	void print ();
}

namespace Z {
	int var =0;
	void print ();
}

void X::print () { cout << "var = " << var  << '\n';}

void Y::print () { cout << "var = " << var  << '\n';}

void Z::print () { cout << "var = " << var  << '\n';}




int main () {
X::var = 7;
X::print ();
using namespace Y;
var =9;
print ();
{
	using Z::var;
	using Z::print;
	var = 11;
	print();
}
print ();
X::print();
char cc;
cin >> cc;
}