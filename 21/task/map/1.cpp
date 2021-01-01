#include <iostream>
#include <map>
#include <string>
#include <numeric>


std::istream& operator >> (std::istream& ist, std::map<std::string, int>& m) {
	for (int i =0; i < 10; ++i) {
		std::string s;
		int a;
		std::cin >> s >> a;
		m[s]=a;
	}
	
	return ist;
	
}

int sum_int(int& x, const std::pair<std::string,int>& p1) {

	return x+p1.second;
}

int main() { 


std::map<std::string,int>msi;



msi["lecture"]=1;
msi["photo"]=2;
msi["stan"]=3;
msi["molly"]=4;
msi["kris"]=5;
msi["tony"]=6;
msi["brus"]=7;
msi["klark"]=8;
msi["natalie"]=9;
msi["tanos"]=10;
msi["thor"]=11;
msi["loki"]=12;



std::map<int,std::string> mis;

for (auto pos = msi.begin(); pos != msi.end();++pos) {
	mis[(*pos).second]=(*pos).first;
}	

	

for (auto q : msi) 
	std::cout << (q).first << '-' << (q).second << '\n';

for (auto q : mis) 
	std::cout << (q).first << '-' << (q).second << '\n';





char c;
std::cin >> c;



}