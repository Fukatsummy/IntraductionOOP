#include<iostream>
using namespace std;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
class Fraction
{
	int integer;//Целое число
	int numerator;
	int denominator;

public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer - integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1argConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old=*this;
		integer++;
		return old;
	}
	Fraction operator--()
	{
		integer--;
		return *this;
	}
	Fraction operator--(int)
	{
		Fraction old = *this;
		integer--;
		return old;
	}
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssigment:\t" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this*other;
	}
	Fraction& to_proper()
	{
		//переодит дробь в правильную(выделяет целую часть)
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& to_improper()
	{
		//переводит дробь в неправильную (выделяет целую часть)
		numerator += integer * denominator;
		integer = 0;
		return*this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		int buffer = inverted.numerator;
		inverted.numerator = inverted.denominator;
		inverted.denominator = buffer;
		return inverted;
	}
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		if (integer == 0 && numerator == 0)cout << 0;
		cout << endl;
	}
};

Fraction operator*(Fraction left, Fraction right)// Оператор умножения
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator()*right.get_numerator());
	result.set_denominator(left.get_denominator()*right.get_denominator());*/

	/*Fraction result
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
	result.to_proper();
	return result;*/

	return Fraction
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
}
Fraction operator+(Fraction left, Fraction right)//Оператор сложения
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator()*right.get_denominator() + left.get_denominator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
}
Fraction operator-(Fraction left, Fraction right)//Оператор вычитания
{
	return Fraction
	(
		left.get_numerator()*right.get_denominator() - left.get_denominator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
}
Fraction operator/(Fraction left, Fraction right)//Оператор деления
{
	return Fraction
	(
		left.get_numerator()*right.get_denominator(),
		left.get_denominator()*right.get_numerator()
	);
}
//Fraction operator*(Fraction left, Fraction right)
//{
//	left.to_improper();
//	right.to_improper();
//	return Fraction
//	(
//		left.get_numerator()*right.get_numerator(),
//		left.get_denominator()*right.get_denominator()
//	);
//}

//ostream& operator<<(ostream& out, const Fraction &fraction)//сохранение в файл
//{
//	out << fraction.get_numerator() << "/" << fraction.get_denominator();
//	return out;
//}
//istream& operator>>(istream& in, const Fraction &fraction)//оператор извлечения(загрузка из файла(объекта))
//{
//	in >> fraction.get_numerator();
//	in >> fraction.get_denominator();
//	return in;
//}
bool operator>(Fraction left, Fraction right)
{
	return left.to_improper().get_numerator()*right.get_denominator() >
		right.to_improper().get_numerator()*left.get_denominator();
	//return(left.get_numerator() * right.get_numerator() > (left.get_denominator() * right.get_denominator()));
}
bool operator<(Fraction left, Fraction right)
{
	return left.to_improper().get_numerator()*right.get_denominator() <
		right.to_improper().get_numerator()*left.get_denominator();
}
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*if (left.get_numerator()*right.get_denominator() == right.get_numerator()*left.get_denominator())
		return true;
	else
		return false;*/
	return left.get_numerator()*right.get_denominator() == right.get_numerator()*left.get_denominator();
	
	//return (left.get_numerator() == right.get_numerator() && left.get_denominator() == right.get_denominator());
}bool operator !=(const Fraction left, const Fraction right)
{
	return !(left == right);
}
bool operator <=(const Fraction& left, const Fraction& right)
{
	return left < right || left == right;
}
bool operator >=(const Fraction& left, const Fraction& right)
{
	return !(left < right);
}

//#define CONSTRUCTOR_CHECK
//#define CONSTRUCTOR_CHECK2
#define CONSTRUCTOR_CHECK3
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


}
