//�������� ���������: ��������� ���������� - F � K � ��������.
//���� ���������: ��������� ������ ��������� ����������� �� �������� ������� � ������� ��������
//�����: ������� �.�.
//���� ������ ���������: 26.10.2016
//���� ��������� ���������:
//����� ������: 1
//��������� ����, ������� ����� ������� ��������: ������� �����������
//�������� ���� �������: 1. ���������� �������, ������ ������ � �������� �.
//������ ����������� ����: 2 ��������� ����� - ������� main � ������� ����������� - ctok
//������������� � ������� ������: �������� ������ � ��������� �������, ��� - double

#include <std_lib_facilities.h>

double ktof (double k)
{

double f =  1.8*(k-273)+32;

return f;
}

double ftok (double f)
{
double k = (f+459.67)/1.8;
return k;
}

int main ()
try
{
double k = 0;
double f = 0;
int z = 0;
int w = 0;


while (z!=3)
{
z=0;
w=0;
cout << "Please change: K to F - 1; F to K - 2; Exit - 3\n";
cin >> z;

if (z==1)
while (w!=2)
	{
w=0;
cout << "\nPlease insert temp in Kelvin\n";
cin >> k;
if (k<0)
cerr << "Too cold!!!!! It is less absolute zero!!!!\n";
double f = ktof (k);
if (k>=0)
cout << k << " of Kelvin is " << f << " of Fahrenheit\n";
cout << "Pls....insert 1 for repeat or 2 for exit\n";
cin >> w;
	}
if (z==2)
while (w!=2)
	{
w=0;
cout << "\nPlease insert temp in Fahrenheit \n";
cin >> f;
if (f<-459.4)
cerr << "Too cold!!!!! It is less absolute zero!!!!\n";
double k = ftok(f);
if (f>=-459.4)
cout << f << " of Fahrenheitis " << k << " of Kelvin\n";
cout << "Pls....insert 1 for repeat or 2 for exit\n";
cin >> w;
	}
}
}

catch (exception& e)
{
cout << e.what ();
}

catch (...)
{
cout << "\nUps......\n";
}


