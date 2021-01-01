#include <string>
#include <iostream>
#include <vector>
#include <regex>

using namespace std;
int main()
{

	regex reg {R"(.+\n)"};
	smatch sm;
	
	string rock = "hello kitty\n";
	
	if (regex_match(rock,sm,reg))
		cout << "Newline is equal template '.' \n";
	else
		cout << "Newline is not equal template '.' \n";
	
	
	char c;
	cin >> c;
}