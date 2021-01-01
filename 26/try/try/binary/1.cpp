/*

Antonuyk I.V. 27/04/2018
Belgorod

Binary search with test and compary with std::binary search

task 26.1 PPP C++ B. Stroustrup

results of performance:

MY:
Time of work    Count
58      14
59      34
60      23
61      13
62      3
63      6
64      4
65      1
67      1
70      1

STD:
Time of work    Count
57      2
58      15
59      30
60      24
61      19
62      3
63      3
65      2
66      1
67      1

*/


#include <iostream>
#include <algorithm>
#include <chrono>
#include <map>
#include <vector>


using namespace std;

template <typename ForwIt, typename K>
bool my_binary_search(const ForwIt begin, const ForwIt end, const K key){
	if (key < *begin || key > *(end-1)) 					//Проблема границ
		return false;
	//------------------------------------------------------
	ForwIt left = begin;									//Установка границ
	ForwIt right = end;
	while (true){
		int number_of_elem = right-left;
		int focus = (number_of_elem / 2 );
		ForwIt comp = left + focus;
		if ( * comp == key){
			return true;
		}	
		else if ( * comp > key){

				if ( * ( comp - 1 ) < key ){
				return false;
				}
					
				else if ( * ( comp - 1 ) == key ){
				return true;
				}	
		right = right - focus;
		}
		else if ( * comp < key ){	
				if ( * comp + 1 > key ){
				return false;
				}
				else if ( * ( comp + 1) == key ){
				return true;
				}
		left = left + focus;
		}
	}

	return false;
}



void test_my_binary_search(int size_of_arrays,const vector<int>& randv){
	int alloc = 500000;
	int* sec1 = new int[alloc];
	int* sec2 = new int[alloc];
	int S1 = size_of_arrays;
	int Ups = 0;
	
	
	for (int i = 0; i < S1; ++i){
		sec1[i] = i*2;
	}
	
	int init_k = 1;
	for (int i = 0; i < S1; ++i){
		sec2[i] = init_k;
		init_k+=2;
	}
	
	for (int i =0 ; i < S1; ++i){
		if (my_binary_search(&sec1[0],&sec1[S1],sec2[i])){
			++Ups;
		}
	}
	//cout << "my:: Sec 1 and 2 was compared, mistakes: " << Ups << '\n';
	Ups = 0;
	for (int i =0 ; i < S1; ++i){
		if (my_binary_search(&sec1[0],&sec1[S1],sec1[i])){
			++Ups;
		}
		
	}
	//cout << "my:: Sec 1 was compared with itself, coincidence: " << Ups << " from " << S1 <<'\n';
	Ups = 0;
	
	for (int i =0 ; i < S1; ++i){
		if (my_binary_search(&sec2[0],&sec2[S1],sec1[i])){
			++Ups;
		}
	}
	//cout << "my:: Sec 2 and 1 was compared, mistakes: " << Ups << '\n';
	
	for (int i =0 ; i < S1; ++i){
		
	}	for (int i =0 ; i < S1; ++i){
		if (my_binary_search(&sec2[0],&sec2[S1],sec2[i])){
			++Ups;
		}	
	}
	//cout << "my:: Sec 2 was compared with itself, coincidence: " << Ups << " from " << S1 <<'\n';
	Ups = 0;

	for (int i =0 ; i < S1; ++i){
		int comp = rand()%200;
		if (my_binary_search(&sec1[0],&sec1[S1],comp)){
			++Ups;
		}
	}
	//cout << "my:: Sec 1 was compared with rand sec, coincidence: " << Ups << " from " << S1 <<'\n';
	Ups = 0;
	
	for (int i =0 ; i < S1; ++i){
		int comp = rand()%200;
		if (my_binary_search(&sec2[0],&sec2[S1],comp)){
			
			++Ups;
		}
	}
	//cout << "my:: Sec 2 was compared with rand sec, coincidence: " << Ups << " from " << S1 <<'\n';
	Ups = 0;
	
	
	for (int i =0 ; i < S1; ++i){

		if (my_binary_search(&sec1[0],&sec1[S1],randv[i])){
			++Ups;
		}
	}
	//cout << "my:: Sec 1 was compared with rand vec, coincidence: " << Ups << " from " << S1 <<'\n';
	Ups = 0;
	
	for (int i =0 ; i < S1; ++i){
		if (my_binary_search(&sec2[0],&sec2[S1],randv[i])){
			++Ups;
		}
	}
	//cout << "my:: Sec 2 was compared with rand vec, coincidence: " << Ups << " from " << S1 <<'\n';
	Ups = 0;
	delete [] sec1;
	delete [] sec2;
	
	
	
}

