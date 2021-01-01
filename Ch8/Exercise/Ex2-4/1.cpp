#include <std_lib_facilities.h>



void print (string s, vector<double>ss) {
	
	for (int i =0; i<ss.size(); ++i)
		cout << ss[i] << '\n';
									 }

void fibonacci(int x, int y,vector<double>&v,int n) {

int i =2;
int c =0;
v.push_back(x);
v.push_back(y);

while (i<n){
	int a=v[i-1];
	int b=v[i-2];
	c=a+b;
	if (c<0) {cout << v[v.size()-1] << " - Biggest fibonaci val for double\n"; return;}
	v.push_back(c);
	++i;
			}
												}
int main () 
try {
	int x = 1;
	int y = 2;
	int n = 96100000;
	vector<double>v;
	fibonacci(x,y,v,n);
	print("", v);
	keep_window_open();
	}
catch (exception& e) {
	cerr << e.what () << '\n';
	keep_window_open();
}
