#include <regex>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	
	
		
	regex pattern;
	
	string pat;
	cout << "Введите шаблон\n";
	getline(cin,pat);
	
	try{
		pattern = pat;
		cout << "Шаблон: - " << pat << '\n';
		
	}
	catch(...){
		cout << "некорректное выражение " << pat << '\n';
		exit(1);
	}
	
	cout << "Введите строки:\n";
	int lineno = 0;
	
	for (string line; getline(cin,line);)
	{
		++lineno;
		smatch matches;
		if (regex_search(line,matches,pattern)){
			cout << "строка " << lineno << ": " << line << "\n";
			for (int i = 0; i < matches.size(); ++i){
				cout << "\t совпадения[" << i << "]: " << matches[i] << '\n'; 
			}
		}
		else 
			cout << " не соответствует\n";
	}
	
	
	
	char c;
	cin >> c;
}
