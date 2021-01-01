/*
Antonuk I.V.
23/04/2018 
N.Novgorod

Vector with pool
PPP C++ 25.14 B.Stroustrup

Финальная жутко упрощенная версия вектора, использующего пул

Пул хранит значения ячеек в поле bitset

*/


#include <iostream>
#include <chrono>
#include <bitset>
#include <map>
#include <vector>


using namespace std;


template <typename T, int N>
struct Pool{
	T* elem;
	bitset<N> log; //журнал, 1 - используется, 0 - не используется
	int space = N;
	int last_elem = 0;
	Pool(): elem {new T[N]}, log{0} {}
	
	T* get();
	void free(T*);
	
};


template <typename T, int N>
T* Pool<T,N>::get(){
	
	
	for (int i =N-1, j = 0; i >= 0; --i, ++j){ //сложная конструкция цикла из-за обратной индексации bitset
		if (log[i] == 0){
			log[i] = 1;
			--space;
			return &elem[j];
		}
	}
	
	return nullptr;
	
}


template <typename T, int N>
void Pool<T,N>::free(T* addr){
	if (!addr){
		cout << "Try to release nullptr\n";
		return;
	}
	if (addr < &elem[0] || addr > &elem[N-1]){
		cout << "Address do not belong to pool\n";
		return;
	}
	int inx = addr-&elem[0];
	
	elem[inx] = T();
	log[(N-1)-inx] = 0;
	
}



template <typename T, int N>
struct my_vector{
	
	Pool<T,N> arr_pool; //вектор единоличный владелец пула
	T* elem;
	int sz;
	my_vector(int i = 0) : sz{i}, elem{arr_pool.get()} { //все что необходимо это перевести указатель вектора на первый элемент пула
		for (int i =0; i < sz; ++i)
			elem[i] = 0;
	} 
	
	
	void push_back(const T& t) {elem[sz] = t; ++sz;}
	int size() const {return sz;}
	int axillary() {return N-sz;} 
	
	
	T operator[](const int n) {return elem[n];}
};


void mf(){ // благодаря тому, что вся память выделяется при компиляции, время вставки нового элемента существенно возрастает
			//из-за отсутствия необходимости вызывать new
	constexpr int N = 100000;
	auto t1 = chrono::system_clock::now();
	my_vector<int,N>v;
	for (int i = 0; i < N; ++i)
	v.push_back(i*10);
	auto t2 = chrono::system_clock::now();
	
	cout << "My_vec with 1000 elem, res: ";
	cout << chrono::duration_cast<chrono::milliseconds>(t2-t1).count() << '\n';
}

void stdf(){
	auto t1 = chrono::system_clock::now();
	vector<int>v;
	for (int i = 0; i < 100000; ++i)
	v.push_back(i*10);
	auto t2 = chrono::system_clock::now();
	
	cout << "STD_vec with 1000 elem, res: ";
	cout << chrono::duration_cast<chrono::milliseconds>(t2-t1).count() << '\n';
}





int main(){
	mf();
	stdf();
	
	
	char end;
	cin >> end;


	
}