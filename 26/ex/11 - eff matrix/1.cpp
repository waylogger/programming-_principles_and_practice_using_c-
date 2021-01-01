/*
Antonuyk I.V.

08/05/2018
Belgorod


PPP C++ B.Stroustrup

ex. 26.11

*/

#include 		<		iostream		>
#include 		<		matrix\\matrix.h>
#include		<		vector			>
#include		<		chrono			>

#include		<		std_lib_facilities.h		>


using namespace std;
using Numeric_lib::Matrix;





double row_sum(Matrix<double,2> m, int n){
	double s = 0;
	
	for (int i = 0 ; i < m.dim2(); ++i){
		s += m[n].data()[i];
		
	}
		
	
	return s;
	}


double row_accum(Matrix<double,2> m, int n){
	
	double s = 0;
	for (int i = 0; i < n; ++i)
		s += row_sum(m,i);
	return s;
	
}


Matrix<double,2> rand_matrix(int d1, int d2){
	Matrix<double,2> m(d1,d2);
	
	for (int i =0; i < m.dim1(); ++i)
		for (int j = 0; j < m.dim2(); ++j){
			m(i,j) = randint(-10,10);
		}
	
	
	return m;
}

int main(){
	
	
	
	auto t1 = chrono::system_clock::now();
	
	Matrix<double,2>m = rand_matrix(10000,10000);
	
	vector<double>v;
	
	for (int i = 0 ; i < m.dim1(); ++i){
		int a = row_sum(m,i);
		v.size() ?	v.push_back(a+v[v.size()-1]) : v.push_back(a);
	//v.push_back(row_accum(m,i+1));
	}
	
	double s = 0;
	for (int i =0; i < v.size(); ++i)
		s += v[i];
	
	cout << "Sum: " << s << '\n';
	
	auto t2 = chrono::system_clock::now();
	
	int tim = chrono::duration_cast<chrono::milliseconds>(t2-t1).count();
	
	cout << "Time: " << tim << '\n';
	cout << "Correlation to matrix size (time/size) : " << tim/150 << '\n';
	
	
	char end;
	cin >> end;
}
