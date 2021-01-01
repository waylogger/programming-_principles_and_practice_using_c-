#include <std_lib_facilities.h>

class Name_pairs { 														// class Name_pairs
private:
vector<string>names;
vector<double>age;
public:
void read_names();
void read_ages();
vector<string>see_names = {names};
vector<double>see_age = age;
void print(vector<string>&); 
void print(vector<double>);
void print(vector<string>&,vector<double>&);							// выводит name[i],age[i];
};																		// class Name_pairs

void Name_pairs::read_names()
{ 																		//read_names()
setlocale(0,"Russian");
cout << "¬ведите имена, дл€ завершени€ введите 0" << '\n';
string name = " ";
while (name!="0") 
	{ 																	//цикл while
cin >> name;
if (name!="0")names.push_back(name);
cout << "≈щЄ!"  <<"\n";

	} 																	//цикл while
sort (names.begin(),names.end());
} 																		//read_names()

void Name_pairs::read_ages() 
{ 																		//read_ages() 
	setlocale(0, "");
	cout << "Введите возраст для следующих имён\n";
	double ages = 0;  
	for (int i =0;i<names.size();++i)
	{ 																	//for
	cout << names[i] << ' ';
	cin >> ages;
	age.push_back(ages);
	}  																	//for
} 																		//read_ages() 

void Name_pairs::print(vector<string>&, vector<double>&) 
{																		//print(vector<string>)
for (int i =0; i<names.size();++i) {cout << names[i] 
										 << " - "
										 <<  age[i]
										 << '\n';}

} 																		//print(vector<string>)

int main () 
{ 																		//main
Name_pairs a;
a.read_names();
a.read_ages();
a.print(a.see_names, a.see_age);
keep_window_open();


}																		 //main
