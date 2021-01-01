#include <iostream>
#include <list>
#include <map>
#include <vector>

template <typename InputIterator, typename T>
int mycount(InputIterator first, InputIterator last, const T& value) {
	int number_of_count = 0;
	
	for (;first != last; ++first) 
		if (*first == value) ++number_of_count;
	return number_of_count;
	}



int main() {
std::vector<int> vi{1,2,3,4,9,9,5,6,7,8,9,1,1,1,1,9};
std::list<double> ld {0.0,0.5,0.5,0.86,124.23};


std::cout << mycount(vi.begin(),vi.end(),9) << '\n';
std::cout << mycount(vi.begin(),vi.end(),1) << '\n';
std::cout << mycount(ld.begin(),ld.end(),0.5) << '\n';

char c;
std:: cin >>c;
}