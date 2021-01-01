#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>



template <typename InputIterator, typename UnPred>
int mycount_if(InputIterator first, InputIterator last, UnPred pred) {
	
	int count = 0;
	
	for (;first != last; ++first)
		if (pred(*first)) ++count;
	return count;
 

}

bool more_then_five(const std::pair<int,std::string>& p) {
if (p.second.size() > 5) return true;
return false;
}

int main () {
	
	std::map<int,std::string>mis;
	mis[413] = "cross";
	mis[42] = "stanly";
	mis[123] = "bradly";
	mis[41123] = "kolin";
	mis[5223] = "ishtar";
	mis[455123] = "drones";
	mis[415123] = "cross";
	
	std::cout << mycount_if(mis.begin(),mis.end(),more_then_five);
	
	
	char c;
	std::cin >>c;
	
}














