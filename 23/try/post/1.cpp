#include <regex>
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP (1251);
	
	ifstream in {"D:\\data\\post.txt"};
	if (!in){
		cerr << "Нет файла\n";
		char cc;
		cin >> cc;
		exit(1);
	}
		
	
	string spat = R"(\w{2}\s*\d{5}(-\d{4})?)";
	
	regex pat {spat};
	
	cout << "шаблон: " << spat<< '\n';
	
	int lineno =0;
	
	for (string line; getline(in,line);){
		++lineno;
		smatch matches;
		if (regex_search(line,matches,pat))
			cout << lineno << ": " << matches[0] << '\n';
	}
	
	char c;
	cin >> c;
	
	
}