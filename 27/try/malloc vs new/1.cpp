#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <map>


using namespace std;


void mall(const int num){
	
	
	void* m = malloc(sizeof(char)*num);
	free(m);	
	
	
}


void tnew(const int num){
	void* m = new(char[num]);
	delete[] m;	
}

int main(){
	map<int,int>res;
	constexpr int num_of_tests = 500000;
	constexpr int mem_val = 1000000;
	
	for (int i = 0; i < num_of_tests; ++i) {
	auto t1 = chrono::system_clock::now();
	
	mall(mem_val);
	
	auto t2 = chrono::system_clock::now();
	tnew(mem_val);
	
	auto t3 = chrono::system_clock::now();
	
	int tm =  chrono::duration_cast<chrono::nanoseconds>(t2-t1).count();
	int tn =  chrono::duration_cast<chrono::nanoseconds>(t3-t2).count();
	
	res.insert(make_pair(tm,tn));
	
	}
	
	int count = 0;
	int sum_time_of_malloc = 0;
	int sum_time_of_new = 0;
	for (auto& a : res){
		sum_time_of_malloc 	+= a.first;
		sum_time_of_new		+= a.second;
		if (a.first > a.second) {++count;}
	}
	
	cout 	<< "In " << num_of_tests << " num of tests\n"
			<< "malloc and new to allocate " << mem_val << " pointers of char\n"
			<< "In " << count << " of cases malloc show best result\n"
			<< "In " << num_of_tests-count << " of cases new show best result\n";
			
	cout	<< "Midle time of malloc is " << sum_time_of_malloc/num_of_tests << '\n'
			<< "Midle time of new is " << sum_time_of_new/num_of_tests << '\n';
			
	cout 	<< "Q: " << (sum_time_of_malloc/num_of_tests) / (sum_time_of_new/num_of_tests) << '\n';
	

	char end;
	cin >> end;
}