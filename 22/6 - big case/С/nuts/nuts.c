#include <stdio.h>



int main()
{

int sq = 0, nuts = 0;

printf("%s\n","Num of nuts");
scanf("%d",&nuts);
printf("%s\n","Num of squirrel");
scanf("%d",&sq);

while (nuts >= sq){
	printf("%s%d%s","We are have - ", nuts, " of nuts\n");
	printf("%d%s",sq, "  of squirrel take by one\n");
	nuts = nuts - sq;
	printf("%s","Rest is - ");
	printf("%d",nuts);
	printf("%s","\n");
}


char c;
scanf("%s",&c);	
}