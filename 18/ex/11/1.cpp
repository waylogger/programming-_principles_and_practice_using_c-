#include <D:\\Programms\\18\\11\\Skip_list.cpp>








int main ()
try
{
	Skip_list* sl = new Skip_list{nullptr};

	for (int i = 0; i < 10000; ++i)
	{
		sl->insert(new Link{i});
	}
	
	//print(sl->get_list());
	
	end();






	
}

catch (Link_exceptions& e)
{
	cout << e.what << '\n';
	end();
}

catch (SL_exc& e)
{
	cout << e.what() << '\n';
	end();
}


catch(...)
{
	cout << "WTF???" << '\n';
	end();
}
