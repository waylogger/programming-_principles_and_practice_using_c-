//�������� ���������: ������� ����������� ��������
//���� ���������:������� ����������� ��������
//�����: ������� �.�.
//���� ������ ���������: 04.11.2016
//���� ��������� ���������: 04.11.2016
//����� ������: 1.0
//��������� ����, ������� ����� ������� ��������: ���� �������� ��� � ����������� ���������� ����������� ������������ �������
//�������� ���� �������: ������������� �������� ����� ���������� �� 7 �������� � ������� ��������� ������
//������ ����������� ����: ������� main, ���� ��������-�������� � ������
//������������� � ������� ������: ������������� � ��������

#include <std_lib_facilities.h>

int main ()
try
{
setlocale (0, "");
//..................7 ����� ��� �������������
vector<int>monday;
vector<int>tuesday;
vector<int>wensday;
vector<int>thursday;
vector<int>friday;
vector<int>saturday;
vector<int>sunday;
//..................
int value = 0; // �����
string day = " ";// ����
int sum = 0; //�����
int z =0; // ������� ������
//..................

while (value!=13666)
	{
	if (value==0) {cout << "������� ���� ������\n";	cin >> day;}
	while (day!=" "&&
	day!="Monday"&&
	day!="Mon"&&
	day!="monday"&&
	day!="mon"&&
	day!="MON"&&
	day!="m"&&
	day!="M"&&
	day!="Tuesday"&&
	day!="Tu"&&
	day!="tuesday"&&
	day!="tue"&&
	day!="TUE"&&
	day!="tu"&&
	day!="TU"&&
	day!="Wensday"&&
	day!="Wen"&&
	day!="wensday"&&
	day!="wen"&&
	day!="WEN"&&
	day!="w"&&
	day!="W"&&
	day!="Thursday"&&
	day!="Thr"&&
	day!="thursday"&&
	day!="thr"&&
	day!="THR"&&
	day!="th"&&
	day!="TH"&&
	day!="Friday"&&
	day!="Fri"&&
	day!="friday"&&
	day!="fri"&&
	day!="FRI"&&
	day!="f"&&
	day!="F"&&
	day!="Saturday"&&
	day!="Sat"&&
	day!="saturday"&&
	day!="sat"&&
	day!="SAT"&&
	day!="st"&&
	day!="ST"&&
	day!="Sunday"&&
	day!="Sun"&&
	day!="sunday"&&
	day!="sun"&&
	day!="SUN"&&
	day!="SU"&&
	day!="su") 
		{
			cout << "������������ ��������, ��������� ���� \n";
			++z;
			cin >> day;
		}
		
	if (value==0) cout << "������� �����\n";
	cin >> value;
	
//..................�����������
	if (day=="Monday"||day=="Mon"||day=="monday"||day=="mon"||day=="MON"||day=="m"||day=="M")
	if (value!=13666)
	monday.push_back(value);

//..................
//..................
//..................�������

	if (day=="Tuesday"||day=="Tu"||day=="tuesday"||day=="tue"||day=="TUE"||day=="tu"||day=="TU")
	if (value!=13666)
	tuesday.push_back(value);

	
//..................�����

if (day=="Wensday"||day=="Wen"||day=="wensday"||day=="wen"||day=="WEN"||day=="w"||day=="W")
	if (value!=13666)
	wensday.push_back(value);

//..................�������

if (day=="Thursday"||day=="Thr"||day=="thursday"||day=="thr"||day=="THR"||day=="th"||day=="TH")
	if (value!=13666)
	thursday.push_back(value);

//..................�������
if (day=="Friday"||day=="Fri"||day=="friday"||day=="fri"||day=="FRI"||day=="f"||day=="F")
	if (value!=13666)
	friday.push_back(value);


//..................�������
if (day=="Saturday"||day=="Sat"||day=="saturday"||day=="sat"||day=="SAT"||day=="st"||day=="ST")
	if (value!=13666)
	saturday.push_back(value);

//..................�����������
if (day=="Sunday"||day=="Sun"||day=="sunday"||day=="sun"||day=="SUN"||day=="SU"||day=="su")
	if (value!=13666)
	sunday.push_back(value);



}
//...............................�����
//..................�����������
if (monday.size()>0)
{
cout << "�����������\n";
for (int i=0; i<monday.size ();++i)
	{
	cout << monday[i] << "\n";
	sum+=monday[i];
	}
cout << "����� ���� �������� = " << sum << "\n";
sum=0;
}
//..................�������
if (tuesday.size()>0)
{
	cout << "�������\n";
for (int i=0; i<tuesday.size ();++i)
	{
	cout << tuesday[i] << "\n";
	sum+=tuesday[i];
	}
cout << "����� ���� �������� = " << sum << "\n";
sum=0;
}
//..................�����
if (wensday.size()>0)
{
cout << "�����\n";
for (int i=0; i<wensday.size ();++i)
	{
	cout << wensday[i] << "\n";
	sum+=wensday[i];
	}
cout << "����� ���� �������� = " << sum << "\n";
sum=0;
}
//..................�������
if (thursday.size()>0)
{
cout << "�������\n";
for (int i=0; i<thursday.size ();++i)
	{
	cout << thursday[i] << "\n";
	sum+=thursday[i];
	}
cout << "����� ���� �������� = " << sum << "\n";
sum=0;
}
//..................�������
if (friday.size()>0)
{
cout << "�������\n";
for (int i=0; i<thursday.size ();++i)
	{
	cout << friday[i] << "\n";
	sum+=friday[i];
	}
cout << "����� ���� �������� = " << sum << "\n";
sum=0;
}
//..................�������
if (saturday.size()>0)
{
cout << "�������\n";
for (int i=0; i<saturday.size ();++i)
	{
	cout << saturday[i] << "\n";
	sum+=saturday[i];
	}
cout << "����� ���� �������� = " << sum << "\n";
sum=0;
}
//..................�����������
if (sunday.size()>0)
{
cout << "�����������\n";
for (int i=0; i<sunday.size ();++i)
	{
	cout << sunday[i] << "\n";
	sum+=sunday[i];
	}
cout << "����� ���� �������� = " << sum << "\n";
sum=0;
}
cout << "����� ��� ����� ������ �������� ������ -  " << z << "\n";
keep_window_open("~");
}

catch (exception& e)
{
cerr << e.what () << "\n";
}
