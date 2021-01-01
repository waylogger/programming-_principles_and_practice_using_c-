#include <iostream>
#include <set>
#include <string>


struct Fruit {
	std::string name;
	int count = 0;
	double unit_price = 0;
	
};

struct Fruit_comparation {
	bool operator()(const Fruit* a, const Fruit* b) {
		return a->name < b->name;
	}
};



int main () {
	
	std::set<Fruit*,Fruit_comparation>Fruits;
	Fruits.insert(new Fruit{"Orange",5,26.20});
	Fruits.insert(new Fruit{"Mango",146,50.20});
	Fruits.insert(new Fruit{"Apple",2000,14.99});
	Fruits.insert(new Fruit{"Kiwi",266,29.50});
	Fruits.insert(new Fruit{"Plum",28,14.50});
	Fruits.insert(new Fruit{"Quince",1,80.99});
	
	for (auto p : Fruits)
		std::cout << p->name << '\n';
	
	
	char c;
	std::cin >> c;
}