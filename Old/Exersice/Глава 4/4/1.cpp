#include <std_lib_facilities.h>

int main () {

string b = " "; // переменная отвечающая за 50
string c = " "; // переменная отвечающая за 75
string d = " "; // переменная отвечающая за 25
string f = " "; // переменная отвечающая за четность/нечетность
string e = "no"; // переменная отвечающая за правильность догадки
int i = 0; // переменная-счетчик цикла

//..........................финальные ветвления
string h_1 = " "; 
string h_2 = " ";
string h_3 = " ";
string h_4 = " ";
string h_5 = " ";
string h_6 = " ";
string h_7 = " ";
string h_8 = " ";
//..........................


//........................вводим массивы по 6-7 чисел;

//..........................
vector <int> a_1;
	a_1.push_back (88);
	a_1.push_back (90);
	a_1.push_back (92);
	a_1.push_back (94);
	a_1.push_back (96);
	a_1.push_back (98);
	a_1.push_back (100);

vector <int> a_2;
	a_2.push_back(76);
	a_2.push_back(78);
	a_2.push_back(80);
	a_2.push_back(82);
	a_2.push_back(84);
	a_2.push_back(86);

vector <int> a_3;
	a_3.push_back (87);
	a_3.push_back (89);
	a_3.push_back (91);
	a_3.push_back (93);
	a_3.push_back (95);
	a_3.push_back (97);
	a_3.push_back (99);

vector <int> a_4;
	a_4.push_back (75);
	a_4.push_back (77);
	a_4.push_back (79);
	a_4.push_back (81);
	a_4.push_back (83);
	a_4.push_back (85);

//..........................
vector <int> a_5;
	a_5.push_back (62);
	a_5.push_back (64);
	a_5.push_back (66);
	a_5.push_back (68);
	a_5.push_back (70);
	a_5.push_back (72);
	a_5.push_back (74);


vector <int> a_6;
	a_6.push_back (50);
	a_6.push_back (52);
	a_6.push_back (54);
	a_6.push_back (56);
	a_6.push_back (58);
	a_6.push_back (60);
	

vector <int> a_7;
	a_7.push_back (63);
	a_7.push_back (65);
	a_7.push_back (67);
	a_7.push_back (69);
	a_7.push_back (71);
	a_7.push_back (73);

vector <int> a_8;
	a_8.push_back (51);
	a_8.push_back (53);
	a_8.push_back (55);
	a_8.push_back (57);
	a_8.push_back (59);
	a_8.push_back (61);

//..........................
vector <int> a_9;
	a_9.push_back (38);
	a_9.push_back (40);
	a_9.push_back (42);
	a_9.push_back (44);
	a_9.push_back (46);
	a_9.push_back (48);

vector <int> a_10;
	a_10.push_back (26);
	a_10.push_back (28);
	a_10.push_back (30);
	a_10.push_back (32);
	a_10.push_back (34);
	a_10.push_back (36);

vector <int> a_11;
	a_11.push_back (37);
	a_11.push_back (39);
	a_11.push_back (41);
	a_11.push_back (43);
	a_11.push_back (45);
	a_11.push_back (47);
	a_11.push_back (49);

vector <int> a_12;
	a_12.push_back (25);
	a_12.push_back (27);
	a_12.push_back (29);
	a_12.push_back (31);
	a_12.push_back (33);
	a_12.push_back (35);

//..........................
vector <int> a_13;
	a_13.push_back (12);
	a_13.push_back (14);
	a_13.push_back (16);
	a_13.push_back (18);
	a_13.push_back (20);
	a_13.push_back (22);
	a_13.push_back (24);

vector <int> a_14;
	a_14.push_back (0);
	a_14.push_back (2);
	a_14.push_back (4);
	a_14.push_back (6);
	a_14.push_back (8);
	a_14.push_back (10);

vector <int> a_15;
	a_15.push_back (13);
	a_15.push_back (15);
	a_15.push_back (17);
	a_15.push_back (19);
	a_15.push_back (21);
	a_15.push_back (23);

vector <int> a_16;
	a_16.push_back (1);
	a_16.push_back (3);
	a_16.push_back (5);
	a_16.push_back (7);
	a_16.push_back (9);
	a_16.push_back (11);

//..........................Всего заданы 16 массивов. Принцип следующий. Программа должна задать 5 вопросов: 1. Больше ли число "50"? 2. Если да, то больше ли 75? 3. Если нет, то больше ли 25? 4. Четное оно? 5. Больше ли оно медианы? В зависимости от соотношения ответов на указанные 5 вопросов программа определит необходимый набор чисел, в котором в вероятностью 1/6-7 содержится правильный ответ.


cout << "Zagadai chislo ot 0 do 100\n";
cout << "Chislo=>50?\n";
cin >> b;
//..........................
//..........................
//..........................вводим блок b
if (b=="yes") 
	cout << "\nChislo=>75?\n"; 
if (b=="yes") 
cin >> c;

if (b=="no")
	cout << "\nChislo=>25?\n";
if (b=="no")
	cin >> d;

//..........................вводим блок c
//..........................
//..........................

if (c=="yes")
	cout << "\nChetnoye?\n";
if (c=="yes") 
	cin >> f;

if (c=="no")
	cout << "\nChetnoye?\n";
if (c=="no") 
	cin >> f;

//..........................вводим блок d
//..........................
//..........................

if (d=="yes")
	cout << "\nChetnoye?\n";
if (d=="yes") 
	cin >> f;

if (d=="no")
	cout << "\nChetnoye1?\n";
if (d=="no") 
	cin >> f;

//..........................
//..........................
//..........................вводим блок f

//..........................

if (f=="yes"&&b=="yes"&&c=="yes")
	cout << "\nono=>88\n";
if (f=="yes"&&b=="yes"&&c=="yes")
	cin >> h_1;

if (f=="no"&&b=="yes"&&c=="yes")
	cout << "\nono=>87\n";
if (f=="no"&&b=="yes"&&c=="yes")
	cin >> h_2;
//..........................

if (f=="yes"&&b=="yes"&&c=="no")
	cout << "\nono=>62\n";
if (f=="yes"&&b=="yes"&&c=="no")
	cin >> h_3;

if (f=="no"&&b=="yes"&&c=="no")
	cout << "\nono=>63\n";
if (f=="no"&&b=="yes"&&c=="no")
	cin >> h_4;

//..........................

if (f=="yes"&&b=="no"&&d=="yes")
	cout << "\nono=>38\n";
if (f=="yes"&&b=="no"&&d=="yes")
	cin >> h_5;

if (f=="no"&&b=="no"&&d=="yes")
	cout << "\nono=>37\n";
if (f=="no"&&b=="no"&&d=="yes")
	cin >> h_6;

//..........................

if (f=="yes"&&b=="no"&&d=="no")
	cout << "\nono=>12\n";
if (f=="yes"&&b=="no"&&d=="no")
	cin >> h_7;

if (f=="no"&&b=="no"&&d=="no")
	cout << "\nono=>13\n";
if (f=="no"&&b=="no"&&d=="no")
	cin >> h_8;

//..........................вводим блок h_n

if (h_1=="yes")

while (e=="no") 
{
cout << "\nVi zagadali - " << a_1[i] << " ?\n";
++i;
cin >> e; 
};

if (h_1=="no")

while (e=="no") 
{
cout << "\nVi zagadali - " << a_2[i] << " ?\n";
++i;
cin >> e; 
}; 
//..........................
if (h_2=="yes")

while (e=="no") 
{
cout << "\nVi zagadali - " << a_3[i] << " ?\n";
++i;
cin >> e; 
};

if (h_2=="no")

while (e=="no") 
{
cout << "\nVi zagadali - " << a_4[i] << " ?\n";
++i;
cin >> e;
};
//..........................
if (h_3=="yes")

while (e=="no") 
{
cout << "\nVi zagadali - " << a_5[i] << " ?\n";
++i;
cin >> e; 
};

if (h_3=="no")

while (e=="no") 
{
cout << "\nVi zagadali - " << a_6[i] << " ?\n";
++i;
cin >> e;
};

//..........................
if (h_4=="yes")

while (e=="no") 
{
cout << "\nVi zagadali - " << a_7[i] << " ?\n";
++i;
cin >> e; 
};

if (h_4=="no")

while (e=="no") 
{
cout << "\nVi zagadali - " << a_8[i] << " ?\n";
++i;
cin >> e;
};

//..........................
if (h_5=="yes")

while (e=="no") 
{
cout << "\nVi zagadali - " << a_9[i] << " ?\n";
++i;
cin >> e; 
};

if (h_5=="no")

while (e=="no") 
{
cout << "\nVi zagadali - " << a_10[i] << " ?\n";
++i;
cin >> e;
};

//..........................
if (h_6=="yes")

while (e=="no") 
{
cout << "\nVi zagadali - " << a_11[i] << " ?\n";
++i;
cin >> e; 
} ;

if (h_6=="no")

while (e=="no") 
{
cout << "\nVi zagadali - " << a_12[i] << " ?\n";
++i;
cin >> e;
};

//..........................
if (h_7=="yes")

while (e=="no") 
{
cout << "\nVi zagadali - " << a_13[i] << " ?\n";
++i;
cin >> e; 
};

if (h_7=="no")

while (e=="no") 
{
cout << "\nVi zagadali - " << a_14[i] << " ?\n";
++i;
cin >> e;
};

//..........................
if (h_8=="yes")

while (e=="no") 
{
cout << "\nVi zagadali - " << a_15[i] << " ?\n";
++i;
cin >> e; 
};

if (h_8=="no")

while (e=="no") 
{
cout << "\nVi zagadali - " << a_16[i] << " ?\n";
++i;
cin >> e;
};
keep_window_open ();
}

