/*
Antonuyk I.V.

01/05/2018
Старый Оскол

PPP C++ B.Stroustrup
ex. 26.4


*/

#include 		<		iostream		>
#include 		<		sstream			>
#include 		<		fstream			>
#include 		<		string			>
#include 		<		vector			>
#include 		<		regex			>
#include		<		My\\test.h		>

namespace MY{
	
//-------------------------------------------------------------------

template <typename T>
struct Complex_test{
	std::vector			<	T		>			seq;
	std::string 								label;
	
	struct Val_res{
		T val;
		bool res;
		
		Val_res(const T& v) : val{v}, res{false} {}
	};
	
	std::vector			<	Val_res	>			val_res;

	std::string 			common_pat;
	std::string 			seq_pat;
	std::string				res_pat				=R"([1|0])";
	
	void					init_seq			( const std::string & s );
	void					init_val			( const std::string & s );
	void 					init_res			( const std::string & s );
	
};

//-------------------------------------------------------------------


template <typename T>
void Complex_test<T>::init_seq( const std::string & s ){
	std::regex				reg		{ seq_pat };
	std::string				line 	= s;
	std::smatch				match;
	
	while					( regex_search ( line,match,reg ) ) {
							seq.push_back( MY::from_string_to < T > ( match[0] ) ) ;
							line = match.suffix();
	}
}

//-------------------------------------------------------------------


template <typename T>
void Complex_test<T>::init_val( const std::string & s ){
	
	std::regex				reg		{ seq_pat };
	std::string				line 	= s;
	std::smatch				match;
	
	while					( regex_search ( line,match,reg ) ) {
							val_res.push_back( Val_res ( MY::from_string_to < T > ( match[0] ) ) );
							
							line 	= match.suffix();
	}
}

//-------------------------------------------------------------------

template <typename T>
void Complex_test<T>::init_res( const std::string & s ){
	
	std::regex				reg		{ res_pat };
	std::string				line 	= s;
	std::smatch				match;
	
	for						( int i = 0; regex_search ( line,match,reg ) ; ++i) {
							val_res[i].res = MY::from_string_to < bool > ( match[0] ) ;
							line 	= match.suffix();
	}

}

//-------------------------------------------------------------------

template <typename T>
std::istream& operator >> (std::istream& ist, Complex_test<T>& test){
	

	if					(	test.common_pat.size() 	== 0 || 
							test.seq_pat.size() 	== 0
						){
						
						std::cout << "Cant find patterns\n";
						return ist;
	}
	
	std::regex			reg{test.common_pat};
	std::string			line;
	std::smatch			match;
	
	std::getline		(ist,line);
	if (std::regex_match(line,match,reg)){
		test.label 				= match[1];
		test.init_val			( match[2] );
		test.init_seq			( match[3] );
		test.init_res			( match[4] );
	}
	

						return ist;
}


//-------------------------------------------------------------------

template < typename T >
std::ostream & operator << ( std::ostream & ost, Complex_test < T > & test ){
	
	
				  ost << '{' << '\t' << test.label << '\t';
	for ( int i = 0; i < test.val_res.size(); ++i )
				{ ost << test.val_res[i].val << ' ';}
	
				  ost << '\t' << '{' << '\t';
	
	for ( int i = 0; i < test.seq.size(); ++i )
				{ ost << test.seq[i] << ' ';}
			
				ost << '\t' << '}' << '\t';
	for ( int i = 0; i < test.val_res.size(); ++i )
				{ ost << test.val_res[i].res << ' '; }
				  ost << '\t' << '}';
	
						return ost;
}


//-------------------------------------------------------------------


template < typename T >
std::vector<  Complex_test < T > > get_cml_tests_from_file( const std::string& pat_file, const std::string& data_file ){
	std::vector<  Complex_test < T > > 		tests;
	
	std::vector< std::string> 		pats = get_pattern_from_file( pat_file );
	if ( pats.size() != 2){
									std::cout << "Expect 2 patterns\n";
									return tests;
	}
	
	std::ifstream 					ifs {data_file};
	if ( !ifs ){
									std::cout << "Cant open file\n";
									return tests;
	}
	
		
	for ( std::string s; getline( ifs,s ); ){
		
		 Complex_test< T > 			t;
		t.common_pat 				= pats[0];
		t.seq_pat 					= pats[1];
		t 							= from_string_to<  Complex_test < T > >( s,t );	
									tests.push_back(t);
	}
									return tests;
}


template <typename T>
void complex_testing(const std::string& s, std::vector<  Complex_test < T > > 	&tests){
	
	std::ofstream ofs {s};
	
	if (!ofs){
		std::cout << "Cant open file\n";
		return;
	}
	
	for ( int i = 0; i < tests.size(); ++i ){
		ofs << "Name of group: " <<  tests[i].label << '\n';
		for ( int j = 0; j < tests[i].val_res.size(); ++j ) {
			ofs << "Test #" << j << ": "<< '\t';
				if (
					MY::binary_search(tests[i].seq.begin(),tests[i].seq.end(),tests[i].val_res[j].val)
					== tests[i].val_res[j].res
				)	ofs << "pass\n";
				else
					ofs << "failed\n";
		}
		
	}	
}


} // end of namespace
int main(){
		
	auto ct = MY::get_cml_tests_from_file<int>("C:\\Data\\26\\4\\patterns.txt","C:\\Data\\26\\4\\tests.txt");
	
	complex_testing("C:\\Data\\26\\4\\res.txt",ct);
		
	char end;
	std::cin >> end;
}