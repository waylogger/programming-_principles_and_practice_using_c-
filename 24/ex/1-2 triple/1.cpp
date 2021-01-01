/*
	file: triple.cpp
	Antonyk I.V. 16.03.2018
	ex. 24.1 PPP C++
	
	triple может принимать только один аргумент - T&
	
*/



#include <iostream>
#include <Matrix\\Matrix.h>
#include <string>
#include <algorithm>

using Numeric_lib::Matrix;
using namespace std;

//Global val
int* first_elem_of_matrix = nullptr;
int total_number_of_elem_of_matrix = 0;
//------------------------------


template <typename F>
void apply(F f, Matrix<int,1>& m){
	for (int i = 0; i < m.size(); ++i){
		f(m.data()[i]);
	}
}


struct Triple{
	void operator()(int& t){
	//необходимо получить адрес t
	//n = EK+p;
	int inx = &t - first_elem_of_matrix;
	if (inx >= total_number_of_elem_of_matrix)
		return;
	
	int* addr1 = first_elem_of_matrix + (total_number_of_elem_of_matrix  + inx);
	int* addr2 = first_elem_of_matrix + (total_number_of_elem_of_matrix * 2 + inx);
	*addr1 = t;
	*addr2 = t;
	}
	
};

Matrix<int,1> triple_matrix(const Matrix<int,1>& qs){
	// функция гарантирует, что в новой матрице поместиться три исходных
	Matrix<int, 1> tqs (qs.size()*3);
	for (int i =0; i < qs.size(); ++i){
		tqs[i] = qs[i];
	}
	
	return tqs;
}




int main()
{
	
	Matrix<int,1> qs (5);
	
	for (int i = 0; i < qs.size(); ++i)
		qs(i) = rand()%200;
	
	
	Matrix<int,1> trip_mat = triple_matrix(qs); //чтобы утроить матрицу нам нужно втрое больше памяти
		
	total_number_of_elem_of_matrix = qs.size();
	first_elem_of_matrix = trip_mat.data();

	apply(Triple{},trip_mat);
	//trip_mat.apply(Triple{});
	
	for (int i =0; i < trip_mat.size(); ++i){
		cout << trip_mat[i] << '\n';
	}
	
	char end;
	cin >> end;
}


















