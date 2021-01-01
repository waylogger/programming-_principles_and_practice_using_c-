/*

Antonuyk I.V.
23.04.2018

PPP C++ 25.14 Examples of Pool of vector


Пул реализован путем ведения регистранциооного журнала, поиск в котором всегда выпоняется за одинаковое время
поскольку всегда выделяется указатель стоящий на первой позиции регистрационного журнала
после выделения запись перемещается за границу использованных записей

Т.Е. журнал всегда сортирован, записи разных категорий отделены границей, 
которая проведена по последнему использованному элементу

Указанную модель пула невозможно использовать без лищних усложнений для формирования массивов
поскольку указатели выделяются из пула не последовательно, а из разных частей пула из-за перемещения записей в регистрационном
журнале

поэтому данная первая версия пула не пригодня для выполнения задания

*/
#ifndef MY_POOL
#define MY_POOL


#include <iostream>
#include <algorithm>
#include <chrono>


using namespace std;




template <typename T, int N>
struct Pool{
	int border;
	struct Log_of_status		{int inx = 0; 	bool stat = 0; };
	struct Log_of_correction	{int inx = 0;	int pos = 0;};
	
	T* mem;
	Log_of_status* los;
	Log_of_correction* loc;
	
	Pool(): mem{new T[N]}, los{new Log_of_status[N]}, loc{new Log_of_correction[N]}, border {N} {
		for (int i =0; i < N; ++i){
			los[i] = Log_of_status{i,false};
			loc[i] = Log_of_correction{i,i};
		}
	}
	
	void swap_los(Log_of_status& los1, Log_of_status& los2);
	void swap_loc(Log_of_correction& loc1, Log_of_correction&loc2);
	
	T* get();
	void print_stat();
	void print_pos();
	int empt()const {
		int s = 0;
		for (int i =0; i < N; ++i){
			if (los[i].stat == false) ++s;
		}
		return s;
	}
	
	void free(T* addr);
};

template <typename T, int N>
void Pool<T,N>::swap_los(Log_of_status& los1, Log_of_status& los2){
	Log_of_status los3 = los1;
	los1 = los2;
	los2 = los3;
	}

template <typename T, int N>
void Pool<T,N>::swap_loc(Log_of_correction& loc1, Log_of_correction&loc2){
		int loc3 = loc1.pos;
		loc1.pos = loc2.pos;
		loc2.pos = loc3;
	}

template <typename T, int N>	
T* Pool<T,N>::get(){
		T* ret = &mem[los[0].inx];
		if (los[0].stat == true)
			return nullptr;
		los[0].stat = true;
		if (border > 0){
		swap_loc(loc[los[0].inx],loc[los[border-1].inx]);
		swap_los(los[0],los[border-1]);
		
		 --border;
		}
		return ret;
	}

template <typename T, int N>	
void Pool<T,N>::print_stat(){
		for (int i = 0; i < N; ++i){
			cout << "Cell: " << los[i].inx << "\t";
			if (los[i].stat == false)
				cout << " is free\n";
			else 
				cout << " is busy\n";
		}
	}


template <typename T, int N>	
void Pool<T,N>::print_pos(){
		for (int i = 0; i < N; ++i){
			cout << "Cell win index: " << loc[i].inx << "\t" << " place: " << loc[i].pos << " of notes\n";
			
		}
	}
	
	
template <typename T, int N>
void Pool<T,N>::free(T* addr){
		if (addr < &mem[0] || &mem[N] < addr){
			cout << "Address not in pool\n";
			return;
		}
		
		//*addr = nullptr;
		int inx = addr - &mem[0];
		int corr_inx = loc[inx].pos;
		
		if (los[corr_inx].stat == false){
			cout << "address already free\n";
			return;
		}
		los[corr_inx].stat = false;
		swap_los(los[corr_inx],los[border]);
		swap_loc(loc[los[corr_inx].inx],loc[los[border].inx]);
		if (border < N)
			++border;

	}
	
	
#endif








