#include <std_lib_facilities.h>

int main () {

	vector <string> words;
	for (string w; cin >> w;)
	words.push_back (w);

	cout << "Kolichestvo slov: " << words.size () << '\n';

	sort (words);
	for (int i = 0; i<words.size (); ++i)

	if (i==0 || words[i-1]!=words [i])
	cout << words [i] << "\n";

keep_window_open ();
}