#include <D:\\Programms\\22\\15 - name pair\\history_guard.h>


void lang_history::exception_primary(const char c) try {
	//----------------------------------------------------
	throw lang_history::Bad_primary(c);
	//----------------------------------------------------
}
	catch(lang_history::Bad_primary& e)	{
	std::cerr << e.what() << '\n';
	}

//---------------------------------------------------


void lang_history::destroyed_expectations(const char expect) try{
	throw lang_history::Destroyed_expectations (expect);
}
	catch(lang_history::Destroyed_expectations& e){
	std::cerr << e.what() << '\n';
}


//----------------------------------------------------


void lang_history::destroyed_expectations(const string expect) try{
	//----------------------------------------------------
	throw lang_history::Destroyed_expectations (expect);
	//----------------------------------------------------
}
	catch(lang_history::Destroyed_expectations& e){
	std::cerr << e.what() << '\n';
}

//----------------------------------------------------




