void test_std_binary_search(int size_of_arrays,const vector<int>& randv){
	int alloc = 500000;
	int* sec1 = new int[alloc];
	int* sec2 = new int[alloc];
	int S1 = size_of_arrays;
	int Ups = 0;
	
	
	for (int i = 0; i < S1; ++i){
		sec1[i] = i*2;
	}
	
	int init_k = 1;
	for (int i = 0; i < S1; ++i){
		sec2[i] = init_k;
		init_k+=2;
	}
	
	for (int i =0 ; i < S1; ++i){
		if (std::binary_search(&sec1[0],&sec1[S1],sec2[i])){
			++Ups;
		}
	}
	//cout << "std:: Sec 1 and 2 was compared, mistakes: " << Ups << '\n';
	Ups = 0;
	for (int i =0 ; i < S1; ++i){
		if (std::binary_search(&sec1[0],&sec1[S1],sec1[i])){
			++Ups;
		}
		
	}
	//cout << "std:: Sec 1 was compared with itself, coincidence: " << Ups << " from " << S1 <<'\n';
	Ups = 0;
	
	for (int i =0 ; i < S1; ++i){
		if (std::binary_search(&sec2[0],&sec2[S1],sec1[i])){
			++Ups;
		}
	}
	//cout << "std:: Sec 2 and 1 was compared, mistakes: " << Ups << '\n';
	
	for (int i =0 ; i < S1; ++i){
		
	}	for (int i =0 ; i < S1; ++i){
		if (std::binary_search(&sec2[0],&sec2[S1],sec2[i])){
			++Ups;
		}	
	}
	//cout << "std:: Sec 2 was compared with itself, coincidence: " << Ups << " from " << S1 <<'\n';
	Ups = 0;

	for (int i =0 ; i < S1; ++i){
		int comp = rand()%200;
		if (std::binary_search(&sec1[0],&sec1[S1],comp)){
			++Ups;
		}
	}
	//cout << "std:: Sec 1 was compared with rand sec, coincidence: " << Ups << " from " << S1 <<'\n';
	Ups = 0;
	
	for (int i =0 ; i < S1; ++i){
		int comp = rand()%200;
		if (std::binary_search(&sec2[0],&sec2[S1],comp)){
			++Ups;
		}
	}
	//cout << "std:: Sec 2 was compared with rand sec, coincidence: " << Ups << " from " << S1 <<'\n';
	Ups = 0;
	

	for (int i =0 ; i < S1; ++i){
		int comp = rand()%200;
		if (std::binary_search(&sec1[0],&sec1[S1],randv[i])){
			++Ups;
		}
	}
	//cout << "std:: Sec 1 was compared with rand vec, coincidence: " << Ups << " from " << S1 <<'\n';
	Ups = 0;
	
	for (int i =0 ; i < S1; ++i){
		int comp = rand()%200;
		if (std::binary_search(&sec2[0],&sec2[S1],comp)){
			++Ups;
		}
	}
	//cout << "std:: Sec 2 was compared with rand vec, coincidence: " << Ups << " from " << S1 <<'\n';
	Ups = 0;
	
	delete [] sec1;
	delete [] sec2;
	
	
	
}



int timetest_of_my_search(const int num,const vector<int>& randv){


	auto t1 = chrono::system_clock::now();
	
	test_my_binary_search(num,randv);
	
	auto t2 = chrono::system_clock::now();
	
	return chrono::duration_cast<chrono::milliseconds>(t2-t1).count();	
}

int timetest_of_std_search(const int num,const vector<int>& randv){


	auto t1 = chrono::system_clock::now();
	
	test_std_binary_search(num,randv);
	
	auto t2 = chrono::system_clock::now();
	
	return chrono::duration_cast<chrono::milliseconds>(t2-t1).count();	
}




int main(){
	
	map<int,int>t_map1;
	
	vector<int>randv;
	
	for (int i =0; i < 50000; ++i){
		randv.push_back(rand()%200);
	}
	
	for (int i =0; i < 100; ++i){
		++t_map1[timetest_of_my_search(50000,randv)];
	}
	cout << "Time of work\tCount\n";
	for (auto z : t_map1){
	cout << z.first << '\t' << z.second << '\n';
	}
	
	cout << '\n';
	
	map<int,int>t_map2;
	
	for (int i =0; i < 100; ++i){
		++t_map2[timetest_of_my_search(50000,randv)];
	}
	cout << "Time of work\tCount\n";
	for (auto z : t_map2){
	
	cout << z.first << '\t' << z.second << '\n';
	}
	
	
	
	
	
	char end;
	cin >> end;
}