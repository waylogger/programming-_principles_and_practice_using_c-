/*
08/04/2018

Antonuyk I.V.
PPP C++

ex. 24.9
*/

#include <iostream>
#include <Matrix\\Matrix.h>
#include <Matrix\\Matrixio.h>
#include <functional>
#include <sstream>

using namespace std;

using Numeric_lib::Matrix;

//apply - функция преобразования типов двухмерных матриц
template < typename C, typename D, typename T, template <typename T,typename D> typename F>
Matrix<T,2> my_apply(F<T,D> f, C c){ //f - шаблонный функтор преобразования, где T - возвращаемый тип, С - исходная матрица
	
	int dim1 = c.dim1();
	int dim2 = c.dim2();
	Matrix<T,2> a (dim1,dim2);
	
	for (int i =0; i < dim1; ++i){
		for (int j =0; j < dim2; ++j)
			a(i,j) = f(c(i,j)); 
	}
	
	return a;
	
}

template <typename T,typename D>
struct Conv{ //простой функтор конвертации
	T d;
	Conv() {
		
	}
	T operator()(D dd){
		ostringstream ost;
		ost << dd;
		istringstream ist {ost.str()};
		ist >> d;	
		return d;
		}	
};


int main(){
	
	Matrix<char,2> b (2,2);
	
	for (int i =0; i < b.dim1(); ++i){
		for (int j = 0; j < b.dim2(); ++j)
			b(i,j) = '2';
	}
	
	Matrix<double,2> a = my_apply(Conv<double,char>{},b);
	
	for (int i =0; i < a.dim1(); ++i){
		for (int j = 0; j < a.dim2(); ++j)
			cout << a(i,j)+1;
	}
	
	
	char c;
	cin >> c;
}