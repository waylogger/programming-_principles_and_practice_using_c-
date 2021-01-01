/*
Antonyk I.V.

05.04.18-17.04.18
Classicali gauss elimination with arrays


PPP C++
24.7

*/


#include <iostream>
#include <string>
#include <vector>
#include <Matrix\\matrix.h>
#include <Matrix\\matrixio.h>
#include <ctime>
#include <functional>
using namespace std;


// -----------typedef block---------------------
typedef double** Matrix;
typedef double* Vector;
// -----------end of typedef block---------------------


//make matrix by array
//-------------------------------------------------------------------------



template <typename A,typename B>
A* row_arr(A a, const int dim1, const int dim2){
	A* rows = new A[dim1];
	
	for (int i = 0; i < dim1; ++i){
		rows[i] = new B[dim2];
	}
	
	for (int i =0; i < dim1; ++i)
		for (int j = 0; j < dim2; ++j)
			(rows[i])[j] = a[i*dim2+j];
	
	return rows;
}


//-------------------------------------------------------------------------



//binding function with types
function<double**(double*,const int,const int)> by_rows = row_arr<double*,double>;

//-------------------------------------------------------------------------

//--------------------printing block----------------------------------------
template <typename T>
void print(T* t, const int dim1, const int dim2){
	for (int i =0; i < dim1; ++i){
		for (int j = 0; j < dim2; ++j){
		cout << t[i*dim2+j] << '\t';	
		}
		cout << '\n';
	}
}

template <typename T>
void print(T* t, const int dim1){
		
		for (int i = 0; i < dim1; ++i)
			cout << t[i] << '\t';
	
}


template <typename T>
void print(T** t, const int dim1, const int dim2){
	for (int i =0; i < dim1;++i){
		for (int j = 0; j < dim2; ++j){
			cout << (t[i])[j] << '\t';
		}
		cout << '\n';
	}
	
}
//--------------------end of printing block----------------------------------------


// 
//------------------------------------------------------------------------
template <typename T, typename C>
void scale_and_add(T a, T b, C c, const int m){
	for (int i =0; i < m; ++i){
		b[i] = a[i]*c+b[i];
	}
}
//------------------------------------------------------------------------

template <typename T>
void swap_rows(T* a, T* b, const int dim){
	T* c = new T[dim];
	for (int i =0; i < dim; ++i)
		c[i] = a[i];
	for (int i =0; i < dim; ++i)
		a[i] = b[i];
	for (int i =0; i < dim; ++i)
		b[i] = c[i];
	delete[] c;
	
	
}


//------------------------------------------------------------------------


//------------------------------------------------------------------------
//first step
void elimination(Matrix a, Vector b, const int dim){
	
	for (int j = 0 ; j < dim; ++j){
	
	// find a largest pivot
	int pivot_row = j;
	for (int k = j+1; k < dim; ++k)
		if (abs((a[k])[j]) > abs((a[pivot_row])[j])) {
			pivot_row = k;
		}
		
	//swaping	
	if (pivot_row != j){	
		swap_rows(a[j],a[pivot_row],dim);
		std::swap(b[j],b[pivot_row]);
		
	}
	//elimination	
	for (int i = j+1; i < dim; ++i){
		double pivot = (a[j])[j];
		double mult = (a[i])[j] / pivot;
		scale_and_add(a[j],a[i],-mult,dim);
		b[i] -= b[j]*mult;
		}
	}
		
}


//---------------------------------------------------------------


double dot_product(Vector v1, Vector v2, const int dim){
	double d = 0;
	for (int i = 0; i < dim; ++i){
		d += v1[i]*v2[i];
	}
	return d;
}

//---------------------------------------------------------------

Vector back_step(Matrix a, Vector v, const int dim){
	Vector x = new double[dim];
	
	for (int i = 0; i < dim; ++i){
		x[i] = 0;
	}
		
	for (int j = dim-1, inx = 0; j >= 0; --j,++inx){
		double pivot = (a[j])[j];
		double s = dot_product(&(a[j])[j+1],&x[j+1],dim-(j+1));
		double val = v[j] - s;
		x[j] = val/pivot;
	}
		
	return x;
}

//---------------------------------------------------------------

Vector classical_gauss_elimination(Matrix a, Vector b, const int dim){
	elimination(a,b,dim);
	return back_step(a,b,dim);
}


//---------------------------------------------------------------



vector<double> uses_of_gauss(double* elem, double* vec, const double dim){
	
	Matrix mat = by_rows(elem,dim,dim);
	Vector res = classical_gauss_elimination(mat,vec,dim);
	vector<double>ret;
	for (int i =0; i < dim; ++i)
		ret.push_back(res[i]);	
	
	
	//--------------------------delete block-------------------------------------
	delete[] res;
	for (int i = 0; i < dim; ++i){
		delete[] mat[i];
	}
	delete[] mat;
	delete[] elem;
	delete[] vec;
	//--------------------------end of delete block-------------------------------------
	return ret;
	
}

//--------------------------------------testing block-------------------------------------

double* rand_sqd_mat(const int dim){
	int n = dim*dim;
	double* d = new double[n];
	for (int i =0; i < n;++i)
		d[i] = rand()%50;
	return d;
}

//---------------------------------------------------------------------------------------------

double* rand_vect(const int i){
	double* d = new double[i];
	for (int k =0; k < i; ++k){
		d[k] = rand()%50;
	}
	return d;
}

//---------------------------------------------------------------------------------------------

vector<double> f(const int n){
	return uses_of_gauss(rand_sqd_mat(n),rand_vect(n),n);;
}


//--------------------------------------end of testing block-------------------------------------

