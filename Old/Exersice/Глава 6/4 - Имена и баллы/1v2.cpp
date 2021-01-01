// »мена и баллы

#include <std_lib_facilities.h>

class Name_value
{
	public:
	string names;
	int scores;
	private:
};





int main () 

try
{
setlocale(0, "Russian");
Name_value ns;

vector<Name_value>NV;
cout << "Введите имена и количество баллое \n Для выхода из режима ввода введите Имя - Noname, Количество баллов - 0\n";
while (ns.names != "noname" && ns.scores !=0)
{
	cin >> ns.names >> ns.scores;
	if (ns.names != "noname" && ns.scores !=0) NV.push_back(ns);
}
for (int i =0; i<NV.size(); ++i)
	cout	<< NV[i].names
			<< "  " << NV[i].scores << "\n";
			keep_window_open("~");



}
catch (runtime_error e) 
{
	cout << e.what () << '\n';
	keep_window_open ("~");
}
catch (...) {
	cout << "Exiting\n"; 
	keep_window_open ("~");
}

