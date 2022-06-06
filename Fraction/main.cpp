#include"Fraction.h"

//#define CONSTRUCTOR_CHECK
//#define CONSTRUCTOR_CHECK2
//#define CONSTRUCTOR_CHECK3
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
//#define FULL_CONPARISON
//#define CONVERSION_FROM_CLASS_TO_OTHER
//#define DOUBLE_CONSTRUCTOR_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTOR_CHECK

	Fraction A;
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = C;
	E.print();

	A = D;
	A.print();
#endif // CONSTRUCTOR_CHECK

#ifdef CONSTRUCTOR_CHECK2
	Fraction A(2, 3, 4);
	Fraction B(19, 5);
	A.print();
	B.print();

	Fraction C = A * B;
	C.print();
#endif // CONSTRUCTOR_CHECK2

#ifdef CONSTRUCTOR_CHECK3
	Fraction A(2, 3);
	Fraction B(4, 5);
	A.print();
	B.print();
	Fraction K = A * B;
	K.print();

	Fraction C = A + B;//Сумма дробей
	C.print();

	Fraction D = A - B;//Вычитание
	D.print();

	Fraction E = A / B;//Деление
	E.print();

	Fraction F = C++;//Инкримент
	C.print();
	F.print();

	Fraction G = D--;//Декримент
	D.print();
	G.print();

	//ostream&(Fraction);
	//istream&(Fraction);

	Fraction I = A > B;
	I.print();

	//cout ;

	Fraction H = A == B;
	H.print();

	cout << (Fraction(1, 2) == Fraction(5, 10)) << endl;
	cout << (Fraction(1, 2) != Fraction(5, 10)) << endl;
	cout << (Fraction(1, 2) > Fraction(5, 10)) << endl;
	cout << (Fraction(1, 2) < Fraction(5, 10)) << endl;
	cout << (Fraction(1, 2) <= Fraction(5, 10)) << endl;
	cout << (Fraction(1, 2) >= Fraction(5, 10)) << endl;

#endif // CONSTRUCTOR_CHECK3

#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS
	/*Fraction A(1, 2);
cout << A<<endl;
A.print();*/

	Fraction B;
	B = Fraction(8);
	cout << B << endl;
#endif // CONVERSIONS_FROM_OTHER_TO_CLASS

#ifdef CONVERSION_FROM_CLASS_TO_OTHER
	Fraction A(2, 3, 4);
	int a = (int)A;
	cout << a << endl;
	double b = A;
	cout << b << endl;

	cout << (Fraction(1, 2) == Fraction(5, 10)) << endl;
#endif // CONVERSION_FROM_CLASS_TO_OTHER
#ifdef DOUBLE_CONSTRUCTOR_CHECK


	//Fraction E(2.75);
	//cout << E << endl;
	Fraction A = 2.75;
	//A.reduce();
	cout << A << endl;
#endif // DOUBLE_CONSTRUCTOR_CHECK

	Fraction A = 2.75;
	cout << "Введите простую дробь: "; cin >> A;
	cout << A << endl;
	cout << (double)A << endl;

}