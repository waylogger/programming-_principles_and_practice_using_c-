#include <stdio.h>


int main ()
{
	int fahr, celsus;
	int lower, upper, step;
	
	lower =0;
	upper =300;
	step = 20;
	
	fahr = lower;
	
	while (fahr <= upper){
		celsus = 5 * (fahr-32) /9;
		printf("%d\t%d\n",fahr,celsus);
		fahr = fahr + step;
	}
	char q;
	scanf("%1c",&q);
}