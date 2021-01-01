#include <Matrix\\Matrix.h>
#include <iostream>

using Numeric_lib::Matrix;
using namespace std;


int main(){
	Matrix<int,2> m (2,3);
	
	int k1 = 0;
	int k2 = 0;
	
	for (int i = 0; i < 5; ++i){
		int r = 0;
		cin >> r;
		
	if (k2 >= m.dim2()){
		k2 = 0;
		++k1;
		}	
		
	m[k1][k2] = r;
	++k2;
	}
	
	for (int i =0 ; i < m.dim1(); ++i){
		for (int j = 0; j < m.dim2(); ++j)
			cout << m[i][j] << '\t';
	cout << '\n';	
	}
		
	
	
	char end;
	cin >> end;
}