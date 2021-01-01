#include <stdio.h>



int main()
{
int x = 0;
char c;
srand(time(0));

for (int i =0; i < 10;++i){
	x = rand()%6;
	printf("%s-","Your luck is");
	printf("%d\n",x);
}




scanf("%c",&c);

}