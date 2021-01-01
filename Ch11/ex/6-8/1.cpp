#include <std_lib_facilities.h>

const char space = ' '; 
const string not_a_reading = "&().;,:!?-'1234567890\""; 
const string adress = "D:\\Programms\\Ch11\\ex\\6\\data\\1.txt";

void letter_up (string& s)
{
	s[0] = toupper(s[0]);
}


fstream read_file (const string& filename){
	fstream ist {filename,ios_base::in};
	if (!ist) error ("Cant open file");
	return ist;
}
fstream write_file (const string& filename){
	fstream ist {filename,ios_base::out};
	if (!ist) error ("Cant open file");
	return ist;
}

void convert (string& s)
{
	if (s=="don't") s="do not";

if (s=="doesn’t") s = "does not"; 		if (s=="didn’t") s = "did not"; 
if (s=="won’t") s = "will not"; 		if (s=="’ll") s = " will"; 
if (s=="shouldn't") s = "should not";	if (s=="can’t") s = "cannot";
if (s=="couldn’t") s = "could not"; 	if (s=="mustn’t") s = "must not"; 
if (s=="oughtn’t") s = "ought not";		if (s=="’m") s = "am";
if (s=="’re") s = "are"; 				if (s=="’s") s = "is ";
if (s=="aren’t") s = "are not"; 		if (s=="isn’t") s = "is not";
if (s=="wasn’t") s = "was no"; 			if (s=="weren’t") s = "were not";
if (s=="’ve") s = "have";				if (s=="’s") s = "has";
if (s=="haven’t") s = "have not";		if (s=="hasn’t") s = "has not";
if (s=="’d") s = "had";					if (s=="hadn’t") s = "had not";
if (s=="’d") s = "would";				if (s=="wouldn’t") s = "would not"; 
if (s=="shouldn’t") s = "should not"; 	if (s==" ") s="";
}


bool is_translate_to_scape (const char& s) {
	 
	for (char ch : not_a_reading) if (s==ch) return true;
	return false;
}

void reducing ()
{
	string big_s;
	fstream ist = read_file(adress);
	for (string s; ist >> s;) 
	{
		convert(s);
		letter_up (s);
		big_s=big_s + s + "\n";
	}

	fstream ost = write_file(adress);
	ost << big_s; 
}

fstream& operator >> (fstream& ist, string& s){
	reducing ();
	for (char c; ist.get(c);) 
	{
	if (is_translate_to_scape(c)) c=space;
	s+=c;
	} 
	return ist;
}
int main () try {
 
	fstream ist = read_file(adress);
	string s; 
	ist >> s;
	fstream ost = write_file(adress);
	ost << s; ;

}
catch (exception& e) {
	cerr << e.what () << '\n';
	keep_window_open();
}










