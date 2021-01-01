/*
Antonuyk I.V.
08/04/18
PPP C++

ex. 24.12
*/


#include <Matrix\\Matrix.h>
#include <Matrix\\Matrixio.h>
#include <iostream>
#include <std_lib_facilities.h>
using Numeric_lib::Matrix;

using namespace std;


Matrix<double,2> operator* (Matrix<double,2>& a, Matrix<double>&b)
{
	int dim1 = a.dim1();
	int dim2 = a.dim2();
	int sz_b = b.size();
	Matrix<double,2> c (dim1,b.size());
	if (dim2 > 1){
		cout << "ERROR\n";
		return c;
	}
	int c1 = c.dim1();
	int c2 = c.dim2();
	for (int i =0; i < c1; ++i)
		for (int j = 0; j < c2; ++j){
			
			c(i,j) = a(i,0)*b(j);
		}
	
	
	return c;
}

template <int N>
Matrix<double,N> operator+(Matrix<double,N>& a, Matrix<double,N>& b){
	Matrix<double,N>c = a;
	
	if (a.size() != b.size()){
		cout << "Error\n";
		return c;
	}
	
	double* d1 = a.data();
	double* d2 = b.data();
	double* res = c.data();
	
	int max = a.size();
	for (int i =0; i < max;++i){
		res[i] = d1[i] + d2[i];
	}
	
	return c;
}



int main(){
	/*while (true){ // mult
	int x = 0;
	cout << "Insert size\n";
	cin >> x;
	
	srand(time(NULL));
	Matrix<double,2> a (x,1);
	int d1 = a.dim1();
	int d2 = a.dim2();
	
	for (int i =0; i < d1; ++i)
		for (int j =0; j < d2; ++j)
			a(i,j) = rand()%20;
		
		
	
	Matrix<double> b(x);
	int sz = b.size();
	for (int i =0; i < sz; ++i)
		b[i] = rand()%20;
	
	auto res = a*b;
	cout << a << '\n';
	cout << b << '\n';
	cout << res << '\n';
	
	}
	*/
	
	int sz = 5;
	srand(time(NULL));
	Matrix<double,2>a(sz,sz);
	for (int i =0; i < sz; ++i){
		for (int j = 0; j < sz; ++j)
			a(i,j) = rand()%50;
	}
	Matrix<double,2>b(sz,sz);
	for (int i =0; i < sz; ++i){
		for (int j = 0; j < sz; ++j)
			b(i,j) = rand()%50;
	}
	
	cout << a << '\n' << b << "\n\n" << a+b << '\n';
	
	
	char c;
	cin >> c;
	
}

