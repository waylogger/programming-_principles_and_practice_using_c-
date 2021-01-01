// »мена и баллы

#include <std_lib_facilities.h>

class namesandscore {
	public:
	string names;
	int score;
	namesandscore(string n, int s) : names(n), score(s) { }
};
class streams {
	public:
	vector<namesandscore>NS;
	void get_names (string a);
	void set_names (string a, int b);
};
class Token_stream {
	public:
	namesandscore get();
};

Token_stream ts;

void set_names(string a, int b);

namesandscore Token_stream::get() {
	while (cin) {
		string names;
		int score;
		cin >> names;
		cin >> score;
		set_names(names, score);
		return namesandscore(names, score);
	}
	};
	
 void streams::get_names(string a) {
	for (int i = 0; i<NS.size(); ++i) cout << NS[i].names << "-" << NS[i].score << "\n";
	return;
};

void streams::set_names(string a, int b) {
	setlocale(0, "");
	
	for (int i = 0; i<NS.size(); ++i) {
		if (NS[i].names==a) error ("Повторное имя");
		else NS.push_back(namesandscore(a,b));
	return;
	}
};

int main () {
}



/*

int main () 
try
{
	
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
*/
