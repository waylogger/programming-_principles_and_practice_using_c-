#include <iostream>
#include <vector>
#include <chrono>


__int64 time_to_work() {
	return 0;
}



template <typename It, typename T> 
It my_find(It first, It last, const T& val) {
	
	while (first != last && *first != val) ++first;
	return first;
	
}


template <typename It, typename T> 
It my_find_vol2(It first, It last, const T& val) {
	
	for (auto p = first; p != last; ++p)
		if (*p == val) return p;
	
	return last;
	
}


int main () {
	
	std::vector<int>v; 
	for (int i =0; i < 102; ++i)v.push_back(i);
	
		
	
	
	auto w = my_find_vol2(v.begin(),v.end(),61);
	
	
	std::cout << *w << '\n';
	char c;
	std::cin >>c;
}