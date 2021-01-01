/*
Antonuyk I.V. 26/04/2018

N.Novgorod

PPP C++ 25.15
Tty to Stack

*/

#include <iostream>
#include <vector>
#include <chrono>
#include <map>
using namespace std;



template <int N>
class Stack{
	private:
	void** order; //log of used address
	char* mem;	
	int last_bit; 
	int last_note; //last note in log
	int sz;
	public:
	Stack();
	void* get(const int n);
	void free();
	int available() const {return N-sz;};
	int size() 		const {return sz;}
	template <typename T> T* cast(const int n); 
	
	
};

template <int N>
Stack<N>::Stack() : mem {new char[N]}, order{new void*[N]}, last_bit{0},last_note{-1}, sz{0} {

}
template <int N>
void* Stack<N>::get(const int n){
	if (available() < n){
		cout << "Stack is overflow\n";
		return nullptr;
	}
		
	char* ret = &mem[last_bit];
	void* cast_ret =  static_cast<void*>(ret);
	++last_note;	
	order[last_note] = cast_ret;
	
	sz += n;
	last_bit+=n;
	
	return cast_ret;
}

template <int N> template <typename T>
T* Stack<N>::cast(const int num){
	void* ret = get(num*sizeof(T));
	
	T* cast_ret = static_cast<T*>(ret);
	
	
	return cast_ret;
	
}


template <int N>
void Stack<N>::free(){
	//главная идея этой функции - вернуть стек в состоятние до последнего выделения памяти
if (sz == 0)
		return;
	
char* address_fb_last_note = static_cast<char*>(order[last_note]);

int size_of_last_elem = &mem[last_bit] - address_fb_last_note;

--last_note;
sz -= size_of_last_elem;
last_bit-=size_of_last_elem;

}


int f(){
	
	auto t1 = chrono::system_clock::now();
	constexpr int N = 10000;
	constexpr int S = 500;
	
	Stack<S*N> mw;
	Stack<N*sizeof(char*)> stack_of_pointers;
	
	
	char** arr = stack_of_pointers.cast<char*>(N);
	
	for (int i = 0; i < N; ++i){
		arr[i] = mw.cast<char>(S);
		for (int j =0; j < S; ++j){
			(arr[i])[j] = 'a';
		}
	}
	
	int smw =  mw.size();
	for (int i =0; i < smw; ++i){
		mw.free();
	}
	
	int ssp =  stack_of_pointers.size();
	for (int i =0; i < ssp; ++i){
		stack_of_pointers.free();
	}
	
	
	
	auto t2 = chrono::system_clock::now();
	
	return chrono::duration_cast<chrono::milliseconds>(t2-t1).count();
}



void test(){
	map<int,int> res;
	
	for (int i =0; i < 50; ++i){
		++res[f()];
	}
	
	for (const auto& q : res){
		cout << q.first << '\t' << q.second << '\n';
	}
	
	
}

int main(){
	
	cout << "For 10000 elem of 500b size obj Stack show next result\ntime\tcount\n";
	test();
	
	
	
	

char c;
cin >> c;
	
}