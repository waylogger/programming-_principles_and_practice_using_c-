#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <numeric>
#include <algorithm>


std::ostream& operator << (std::ostream& ost, const std::pair<double,int>& p) {
	
	ost << "Key - " << p.first << ". Value - " << p.second << '\n';
	return ost;
}

struct midle_check {
double m = 0.0;
midle_check(const double& d) : m{d} {}

bool operator()(const double& mm) { return mm<m;}
 
};


void copy(const std::vector<double>& vd, std::vector<double>& vd1, const double& midle) {

	for (auto p = vd.begin(); p != vd.end(); ++p)
		if (*p < midle) vd1.push_back(*p);
}

int main() {
	
	std::string source;
	source = "D:\\data\\input.txt";
	
	std::ifstream ifs{source};
	std::istream_iterator<double>ii{ifs};
	std::istream_iterator<double>eos;
	
	std::vector<double> vd{ii,eos};
	
	std::vector<int>vi(vd.size());
	
	std::copy(vd.begin(),vd.end(),vi.begin());
	
	double sum_vd = std::accumulate(vd.begin(),vd.end(),0.0);
	int sum_vi = std::accumulate(vi.begin(),vi.end(),0);

	double midle = sum_vd/vd.size();
	
	std::vector<double>vd2;
	
	
	
	
	copy(vd,vd2,midle);
	
	std::sort(vd2.begin(),vd2.end());
	
	for (auto p : vd2)
		std::cout << p << '\n';
	
	
	char c;
	std::cin >>c;
}