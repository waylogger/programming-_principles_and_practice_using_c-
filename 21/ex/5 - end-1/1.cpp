
#include <string>
#include <vector>
#include <iostream>


template <typename ForwardIterator, typename T>
bool my_find(ForwardIterator first, ForwardIterator last, ForwardIterator& result, const T& val) {

while (true) {
		if (*first == val) {
			result = first;
			return true;
		}
		++first;
		
		if (first == last) {
			if (*last == val) {
				result = last;
				return true;
			}
		break;
		}
	
	}
	return false;
	
}

template <typename it, typename T>
It find(it first, it last, const T& val) {
	for (;first != last; ++first)
		if (*first == val) return first;
	return last;
}




template <typename InputIterator, typename T>
int my_count(InputIterator first, InputIterator last, const T& val){
	int count = 0;
	
while (true){
		if (*first == val) ++count;
		++first;
		if (first == last) {
		if (*last == val) ++count;
		break;
		}
	}
	return count;
	
}



int main () {
std::vector<int>vi{1,23,123,124,5,234,123,53213,6245,1232,52,6345,124,326534,53213};
auto res = vi.begin();
auto p = my_find(vi.begin(),vi.end()-1,res,6245);

if (p) std::cout << *res << '\n';





char c;
std::cin >> c;
}