// ����� � �����
/*
������ ������ ��������� ������ �������� ��� �� �����������, �� �� ���������� ������ ���� ���������.

1. ����� �� ������ ����� � �����;
2. ��������� �� � ������
3. ����� �� �������.

1. ������� ����� ���_����
2. ������� ������ ���� <���_����>
3. ������� ������ ������� �����;
4. ������� ������ �������� � ��������� � ������ ��������;
5. ������� ������� ������ �� �������
*/

#include <std_lib_facilities.h>
const char print = '='; // ������������� ��������� ������ �� ������
class namesandscore { //����� �������
	public:
	string names; //�����
	int score; //����
	namesandscore(string n, int s) : names(n), score(s) { } //������������ �������
};
class streams { //���������� � �������������
	public:
	namesandscore get (); // ��������� ������ �� ������
	void ignoring(char c); //���������� �������
};
class tables { //������ � �������� � ���
	public:
	vector<namesandscore>NS;
	void push(string a, int b); //�������� � ������
	void back(); //����� �� �������
};
streams ts;
tables tl;
void continuerun () { //������� �������������� ����� ������
	ts.ignoring(print);
}
void tables::push (string a, int b) try { //�������� � ������
	
	setlocale(0, "");
	for (int i = 0; i<NS.size(); ++i) {
	if (NS[i].names==a) error ("��������� ���");} //� �� ����������� �� ��?
	NS.push_back(namesandscore(a,b));
	
}
catch (exception& e) {
	cerr << e.what() << endl;
	continuerun ();
	}
void tables::back () { //����� �� �������
	for (int i = 0; i<NS.size(); ++i) 
		cout << NS[i].names << " - " << NS[i].score << "\n";
	return;
};
void streams::ignoring (char c) { //�������������
	char ch;
	while (cin >> ch)
	if (ch == c) return;
}
namesandscore streams::get () { //���������� �� ������ �����
	
	setlocale(0, "Russian");
		string names;
		int score;
	while (cin && names!="noname" && score!=0) { //����� �� ����� ��� noname 0
		cout << "������� ��� � ����\n";
		cin >> names >> score;
		if (names!="noname"&&score!=0) tl.push(names,score);
		cout << tl.NS.size();
		}
	return namesandscore(names, score);
	}
int main () //����� �����
try {
	ts.get();
	tl.back();
	keep_window_open ("~~");
}
catch (exception& e) {
	cerr << e.what() << endl;
	keep_window_open("!");
	}
catch (...) {
	cerr << "Ups...." << '\n';
	keep_window_open("!");
	}