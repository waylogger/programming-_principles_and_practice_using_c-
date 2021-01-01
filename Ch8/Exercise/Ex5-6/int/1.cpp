#include <std_lib_facilities.h>



void recurs (vector<int>v1, vector<int>v2) {
	int a = 0;
	for (int i = 1; i<=v1.size();++i) {
	a = v1[v1.size()-i];
	v2.push_back(a);
	}
	for (int i = 0; i<v2.size();++i)
		cout << v2[i] << ' ';
	

}	


void true_recurs (vector<int>v1) {
	int i =0;
	while (i<v1.size()/2) {	
		
	int a =v1[0+i];
	int b =v1[v1.size()-1-i];
	
	swap(a,b);
	v1[0+i]=a;
	v1[v1.size()-1-i]=b;
	++i;
	
	}
	for (int i = 0; i<v1.size();++i)
		cout << v1[i] << '\n';
}



int main ()
try{
	
vector<int>v1 {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
vector<int>v2;
//recurs(v1,v2);
true_recurs(v1);	
keep_window_open();
}

catch (exception& e) {
	cerr << e.what() << '\n';
	keep_window_open();
}
