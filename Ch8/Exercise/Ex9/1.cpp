/*
������� �.�.

07.12.2016

�������� ������� maxv (), 
������� ����������
 ���������� ������� �������, 
������������� � �������� ���������
*/
#include<std_lib_facilities.h>
void maxv (vector<double>&maxi) 
{ // ��������� ������� maxv
double d = 0;
for (int i=0;i<maxi.size();++i)
{ //��������� for
if (d<maxi[i]) d=maxi[i];
}//��������� for
cout << "Biggest member of maxi - " << d <<'\n';
}//��������� ������� maxv


int main () 
{ //omain
vector<double>maxi{1,2,3,4,5,6,7,8,9};
maxv(maxi);
keep_window_open();
} //cmain


	