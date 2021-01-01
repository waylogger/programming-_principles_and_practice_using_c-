
#include <std_lib_facilities.h>

int main ()
try
{
	setlocale(LC_ALL, "Russian"); // язык
	
		
	string a = " "; // отгадка
	int reg = 0; // режим
	int next = 0; //следующее слово
	int kows = 0; // коровы
	int bulls = 0; // быки
	int n = 0; // Начальное значение = seed 
	//Счетчики
	int i2 = 0;
		
	
	
	
	while (reg!=2)
	{
	vector<char>randchar = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o',
	'p','q','r','s','t','u','v','w','z','w','z'};
	
	int ib1 = 0; // случайная цифра №1
	int ib2 = 0; // случайная цифра №2
	int ib3 = 0; // случайная цифра №3
	int ib4 = 0; // случайная цифра №4
	
	string sb1 = " "; //строковая загадка №1
	string sb2 = " "; //строковая загадка №2
	string sb3 = " "; //строковая загадка №3
	string sb4 = " "; //строковая загадка №4
	int n =0;
	
	cout << "Insert number\n";
	setlocale(LC_ALL, "Russian"); // язык
	cin >> n;
	
	srand(n+11+96-32/65);
	ib1 = rand () %10;
	sb1=randchar[ib1];
	
	srand(n*n/32*994);
	ib2 = rand () %10;
	sb2=randchar[ib2];
	
	
	srand(n+5+11*n/n*n+64);
	ib3 = rand () %10;
	sb3=randchar[ib3];
		
	srand(n-18+6594-964*n/n);
	ib4 = rand () %10;
	sb4=randchar[ib4];
	n=n*n/n+6/2+2-4*11;
	sb1=sb1+sb2+sb3+sb4;
		
		
		cout << "1 - Play, 2 - exit \n";
		cin >> reg;
			while (reg!=1&&reg!=2)
			{
				cout << "Uncorrect value, try again \n";
				cin >> reg;
				if (reg==2) error ("Прощай\n");
			}
			;
			cout << "What number>?\n";
			while (a!="help")
			{
			cout << sb1 << "\n";
			cin >> a;
				while (a.size ()!=4)
				{
					cout << "Uncorrect value, try again \n";
					cin >> a;
				}
			for (int i =0; i<4; ++i) 
				{
					if (sb1[i]==a[i]) ++bulls;
					for (int i2 = 0; i2<4; ++i2) 
						if (a[i]==sb1[i2]
							&&a[i]!=a[i-1]
							&&a[i]!=a[i-2]
							&&a[i]!=a[i-3]) 
							++kows;
				}
			if (a!="help") cout << "Bulls = " << bulls << "\n";
			if (a!="help") cout << "Kows = " << kows << "\n";
			if (a!="help"&&kows==4) cout << "GZ. you are find all cows!!!\n";
			if (a!="help"&&kows>0&&kows<4) cout << "You are find cow -  "
									 << kows << "\n";
			if (a!="help"&&kows==0) cout << "You are dont find any cow\n";
			if (a!="help"&&bulls>0&&bulls<4) cout << "You are find bull -   "
									 << bulls << "\n";
			if (a!="help"&&bulls==4) 
			{
				cout << "GZ, you are find all bull!!!\n";
				
				
	cout << "Insert number\n";
	cin >> n;
	
	srand(n+11+96-32/65);
	ib1 = rand () %10;
	sb1=randchar[ib1];
	
	srand(n*n/32*994);
	ib2 = rand () %10;
	sb2=randchar[ib2];
	
	
	srand(n+5+11*n/n*n+64);
	ib3 = rand () %10;
	sb3=randchar[ib3];
		
	srand(n-18+6594-964*n/n);
	ib4 = rand () %10;
	sb4=randchar[ib4];
	n=n*n/n+6/2+2-4*11;
	sb1=sb1+sb2+sb3+sb4;
			}
			if (a!="help"&&bulls==0) cout << "You are dont find any bull\n";
			bulls=0;
			kows =0;
			}
			
			
		
	}
	
}
				
		


catch (exception& e)
{
cerr << e.what ();
}