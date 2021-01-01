/*
Antonyuk I.V.
01/05/2018

PPP C++ B.Stroustrup

ex. 26.5
*/


#include <		iostream	>
#include <		MY\\test.h	>


using namespace std;

template <typename T>
void test(const vector<T>& v1){
	
	MY::binary_search(v1.begin(),v1.end(),2);
	
	
}



int main(){
	
	
	vector<int> v1 = {1,2,3,4,5,6};
	
	test(v1);
	
	
	char end;
	cin >> end;
}