#include <iostream>
#include <vector>
#include <Matrix\\Matrix.h>

using Numeric_lib::Matrix;
using namespace std;


void f(){
	vector<int>v1;
	vector<int>v2;
	
	int m = 0;
	int n = 0;
	
	Matrix<int,2>* table = nullptr;
	
	cout << "Lets construct matrix view by [0,n)*[0,m)" << '\n';
	
	cout << '\t' << "insert n: ";
	cin >> n;
	if (!cin){
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cerr << "Bad stream\n";
		return;
	}
		
	cout << '\t' << "insert m: ";
	cin >> m;
	if (!cin){
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cerr << "Bad stream\n";
		return;
	}
	
	
	for (int i = 0; i < n; ++i)
		v1.push_back(i);
	
	for (int i = 0; i < m; ++i)
		v2.push_back(i);
	
	table = new Matrix<int,2>(n*m,3);

	int index = 0;
	for (int i = 0; i < v1.size(); ++i) 
			for (int j = 0; j < v2.size(); ++j, ++index){
				(*table)[index][0] = v1[i];
				(*table)[index][1] = v2[j];
				(*table)[index][2] = v1[i] * v2[j];
			}
		
	
	int save = 0;
	for (int i = 0; i < table->dim1(); ++i){
		if (save != (*table)[i][0]){
			save = (*table)[i][0];
			cout << "-------------------------------------------------------------------------------\n";
		}
				
		cout 	<< (*table)[i][0] << "\t*\t"	<< (*table)[i][1] << "\t=\t"
				<< (*table)[i][2] << '\n';
	}
		
	cout << "-------------------------------------------------------------------------------\n";
}
int main(){
	
	while (true) f();
	
	
	char end;
	cin >> end;
}
