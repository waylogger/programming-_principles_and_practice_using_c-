#include <complex>
#include <iostream>
#include <Matrix\\Matrix.h>


using Numeric_lib::Matrix;
using namespace std;


int main(){

Matrix<complex<double>>mcd(10);
for (int i =0; i < 10; ++i){
	complex<double> cd;
	cin >> cd;
	mcd[i] = cd;
}

for (int i =0; i < mcd.size(); ++i)
	cout << mcd[i] << '\t';



char end;
cin >> end;	
}