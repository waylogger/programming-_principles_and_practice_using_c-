
include D:\masm32\include\Irvine32.inc
includelib D:\masm32\lib\kernel32.lib
includelib D:\masm32\lib\Irvine32.lib

.data

fahr	dd		?
celsus	dd		?
lower	dd		0
upper	dd		300
step	dd		20
d dd 5*2+25
.code
start:
mov eax,lower
mov fahr,eax

s1:
mov eax, fahr
cmp eax,upper
JLE s2

s2:
mov eax, fahr


mov eax,d
call WriteInt


ret
end start 


	;int fahr, celsus;
	;int lower, upper, step;
	
	;lower =0;
	;upper =300;
	;step = 20;
	
	;fahr = lower;
	
	;while (fahr <= upper){
	;	celsus = 5 * (fahr-32) /9;
	;	printf("%d\t%d\n",fahr,celsus);
	;	fahr = fahr + step;
	;}
