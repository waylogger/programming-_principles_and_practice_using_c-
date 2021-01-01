#include <iostream>
#include <map>
#include <string>
#include <numeric>



double weighted_value
(
const std::pair<std::string,double>& a,
const std::pair<std::string,double>& b
)
{
	return a.second * b.second;
}

int main() {
	
	
	
std::map<std::string,double> dow_price = {
	{"MMM",86.81},
	{"AA",34.69},
	{"MO",54.45},
	{"KFC",55},
	{"MC",48},
	};
	
	
	std::map<std::string,double> dow_weight = {
	{"MMM",5.8849},
	{"AA",2.4808},
	{"MO",3.8940},
	{"KFC",1.13},
	{"MC",8.124},
	};
	
	std::map<std::string,std::string> dow_name = {
	{"MMM","3m Co."},
	{"AA","Alcoa Inc"},
	{"MO","Altria Group Inc."},
	{"KFC","Kentuky fry chicken"},
	{"MC","Macdonalds"},
	};
	
	double dji_index = 
	std::inner_product(
	dow_price.begin(),dow_price.end(),
	dow_weight.begin(),
	0.0,
	std::plus<double>(),
	weighted_value);
	
	std::cout << dji_index << '\n';
	
	
	
	
char c;

std::cin >> c;	
}