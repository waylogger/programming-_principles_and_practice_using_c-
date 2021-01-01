/*

Antonyuk I.V.
23/05/18
Belgorod

PPP C++ B.Stroustrup
ex. 27.14


*/


#include <stdlib.h>
#include <stdio.h>


struct Data{
	
	int max;
	int min;
	int med;
	int mid;
	
	
};


void init_data(struct Data* d){
	d->max = d->min = d->med = d->mid = 0;
}


int cmp_int(const int* a, const int* b){
	
	if 		(*a == *b)
						return 0;
	else if (*a < *b)
						return -1;
	else
						return 1;
}

struct Data ariph(int* a,int sz){
	struct Data d;
	init_data(&d);
	
	
	int* arr = (int*)malloc(sizeof(int)*sz);
	int mid = 0;
	int med = 0;
	for (int i = 0; i < sz; ++i){
		arr[i] = a[i];
		mid += arr[i];
	}
	
	qsort(arr,sz,sizeof(int),cmp_int);
	
	if (!(sz%2)){
		int f1 = arr[(sz/2)-1];
		int f2 = arr[(sz/2)];
		med = (f1+f2)/2;
	}
	else
		med = arr[((sz-1)/2)];
	
	d.max = arr[sz-1];
	d.min = arr[0];
	d.mid = mid;
	d.med = med;
	
		
	
	free(arr);
	return d;
}
int main(){
	//0123 4 5678
	//0123 45 6789
	int a[10];
	
	for (int i = 0; i < 10; ++i)
		a[i] = i;	
	
	struct Data d = ariph(a,10);
	
	printf("max: %1d\nmin: %1d\nmid: %1d\nmed: %1d\n",d.max,d.min,d.mid,d.med);

		
	char c;
	scanf("%1c",&c);
	
}