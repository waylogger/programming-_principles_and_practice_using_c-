#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector> 



int main ()
{
	
	std::string s = "C++ is a general purpose programming language designed";
	s = s + " to make programming more enjoyabe for the serious programmer. Except ";
	s = s + "for minor details, C++ is a superset of the C programming language. ";
	s = s + "In addition to the facilities provided by C, C++ provides flexible and efficient ";
	s = s + "facilities for defining new types.";
	std::string ss;
	std::vector<std::string>vs;
	for (int i =0; i < s.size(); ++i) {
		
		if (s[i] != '.' && s[i] != ',')
			ss = ss + s[i];
		
		if (s[i] == ' ') {
			vs.push_back(ss);
			ss = "";
		}
		
	}

	std::map<std::string,int>msi;
	
	for (auto p : vs)
		++msi[p];
	
	std::multimap<int,std::string>mis;
	
	
	for (auto p : msi)
		mis.insert(std::pair<int,std::string>{p.second,p.first});

	for (auto p : mis)
		std::cout << p.first << '-' << p.second << '\n';
	
	
	char c;
	std::cin >> c;
}