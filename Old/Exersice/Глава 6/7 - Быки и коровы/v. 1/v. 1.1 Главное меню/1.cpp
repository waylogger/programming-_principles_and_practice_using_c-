//�������� ���������: ���� � ������
//���� ���������: ����������� ����� � �������� ����������, � ���������� � ������� ���������� ��������� ������
//�����: ������� �.�.
//���� ������ ���������: 1.11.2016
//���� ��������� ���������:
//����� ������:1.0
//��������� ����, ������� ����� ������� ��������: ��������� ���������� ���������������� ���� 
//�������� ���� �������:1. ������ ��������� �����������, ������� ����������� ���� ��������� ����� ��������� ������������������ ��������� � ����� �� ����� �������� ������������������; 2. ���� ��������� �����������, ������� ����������� ���� ��������� ����� ����� ������������������� � ����� � ��� �� ��������.
//������ ����������� ����: 1. ������� main; 2. ��������� ����������; 3. ������ ���������. 4. ���������������� ���� ���������; 5. ������� ������.
//������������� � ������� ������: �������� ��� ��������� �������� �� ����� 4-� ��������.

#include <std_lib_facilities.h>

int main ()
try
{
string a = " "; // ����
string b = " "; // �����
int reg = 0; // �����
int next = 0;

//.............................
//.............................
//........(��������)...........
int i = 0;
int i2 = 0;
int i3 = 0;
int i4 = 0;
int bulls = 0;
int kows = 0;
//.............................
//.............................
//.............................
vector<string>bk = {"9672"};
while (reg!=3) // ����� ���� - ���� ���������� - ���� ���� ������ ���� ���������
		{
		if (i=bk.size()-1&&reg==1) cout << "GZ!!!!! Ti otgadal vse slova!!!!\n";
		cout << "Viberite rezhim: 1-Ugadivanie; 2-dobavlenie, 3-exit;\n";
		cin >> reg;
		if (reg==2) // ����� ����� ������;
			{
		cout << "Dobavte 4-h znachnie chisla\n";
		
		while (a.size ()!=4)// �������� �� �������� ���������, ������� ������ �������� ������ �� 4� ��������;
			{cin >> a;
			if (a.size () !=4) cout << "Uncorrect value\n";
			}
		
		bk.push_back(a);
		a=" ";
				}
		if (reg==1) // ����� �����������;
			{
				cout << "Pls....ugadaite zagadannoe 4-h znachnoe chislo - igra biki i korovi\npravila tebe izvestni\n";
				while (i<bk.size()) // ��������� �� �������, 1 ���������� ���� �������������� �����;
					{	b=bk[i];
						a=" ";
						while (a.size ()!=4) // �������� �� �������� ���������, ������� ������ �������� ������ �� 4� ��������;
						{
						cin >> a;	if (a.size () !=4) cout << "Uncorrect value\n";
						}
						while (i2<4) // ������� ���������� �����, 1 ��������� - 1 �������������, ����� 4 �������������;
						{
							if (bulls<4&&a[i2]==b[i2]) ++bulls;
							while (i3<4) // ������� ���������� �����, 1 �������� - 4 �������������, ����� 16 �������������, 1 ������ a � 4 �� b
							{
							if (a[i2]!=a[i2-1]&&a[i2]!=a[i2-2]&&a[i2]!=a[i2-3]&&a[i2]==b[i3]) ++kows;
							++i3;
							}
						++i2;
						i3=0;
						}
					///////////////////////////////////////////////////////////////////////////////////////
					//////////////////////�����////////////////////////////////////////////////////////////
					if (kows!=0&&kows!=4)	cout << "OK, you are have " << kows << " kows\n" << "\n";
					if (kows==0)	cout << "OK, you are have no kows\n" << "\n";
					if (kows==4)	cout << "GZ!!! You are have all " << kows << " kows" << "\n";
					if (bulls!=0&&bulls!=4)	cout << "OK, you are have " << bulls << " bulls\n" << "\n";
					if (bulls==0)	cout << "OK, you are have no bulls\n" << "\n";
					if (bulls==4)	
							{
							cout << "GZ!!! You are have all " << bulls << " bulls" << "\n";
							cout << "next numbers? 1-yes; 2 = no; 3 = exit\n";
							cin >> next;
							if (next == 1) {++i; i2=0; i3=0; bulls=0;};
							if (next == 3) i=bk.size(); //����� � ������� ����;
							}
					i2=0;
					kows=0;
					bulls=0;	
					}
			reg=0;
			
			}
		}

}
				
		


catch (exception& e)
{
cerr << e.what () << "\nUps.....\n";
}