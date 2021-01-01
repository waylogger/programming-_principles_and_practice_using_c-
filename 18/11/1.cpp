#include <D:\\Programms\\18\\11\\Skip_list.cpp>








int main ()
try
{
	Skip_list* sl = new Skip_list{nullptr};
while (true)
{
	for (int i = 0; i < 10; ++i)
	{
		sl->insert(new Link{i});
	}
	
	Link* e = sl->get_list()->sub_zero();
	
	
	while (e->next()) e = e->next();
	sl->set_list(e);
	
	while (sl->get()) sl->erase();
}






	
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
