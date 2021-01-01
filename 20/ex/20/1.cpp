#include <My\\my_list.h>
#include <My\\my_vector.h>
#include <chrono>
#include <vector>
#include <list>


template <typename T>
void sorted_insert(const int a,T& v) {
	 
	if (v.begin() == v.end()) {
			v.insert(v.begin(),a);
			return;
		}
	
	
	for (auto b = v.begin(); b != v.end(); ++b) 
		if (*b > a) {
				v.insert(b,a);
				return;
			}
		 
	
	v.insert(v.end(),a);
		
		 
	 
 }
 
 void sorted_insert_list(const int a,std::list<int>& v) {
auto place = v.begin();

if (v.begin() == v.end())
	
for (auto pos = v.begin(); pos != v.end(); ++pos) {
	if (*pos >= *place) place = pos;

}	

v.insert(place,a);
	 
 }
 


void do_something_with_vector(int n) {

	std::vector<int>q;
	for (int i = 0; i < n; ++i) {
		sorted_insert<std::vector<int>>(rand()%1000,q);
	}

	
}

void do_something_with_list(int n) {

	std::list<int>q;
	for (int i = 0; i < n; ++i) {
		sorted_insert<std::list<int>>(rand()%1000,q);
	}

}


__int64 time_of_work_vector (int n) {
	
	int num = 50;
	auto t1 = std::chrono::system_clock::now();
//	for (int i =0; i < num; ++i)
		do_something_with_vector(n);
	auto t2 = std::chrono::system_clock::now();
	return std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
		
	
}

__int64 time_of_work_list (int n) {
	
	int num = 50;
	auto t1 = std::chrono::system_clock::now();
	//for (int i =0; i < num; ++i) {
		do_something_with_list(n);
	//}
	auto t2 = std::chrono::system_clock::now();
	return std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
		
	
}


struct result {
	int numbers = 0;
	__int64 result_of_vector = 0;
	__int64 result_of_list = 0;
	result(int n, __int64 v, __int64 l) : numbers{n},  result_of_vector{v}, result_of_list{l} {}
};

std::ostream& operator << (std::ostream& ofs, const result& res) {
	


std::cout << "With - " << res.numbers << " - of random numbers\n"
			<< "List" << "|" << "Vector" << '\n'
			<< res.result_of_list << '|' << res.result_of_vector << '\n';
			if (res.result_of_list < res.result_of_vector)
				std::cout << "Winner is list\n";
			else if (res.result_of_list > res.result_of_vector)
				std::cout << "Winner is vector\n";
			else if (res.result_of_list == res.result_of_vector)
				std::cout << "Winner is friendship\n";

return ofs;
}

int main() {
std::vector<result> results; 

//for (int i =0; i < 10000; ++i ) {
int n = 50000;
__int64 vec = time_of_work_vector(n);
__int64 lis = time_of_work_list(n);
std::cout << result{n,vec,lis} << '\n';
//}




	char c;
	std::cin >>c;
}