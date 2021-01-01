#include <iostream>
#include <numeric>
#include <vector>



struct Record {

double unit_price = 0.0;

int unit = 0;

Record(const double& up, const int u) : unit_price{up}, unit{u} {}

};


double price(const double& up, const Record& r) {
	return up + r.unit_price * r.unit;
}


int main() {
	
	std::vector<Record>vr;
	vr.push_back(Record{200,150});
	vr.push_back(Record{300,100});
	vr.push_back(Record{250,2000});
	vr.push_back(Record{1000,150});
	vr.push_back(Record{120,25});
	
	double total_price = 0.0;
	
	total_price = std::accumulate(vr.begin(),vr.end(),0.0,price);
	
	std::cout << total_price << '\n';




char c;
std::cin >> c;
}