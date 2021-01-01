/*


Antonyuk I.V. 30/04/2018
Stariy Oskol

PPP C++ B. Stroustrup

ex.26.3

*/


#include <My\\binary.h>
#include <My\\test.h>

using namespace std;
using MY::Test;

bool compare( const int a, const int b ){
	return a  <  b ;
}



int main(){
	
	vector  < Test < int > > v1 = MY::get_tests_from_file< int >(
		"C:\\data\\int\\pats.txt",
		"C:\\data\\int\\tests.txt"
	);
	
	testing(
		v1,
		"C:\\data\\int\\res.txt",
		compare
	);
	
	
	
	char end;
	cin >> end;
}