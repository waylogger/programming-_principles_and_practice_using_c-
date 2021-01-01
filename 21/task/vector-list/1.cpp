#include <string>
#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

struct Item {

std::string name;
int iid = 0;
double value = 0.0;

bool operator < (const Item& it2) {return name < it2.name;}
bool operator ==(const Item& t) {return ((name == t.name)&&(iid == t.iid)&&(value==t.value));}

bool operator == (const std::string& s) {return s == name;}
bool operator == (const int i) {return iid == i;}

};
bool com_by_iid(const Item& it1, const Item& it2) {return it1.iid < it2.iid;}
bool com_by_value(const Item& it1, const Item& it2) {return it1.value > it2.value;}
 



std::istream& operator >> (std::istream& ifs, Item& it) {

ifs >> it.name;
ifs >> it.iid;
ifs >> it.value;

return ifs;
}


std::ostream& operator << (std::ostream& ofs, const Item& it) {
	
	ofs << it.name << '\n' << it.iid << '\n' << it.value << '\n';
	
	return ofs;
	
}



int main ()
{
	std::string source;
	source = "D:\\data\\input.txt";
	
	std::ifstream ifs {source};
	
	std::istream_iterator<Item> ii {ifs};
	std::istream_iterator<Item> eos;
	std::list<Item>vi{ii,eos};
	
	vi.push_back(Item{"horse shoe",90,12.34});
	vi.push_back(Item{"Canon S400",9988,499.95});
	
	vi.sort();
	
	
	
	
	auto pos = std::find(vi.begin(),vi.end(),"clever");
	vi.erase(pos);
	pos = std::find(vi.begin(),vi.end(),"Canon S400");
	vi.erase(pos);
	pos = std::find(vi.begin(),vi.end(),322);
	vi.erase(pos);
	pos = std::find(vi.begin(),vi.end(),500);
	vi.erase(pos);
	
	for (auto a : vi)
		std::cout <<a << '\n';
	
	char c;
	std::cin >> c;
}