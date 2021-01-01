/*
Antonyuk I.V. 18.03.2018

ex. 3 PPP C++ 


template <typename A, typename F>
A apply(A(const A&), F(F&)){
}
*/

#include <iostream>
#include <Matrix\\Matrix.h>
#include <functional>

using std::placeholders::_1;
using namespace std;
using Numeric_lib::Matrix;

//-------------------------------------------------


//-------------------------------------------------

template <typename A, typename F>
A apply( A a ( const A& ), void f ( F& ) ){
	A mat = a(glob_mat);
	for ( int i = 0; i < mat.size(); ++i ){
		f(mat.data()[i]);
	}
	return mat;
}

//-------------------------------------------------



template <typename Ret,typename A, typename F>
Ret mapply( A* a, F* f ){
	Ret mat = (*a)();
	for ( int i = 0; i < mat.size(); ++i ){
		(*f)(mat.data()[i]);
	}
	return mat;
}




//-------------------------------------------------

int global_index = 0;
Matrix<int,1>glob_matrix(1);
void triple(int& i){

	// np = KE + p
	//-------------------------------------------------
	if (global_index > glob_matrix.size()){
		++global_index;
		return;
	}
	//-------------------------------------------------
	int* first = &i - global_index;
	//-------------------------------------------------
	int* addr1 = first + (glob_matrix.size() +global_index);
	int* addr2 = first + (2 * glob_matrix.size() + global_index);
	//-------------------------------------------------
	*addr1 = i;
	*addr2 = i;
	//-------------------------------------------------
	++global_index;
}

//-------------------------------------------------

struct Triple{
	int limit = 0;
	int index = 0;
	Triple(const int lim) : limit{lim}{}
	
	void operator()(int& i){
		// np = KE + p
	//-------------------------------------------------
	if (index > limit){
		//++index;
		return;
	}
	//-------------------------------------------------
	int* first = &i - index;
	//-------------------------------------------------
	int* addr1 = first + (limit +index);
	int* addr2 = first + (2 * limit + index);
	//-------------------------------------------------
	*addr1 = i;
	*addr2 = i;
	//-------------------------------------------------
	++index;
	
	}
	
	
	
};

Matrix<int,1> get_m ( const Matrix<int,1>& a ) {
	Matrix<int, 1> nm (a.size()*3);
	for ( int i = 0; i < a.size(); ++i ){
		nm[i] = a[i];
	}	
	return nm;
}

//-------------------------------------------------

int main(){


		

	char end;
	cin >> end;
}
