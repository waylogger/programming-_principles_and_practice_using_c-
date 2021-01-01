#include <iostream>
#include <Matrix\\Matrix.h>

using Numeric_lib::Matrix;
using namespace std;


int main(){
	
	Matrix<int>a	(10);
	Matrix<int>b	(20);
	Matrix<double>c	(10);
	Matrix<int,2>d	(10,10);
	Matrix<int,3>e	(10,10,10);
	
	cout << "Size of matrix of integer number, with dimension - 1 and " << a.size() << " elem is "
	<< sizeof(a) << " of bytes\n";  
	cout << "Size of matrix of integer number, with dimension - 1 and " << b.size() << " elem is "	
	<< sizeof(b) << " of bytes\n";
	cout << "Size of matrix of double number, with dimension - 1 and " << c.size() << " elem is "	
	<< sizeof(c) << " of bytes\n";
	cout << "Size of matrix of integer number, with dimension - 2 and " << d.size() << " elem is "	
	<< sizeof(d) << " of bytes\n";
	cout << "Size of matrix of integer number, with dimension - 3 and " << e.size() << " elem is "	
	<< sizeof(e) << " of bytes\n";
	
	char qc;
	cin >> qc;
}