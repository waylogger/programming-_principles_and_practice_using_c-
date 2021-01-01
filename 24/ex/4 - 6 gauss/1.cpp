/*

Antonyk I.V. 22/03/2018
PPP C++ ex.24.4

*/

#include <iostream>
#include <Matrix\\Matrix.h>
#include <Matrix\\Matrixio.h>
#include <string>
#include <random>
using namespace std;
using Numeric_lib::Index;
using Numeric_lib::scale_and_add;

typedef Numeric_lib::Matrix<double,2> Matrix;
typedef Numeric_lib::Matrix<double,1> Vector;


Vector operator* (const Matrix& m, const Vector& u){
	const Index n = m.dim1();
	Vector v(n);
	
	for (Index i =0; i < n; ++i){
		v(i) = dot_product(m[i],u);
	}
	
	return v;
}

struct Elim_failure{
	Elim_failure(Index n) {}
};

struct Back_subst_failure{
	Back_subst_failure(Index n) {}
};

void error(const std::string& s){};

void classical_elimination(Matrix& A, Vector& b);
Vector back_substitution(const Matrix& A, const Vector& b);



void elim_with_parial_pivot(Matrix& A, Vector&b){
	const Index n = A.dim1();
	for (Index j = 0; j < n-1; ++j){
		
		Index pivot_row = j;
		//Поиск подходящего опорного элемента
		for (Index k = j+1; k < n; ++k){
			if (abs(A(k,j)) > abs(A(pivot_row,j))) pivot_row = k;
		}
		//Обмен строк для лучшего опорного элемента
		if (pivot_row != j){
			A.swap_rows(j,pivot_row);
			std::swap(b(j),b(pivot_row));
		}
		//Исключение
		for (Index i = j+1; i<n; ++i){
			const double pivot = A(j,j);
			if (pivot == 0)
				error("решения нет, нулевой опорный элемент");
			const double mult = A(i,j)/pivot;
			auto f = A[j].slice(j);
			auto s = A[i].slice(j);
			auto res = A[i].slice(j);
			double k = -mult;
			for (int i =0; i < f.size(); ++i)
				res[i] = f[i]*k+s[i];
			//A[i].slice(j) = scale_and_add(A[j].slice(j),-mult,A[i].slice(j));
			b(i) -= mult*b(j);
		}
	}
}
Vector classical_gaussian_elimination(Matrix A, Vector b){
	//classical_elimination(A,b);
		elim_with_parial_pivot(A,b);
	return back_substitution(A,b);
}
void classical_elimination(Matrix& A, Vector& b){
	const Index n = A.dim1();
	for (Index j =0; j < n-1; ++j){
		const double pivot = A(j,j);
		if (pivot == 0)
			throw Elim_failure(j);
		for (Index i = j+1; i < n; ++i){ // начинием со следующей строки
			const double mult = A(i,j) / pivot; // вычисление коэффициента как отношение исключаемого элемента к опорному 
			A[i].slice(j) = scale_and_add(A[j].slice(j),-mult,A[i].slice(j));//умножаем первый арг на коэффициент и прибавляем к соответствующему элементу второго аргумента
			
			
			
			b(i) -= mult * b(j); //прибавляем к правому элементу правой части строки произведение правого эл-та предыдушей строки
			// и коэффициента
		}
		
	}
	
}

Vector back_substitution(const Matrix& a, const Vector& B){
	Matrix A = a;
	Vector b = B;
	const Index n = A.dim1();
	Vector x(n);
	for (Index i = n-1; i >=0; --i){ //обратный шаг естественно с последней строки
		double dp = dot_product(A[i].slice(i+1),x.slice(i+1));
		cout << b << '\n';
		double s = b(i) - dp;
		cout << s << '\n';
		//разница между текущим элементом правой части уравнения 
		//и суммой всех произведений уже вычесленных элементов 
		if (double m = A(i,i))
			x(i) = s/m;	
				
	}	
	return x;
}


Vector random_vector(Index n){
	Vector v(n);
	double max = 956;
	default_random_engine ran{};
	uniform_real_distribution<> ureal{0,max};
	
	for (Index i = 0; i < n; ++i){
		v(i) = ureal(ran);
	}
	return v;
}
Matrix random_matrix(Index n){
	Matrix m(n,n);
	
	double max = 956;
	default_random_engine ran{};
	uniform_real_distribution<> ureal{0,max};
	
	
	Index i = m.dim1();
	Index j = m.dim2();
	
	
	for (Index k = 0; k < i; ++k){
		for (Index n = 0; n < j; ++n){
			m(k,n) = ureal(ran);
		}
	}
	
	return m;
}
void solve_random_system(Index n){
	Matrix A = random_matrix(n);
	Vector b = random_vector(n);
	
	
	cout << "A = " << A << '\n';
	cout << "b = " << b << '\n';
	try{
		Vector x = classical_gaussian_elimination(A,b);
		cout << "Gausses solution: x = " << x << '\n';
		Vector v = A * x;
		cout << " A * x = " << v << '\n';
		
	}
	catch(const exception& e){
		cerr << e.what() << '\n';
	};
	
}


int main(){
	
	Matrix m {3,3};
	m(0,0) = 2;
	m(0,1) = 1;
	m(0,2) = 1;
	
	m(1,0) = 1;
	m(1,1) = -1;
	m(1,2)  = 0;
	
	m(2,0) = 3;
	m(2,1) = -1;
	m(2,2) = 2;
	
		
	Vector v {3};
	v(0) = 2;
	v(1) = -2;
	v(2) = 2;
	classical_gaussian_elimination(m,v);
	
	
	
	char end;
	cin >>end;
}