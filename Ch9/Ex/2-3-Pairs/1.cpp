/*
����������� ���������:
*/
#include <std_lib_facilities.h>
class Name_pairs
{ 												//open class Name_pairs
private:
vector<string>names;
vector<double>ages;
int find_index(const string n);					//���� ������ ���������
public:
Name_pairs();									//�����������
void sort_pairs();								//����������
vector<string>see_names;
vector<double>see_ages;
}; 												//close class Name_pairs
Name_pairs::Name_pairs()
{ 												//open constructor Name_pairs
	setlocale(0,"");
	string name = " ";
	double age = 1;
	cout << "������� �����\n";
	
	while (name!="0") 
	{ 											//open while (name!=0)  
	cin >> name;
	if (name!="0") names.push_back(name);
	} 											//close while (name!=0)
	
	cout << "������� �������\n";
	while (ages.size()!=names.size())
	{ 											//open while (age!=0)
	cin >> age;
	if (!cin) { error ("Uncorrect type");}
	if (age!=0) ages.push_back(age);
	} 											//close while (age!=0)
}	 											//close constructor Name_pairs
void Name_pairs::sort_pairs()
{												// open Name_pairs::sort_pairs()
	
	vector<string>copy_names = names;
	vector<double>copy_ages = ages;
	see_names=names;
	see_ages=ages;
	sort(names.begin(),names.end());
	for (int i=0; i<copy_names.size();++i)
		{ 										//open for
			int a = find_index(copy_names[i]);  //��� ��������������� ������ ���������� "�" � �������������� �� �������� � ���� ������ ����� �� �������
			ages[i]=copy_ages[a];				//����������� ������� ������� �������� �� ��� �����, ������� ��������� ��� ��������� �������� 
		}  										//close for	
			
}												// clos Name_pairs::sort_pairs()

int Name_pairs::find_index(string n)
{												//open int Name_pairs::find_index(string s)
int x = 0;
for (int i =0; i<names.size();++i)
	{											//open for
	if (n==names[i]) return i;
	}											//close for
	return x;
}												//close int Name_pairs::find_index(string s)
bool operator == (const Name_pairs&a, const Name_pairs&b)
{
	for (int i = 0; i<a.see_names.size();++i) if (a.see_names[i]==b.see_names[i]) return true;
	return false;
}
bool operator != (const Name_pairs&a, const Name_pairs&b)
{
for (int i = 0; i<a.see_names.size();++i) if (a.see_names[i]!=b.see_names[i]) return true;
	return false;
}
ostream& operator << ( ostream& os, Name_pairs d)
{ 												//open ostream& operator
	
	for (int i =0; i<d.see_names.size();++i)
		{ 										//open for 
		cout    << d.see_names[i] << " - " 
				<< d.see_ages[i] << '\n';
		} 
												//close for
	return os; 
	
} 												//close ostream& operator
int main () 
try 
{ 												//open main ()
	while (true)
	{	//open while
	try 
		{										//open try									 
		Name_pairs np;
		np.sort_pairs();
		cout << np;
		keep_window_open();
		}										//close try
		catch (exception& e)
		{										//open catch
		cerr << e.what () << '\n';				// ����������������� ����� ������
		}										//close catch
		}										//close while
} 												//close main  
catch (exception& e)
{
	cerr << e.what () << '\n';
	keep_window_open("~~");
}
catch (...)
{
	cerr << "Ups...";
	keep_window_open("~~");
}






















