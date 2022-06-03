#include"String.h"



//#define CONSTRUCTOR_CHECK
#define MOVE_METODS_CHECK
//#define COLLING_CNSTRUCTOR

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTOR_CHECK
	String str1;   //Default constructor
	str1.print();

	String str2(5); // explicit Single-argument constructor
	str2.print();

	String str3 = "Hallo";
	str3 = str3;
	str3.print();

	String str4 = str3; //CopyConstructor
	str4.print();

	String str5;   //CopyAssignment
	str5 = str4;
	str5.print();
#endif // CONSTRUCTOR_CHECK

#ifdef MOVE_METODS_CHECK
	String str1 = "Hello";
	String str2("World");
	//String str3 = str1 + str2;//Mova Constructor
	//str3.print();
	String str3;
	str3 = str1 + str2;
	cout << str3 << endl;

	//cout << "Введите строку: "; cin >> str1;
	//cout << str1 << endl;

	//String str1 = "Hello";
	//String str2("World");
	str1 += str2;
	cout << str1 << endl;
#endif // MOVE_METODS_CHECK


#ifdef COLLING_CONSTRUCTOR
	String str1;
	String str2(55);
	String str3 = "Hello";
	String str4 = str3;

	String str5;
	str5 = str4;
	String str6();
	str7.print();
#endif // COLLING_CONSTRUCTOR

}