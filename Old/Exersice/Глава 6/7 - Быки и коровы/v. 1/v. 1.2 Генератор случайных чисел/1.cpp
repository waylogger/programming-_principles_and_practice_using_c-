//�������� ���������: ���� � ������
//���� ���������: ����������� ����� � �������� ����������, � ���������� � ������� ���������� ��������� ������
//�����: ������� �.�.
//���� ������ ���������: 1.11.2016
//���� ��������� ���������: 03.11.2016
//����� ������:1.0
//��������� ����, ������� ����� ������� ��������: ��������� ���������� ���������������� ���� 
//�������� ���� �������:1. ������ ��������� �����������, ������� ����������� ���� ��������� ����� ��������� ������������������ ��������� � ����� �� ����� �������� ������������������; 2. ���� ��������� �����������, ������� ����������� ���� ��������� ����� ����� ������������������� � ����� � ��� �� ��������.
//������ ����������� ����: 1. ������� main; 2. ��������� ����������; 3. ������ ���������. 4. ���������������� ���� ���������; 5. ������� ������.
//������������� � ������� ������: �������� ��� ��������� �������� �� ����� 4-� ��������.

#include <std_lib_facilities.h>

int main ()
try
{
	setlocale(0, ""); // ����
	
	
	
	
	string a = " "; // �������
	int reg = 0; // �����
	int next = 0; //��������� �����
	int kows = 0; // ������
	int bulls = 0; // ����
	int n = 0; // ��������� �������� = seed 
	//��������
	int i2 = 0;
		
		
while (reg!=2)
	{
	
	int ib1 = 0; // ��������� ����� �1
	int ib2 = 0; // ��������� ����� �2
	int ib3 = 0; // ��������� ����� �3
	int ib4 = 0; // ��������� ����� �4
	char sb1[16] = " "; //��������� ������� �1
	char sb2[2] = " "; //��������� ������� �2
	char sb3[2] = " "; //��������� ������� �3
	char sb4[2] = " "; //��������� ������� �4
	int n =0;
	cout << "������� ����� ����� �����\n";
	cin >> n;
	
	srand(n); // ��������� ����� �1
	ib1 = rand () %10;
	itoa(ib1, sb1, 10);
	
	n=n*n;
	srand(n); // ��������� ����� �2
	ib2 = rand () %10;
	itoa(ib2, sb2, 10);
	
	n=n/n;
	srand(n); // ��������� ����� �3
	ib3 = rand () %10;
	itoa(ib3, sb3, 10);
	
	n=n/n+641;
	srand(n); // ��������� ����� �4
	ib4 = rand () %10;
	itoa(ib4, sb4, 10);
	
	//������������ �����
	strcat(sb1,sb2); 
	strcat(sb1,sb3);
	strcat(sb1,sb4);

		
		
		cout << "��� ������ ���� - ���� � ������ - ������� 1, ��� ������ ������� - 2 \n";
		cin >> reg;
			while (reg!=1&&reg!=2)
			{
				cout << "������������ ��������, ��������� ���� \n";
				cin >> reg;
				if (reg==2) error ("������\n");
			}
			;
			cout << "��� �� �������, ����� �������������� ����� ���� ��������?\n";
			while (a!="help")
			{
			cout << sb1 << "\n";
			cin >> a;
				while (a.size ()!=4)
				{
					cout << "������������ ��������, ��������� ���� \n";
					cin >> a;
				}
			for (int i =0; i<4; ++i) 
				{
					if (sb1[i]==a[i]) ++bulls;
					for (int i2 = 0; i2<4; ++i2) 
						if (a[i]==sb1[i2]
							&&a[i]!=a[i-1]
							&&a[i]!=a[i-2]
							&&a[i]!=a[i-3]) 
							++kows;
				}
			if (a!="help") cout << "����� = " << bulls << "\n";
			if (a!="help") cout << "����� = " << kows << "\n";
			if (a!="help"&&kows==4) cout << "�����������, �� ����� ���� �����!!!\n";
			if (a!="help"&&kows>0&&kows<4) cout << "��������, �� ���� ���������� ����� �� ����� ������ "
									 << kows << "\n";
			if (a!="help"&&kows==0) cout << "��������, �� �� ����� �� ����� ������\n";
			if (a!="help"&&bulls>0&&bulls<4) cout << "��������, �� ���� ���������� �����, �� ����� ������ "
									 << bulls << "\n";
			if (a!="help"&&bulls==4) 
			{
				cout << "�����������, �� ����� ���� �����!!!\n";
				
					cout << "������� ����� ����� �����\n";
					cin >> n;
	
					srand(n); // ��������� ����� �1
					ib1 = rand () %10;
					itoa(ib1, sb1, 10);
					
					n=n*n;
					srand(n); // ��������� ����� �2
					ib2 = rand () %10;
					itoa(ib2, sb2, 10);
					
					n=n*64031;
					srand(n); // ��������� ����� �3
					ib3 = rand () %10;
					itoa(ib3, sb3, 10);
					
					n=n*n+641;
					srand(n); // ��������� ����� �4
					ib4 = rand () %10;
					itoa(ib4, sb4, 10);
					
					//������������ �����
					strcat(sb1,sb2); 
					strcat(sb1,sb3);
					strcat(sb1,sb4);
				
			}
			if (a!="help"&&bulls==0) cout << "��������, �� �� �� ����� �� ������ ����\n";
			bulls=0;
			kows =0;
			}
			
			
		
	}
	
}
				
		


catch (exception& e)
{
cerr << e.what ();
}