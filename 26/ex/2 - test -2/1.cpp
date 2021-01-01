/*
Antonuyk I.V. 30/04/2018

Stariy Oskol

PPP C++ B.Stroustrup
ex. 26.2
*/
#include <		iostream	>
#include <		string		>
#include <		vector		>
#include <		regex		>
#include <		sstream		>
#include <		fstream		>
#include <		C:\\Programms\\26\\task\\binary.h	>
using namespace std;


//----------------------------------------------------------------------


template < typename T >
struct Test{
	string 		pat;
	string 		seq_pat;
	string 		label;
	T 			val;
	vector<T>	seq;
	bool 		res;
	
	void 		init_seq		(const string& s);
};

//----------------------------------------------------------------------


template < typename T >
void Test< T > :: init_seq ( const string & s ) {
	if ( seq_pat.size() == 0 ){
		cout << "Cant find pat for sequence\n";
		return;
		}

	string 		line 		= s;
	regex 		reg			{seq_pat};
	smatch 		match;
	
	while( regex_search( line, match, reg ) ) {
		seq.push_back( from_string_to< T >( match[0] ) );
		line = match.suffix();
	}
	
	std::sort(seq.begin(),seq.end());
			
}


//----------------------------------------------------------------------


template < typename T >
T from_string_to ( const string & s ){
	ostringstream 		ost;
						ost << s;
	istringstream 		ist{ost.str()};
	T 					t;
						ist >> t;
	return t;
	
}


//----------------------------------------------------------------------



template < typename T >
T from_string_to( const string & s, T & t ){
	ostringstream 		ost;
						ost << s;
	istringstream 		ist{ost.str()};
						ist >> t;
	return t;
	
}


//----------------------------------------------------------------------



template < typename T >
istream & operator >> ( istream & ist, Test< T > & t){
		
	if ( t.pat.size() == 0 ){
		cout << "Cant find the pattern to this test\n";
		return ist;
	}
	
	regex reg 				{ t.pat };
	smatch					match;
	string					raw_material;
	string 					line;

	getline					( ist, line );
	regex_match				( line, match, reg);
	
	t.label 				= match[1];
	t.val 					= from_string_to< T >( match[2] );
	t.init_seq				(match[3]);
	int r 					= from_string_to< int >( match[4] );
	
	if (r == 0)
							t.res = false;
	else 
							t.res = true;	
	return ist;
}


//----------------------------------------------------------------------



template < typename T >
ostream & operator << ( ostream & ost, const Test< T > & t){
	
						ost << '{' << '\t' << t.label << '\t' 
							<< t.val << '\t' << '{' << '\t';
							
	for ( int i = 0; i < t.seq.size(); ++i ){
		
						ost << t.seq[i] << ' ';
	}
						ost << '\t' << '}' << '\t';
	if (t.res)
						{ost << "true";}
	else 
						{ost << "false";}
						ost << '\t' << '}';
	
	
	return ost;
}


//----------------------------------------------------------------------


vector< string > get_pattern_from_file( const string& file_pat ){
	
		ifstream ifs 			{ file_pat };
		vector<string> 			pats;
			
		if ( !ifs ){
								cout << "Cant open file\n";
								return pats;
		}
		
		string 					s;
		while( getline( ifs,s ) ){ 
			//cout << s << '\n';
			pats.push_back( s );
		}
		return pats;													
	}
	
	
//----------------------------------------------------------------------
	
	
template < typename T >
vector< Test < T > > get_tests_from_file( const string & pat_file, const string & data_file ){
	vector< Test < T > > 			tests;
	
	vector< string > 				pats = get_pattern_from_file( pat_file );
	if ( pats.size() != 2){
									cout << "Expect 2 patterns\n";
									return tests;
	}
	
	ifstream 						ifs {data_file};
	if ( !ifs ){
									cout << "Cant open file\n";
									return tests;
	}
	for ( string s; getline( ifs,s ); ){
		Test<T> 					t;
		t.pat 						= pats[0];
		t.seq_pat 					= pats[1];
		t 							= from_string_to< Test < T > >( s,t );	
									tests.push_back(t);
	}
									return tests;
}


//----------------------------------------------------------------------


template < typename T >
void testing( vector< Test < T > > & tests , const string& file){
	
	ofstream ofs {file};
	
	if(!ofs) {
		cout << "Cant open file\n";
		return;
	}
	
	for ( int i = 0; i <  tests.size(); ++i ){
		ofs			<< "---------------------------------------------------------------------------\n";
		ofs			<< "Testname: " << tests[i].label 		<< '\n'
					<< "Find: "		<< tests[i].val 		<< '\n'
					<< "in sequence";
		if 			( tests[i].seq.size() > 10 ){
					ofs			<< " with " << tests[i].seq.size() << " elements\n";
		}
		
		else{
		ofs			<< ":\n";
					for ( int j = 0; j < tests[i].seq.size(); ++j ){
								ofs			<< tests[i].seq[j] << ' ';
					}
		ofs			<< "\n";
		ofs			<< "Expect: ";
		if			(tests[i].res)
								{ofs			<< "true\n";}
		else				
								{ofs			<< "false\n";}
		}
	ofs			<< "---------------------------------------------------------------------------\n";
	
		if			(MY::binary_search( tests[i].seq.begin(),tests[i].seq.end(),tests[i].val) == tests[i].res ){
				ofs << "\t\t\t\t\t\t\tTest is compited\n";	
		}
		else
				ofs	<< "\t\t\t\t\t\t\tTest is failed\n";	
	}
	
	ofs			<< "---------------------------------------------------------------------------\n";
}

int main(){
	
	auto tests = get_tests_from_file<double>("C:\\data\\pats for double.txt","C:\\data\\tests for double.txt");
	
	testing(tests,"C:\\data\\res of double.txt");
	

}