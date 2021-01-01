#include <iostream>
#include <map>


using namespace std;



template <typename T, int N>
struct Pool{
	Pool() : elem {new Elem[N]} {
		
		
		}
	T* get();
	void free();
	int available() const {return space - sz;}
	
	struct Elem{
		T* addr = nullptr;
		bool status = false;
	};
	
	
	Elem* elem;
	int sz;
	int space = N;
	
};

int main(){
	
	Pool<int,5> p;
	
	
	char c;
	cin >> c;
}