#include <iostream>
#include <chrono>

using namespace std;


struct Ambush{
	int* amb;
	explicit Ambush(int n) : amb{new int[n]}{}

	int size() {return time(0);}
};

int main(){
	
	Ambush s {51};
	for (int i =0; i < s.size(); ++i){
	Ambush ss{i};	
		
	}
	
	
}