#include <iostream>
#include <chrono>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <C:\\Programms\\25\\ex\\14 - vector_pool\\pool.h>


using namespace std;



int without_del(const int& N){

auto t1 = chrono::system_clock::now();
char** common_data = new char*[N];
const int S = rand()%1000;

for (int i =0; i < N; ++i){
	common_data[i] = new char[S];

}
auto t2 = chrono::system_clock::now();

return chrono::duration_cast<chrono::milliseconds>(t2-t1).count();
}

int with_del_back_order(const int& N){

auto t1 = chrono::system_clock::now();
char** common_data = new char*[N];

for (int i =0; i < N; ++i){
	common_data[i] = new char[rand()%1000];
	*common_data[i] = '0';
}
auto t2 = chrono::system_clock::now();

for (int i = N-1; i >=0; --i){
	delete[] common_data[i];
}

delete [] common_data;

return chrono::duration_cast<chrono::milliseconds>(t2-t1).count();
}



vector<int> rand_sec(int n = 0){
	vector<int>ind;
while (ind.size() < n){
	bool sw = false;
	int r = rand()%n;
	for (int k = 0; k < ind.size(); ++k){
		if (ind[k] == r) sw = true;
	}
	
	if (!sw) 
		ind.push_back(r);
}
	return ind;
}


int with_del_rand_order(vector<int>& r1, const int& N){

auto t1 = chrono::system_clock::now();
char** common_data = new char*[N];

for (int i =0; i < N; ++i){
	common_data[i] = new char[rand()%1000];
}
auto t2 = chrono::system_clock::now();


for (int i = 0; i < r1.size(); ++i){
	delete[] common_data[r1[i]];
}

delete [] common_data;

return chrono::duration_cast<chrono::milliseconds>(t2-t1).count();
}

template <typename T>
int see(const T&t){
	int a = sizeof(T);
	cout << a << " : bytes" << '\n';
	return a;
}

int again_with_pool_back_order(){
	constexpr int N = 10000;
	constexpr int S = 500;
	
	Pool<char*[S],N> arr;
	Pool<char,N*S>carr;
	auto t1 = chrono::system_clock::now();
	char*(*pool_arr1[N])[S];
	
	for (int i =0; i < N; ++i){
		pool_arr1[i] = arr.get();
		for (int j = 0; j < S; ++j){
			(*pool_arr1[i])[j] = carr.get();
			*(*pool_arr1[i])[j] = '0';
		}
	}

	for (int i = 0; i < N; ++i){
		for (int j = 0; j < S; ++j){
			char* p = (*pool_arr1[i])[j];
			carr.free(p);
		}
	}	
	for (int i = N-1; i >= 0; --i){
		char* (*p)[S] = pool_arr1[i];
		arr.free(p);
	}
	auto t2 = chrono::system_clock::now();
	return chrono::duration_cast<chrono::milliseconds>(t2-t1).count();
	
}


int again_with_pool_rand_order(vector<int>& r1){
	
	
	constexpr int N = 10000;
	constexpr int S = 500;
	
	Pool<char*[S],N> arr;
	Pool<char,N*S>carr;
	auto t1 = chrono::system_clock::now();
	char*(*pool_arr1[N])[S];
	
	for (int i =0; i < N; ++i){
		pool_arr1[i] = arr.get();
		for (int j = 0; j < S; ++j){
			(*pool_arr1[i])[j] = carr.get();
			*(*pool_arr1[i])[j] = '0';
		}
	}

	for (int i = 0; i < N; ++i){
		for (int j = 0; j < S; ++j){
			char* p = (*pool_arr1[i])[j];
			carr.free(p);
		}
	}	
	for (int i = 0; i < r1.size(); ++i){
		char* (*p)[S] = pool_arr1[r1[i]];
		arr.free(p);
	}
	auto t2 = chrono::system_clock::now();
	return chrono::duration_cast<chrono::milliseconds>(t2-t1).count();
	
}
void test1(){
	map<int,int>m;

for (int i =0; i < 100; ++i){
	++m[without_del(10000)];
}

for (const auto& q : m)
	cout << q.first << '\t' << q.second << '\n';
	
}

void test2(){
	
	map<int,int>m;

for (int i =0; i < 100; ++i){
	++m[with_del_back_order(10000)];
}

for (const auto& q : m)
	cout << q.first << '\t' << q.second << '\n';
	
	
	
}


void test3(){
	
	map<int,int>m;
	vector<int> r = rand_sec();

for (int i =0; i < 100; ++i){
	++m[with_del_rand_order(r,10000)];
}

for (const auto& q : m)
	cout << q.first << '\t' << q.second << '\n';
	
	
	
}

void test4(){
	
	map<int,int>m;
	vector<int> r = rand_sec();

for (int i =0; i < 3; ++i){
	++m[again_with_pool_back_order()];
}

for (const auto& q : m)
	cout << q.first << '\t' << q.second << '\n';
	
	
	
}


void test5(){
	
	map<int,int>m;
	vector<int> r = rand_sec(500);

for (int i =0; i < 3; ++i){
	++m[again_with_pool_rand_order(r)];
}

for (const auto& q : m)
	cout << q.first << '\t' << q.second << '\n';
	
	
	
}


int main(){
	
	
	
	
	
	
	
	
	
	

char c;
cin >> c;
	
}