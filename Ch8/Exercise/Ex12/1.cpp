/*

�������� �������, ����������� ��������
����
vector<string>
� ������������ ������ ���� vector <int>
���������� ���������� �������� �
������ ������

����� ����� �������� � ����� �������
������

��������������� ������ � ��������� �����

������� ��������� ������� �� ������������ ��
��� ������� ���� �����? ������?


*/



/*
����������� ���������:
����� ������� ����� ������� �����
����� ������� ����� �������� �����
*/
#include <std_lib_facilities.h>
void cheking(vector<string> word)
{ //cheking
	int s = 0;
	string slong = " ";
	string sshort = " ";
	string ss = " ";
	for (int i = 0; i < word.size(); ++i) 
	{//for 24
	ss = word[i];
	sshort=ss;
	if (ss.size()>slong.size()) slong = ss;
	if (ss.size()<sshort.size()) sshort = ss;
	cout << "String " << i+1 << " - " << ss
	     << "\nSum of char - " << ss.size() << '\n';
	
	}//for 24
	cout << "The most long string - " << slong << '\n';
	cout << "The most short string - " << sshort << '\n';
	sort (word);
	cout << "The low lexigraphic string - " << word[0] << '\n'
		 << "The hight lexigraphic string - " << word[word.size()-1] << '\n';
	
		

}//cheking

int main() {
	vector<string>word{ "smithy", "milka", "bobr" };
	cheking(word);
	keep_window_open();
} 