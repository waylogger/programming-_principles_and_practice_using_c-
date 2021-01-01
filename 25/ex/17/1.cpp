/*
Antonyuk I.V. 26/04/2018

Road from N.Novgorod to Moskow

PPP C++ B.Stroustrup

ex.25.17

*/

#include <iostream>
#include <vector>

using namespace std;


template <typename T>
class Array_ref{
	private:
	T* pointer;
	int sz;
	public:
	Array_ref		();
	Array_ref		(T* ptr, int s);
	
	T& 			operator[]		( const int n ) 		{ return pointer[n]; }
	const T& 	operator[]		( const int n ) const 	{ return pointer[n]; }

	bool 		assign			( const Array_ref ar );
	void 		reset			( Array_ref ar )			{ reset(ar.pointer,ar.size); }
	void		reset			( T* pp, int s )			{ pointer = pp; sz = s;}

	
	template <typename Q>
				operator 		const Array_ref<const Q>(){
		static_cast<Q>(*static_cast<T*>(nullptr));
		
		return Array_ref<const Q> (reinterpret_cast<Q*>(pointer),sz);
	}
};

//------------------------------------------------------------------

template <typename T>
Array_ref<T>::Array_ref() : pointer{nullptr}, sz{0} {}

//------------------------------------------------------------------

template <typename T>
Array_ref<T>::Array_ref(T* ptr, int s) : pointer{ptr}, sz{s} {	}

//------------------------------------------------------------------

template <typename T>
bool Array_ref<T>::assign(const Array_ref<T> ar){
	
	if ( sz != ar.sz )
					return false;
	
	for ( int i = 0; i < ar.sz; ++i ){
					pointer[i] = ar.pointer[i];
 	}
					return true;
}

//------------------------------------------------------------------

template <	typename T	>
Array_ref<T> 	make_ref	( vector<T>& v ){
	
	
	return (v.size()) 	? Array_ref<T>(&v[0],v.size())
						: Array_ref<T>(0,0);	
}

//------------------------------------------------------------------

template < typename T,int s	>
Array_ref<T> make_ref(T(&pp)[s]){
	
	return Array_ref<T>(pp,s);
	
}




struct Some_parent{

virtual void vfun(){
	cout << 5;
}
};

struct Some_child : Some_parent {
	void vfun() override{
		cout << 6;
	}
	

};


struct Lucius : Some_parent{
	
	void vfun() override{
		cout << 666;
	}
};


void f(const Array_ref<Some_parent*const> sp) {
	sp[0]->vfun();
	//Lucius* ls = sp[0];
	cout << sp[0];
}

int main()try {
	
	
	vector<Some_child*>sc;
	sc.push_back(new Some_child{});
	
	f(make_ref(sc));
	
	char end;
	cin >> end;
}


catch(...){
	
	
	char end;
	cin >> end;	
}









