/*
Antonuyk I.V. 29/04/2018

Stariy Oskol

Binary.h

My_bynary_search
*/
#ifndef MY_BINARY_H
#define MY_BIMARY_H

#include <iostream>
#include <vector>
using namespace std;

namespace MY{
template 	< typename RandomAccessIterator, typename Elem >
bool		binary_search(RandomAccessIterator begin, RandomAccessIterator end, const Elem& elem){
	
	if ( begin == end ){
		return false;
	}
	
	if ( ( *begin > elem ) || ( *(end-1) < elem) )
							return false;
	auto left = begin;
	auto right = end;
	while ( true ) {
		int number_of_elem = &right[0]-&left[0];
		int focus = number_of_elem/2;
		if ( *( left + focus ) == elem ){	
							return true;
		}
		else if ( *( left + focus ) > elem ){
					if ( *( left + focus - 1 ) == elem ){
							//cout << *( left + focus - 1 ) << '\n';
							return true;
					}
					else if ( *( left + focus - 1 ) < elem)
							return false;	
					else 
							right = right - focus;
		}
		else if ( *( left + focus ) < elem ){	
					if ( *( left + focus + 1 ) == elem ){
							//cout << *( left + focus + 1 ) << '\n';
							return true;
					}
					else if ( *( left + focus + 1) > elem ){
							return false;
					}					
					else
							left = left + focus;			
		}	
	}	
	return false;
}

} // End of namespace
#endif