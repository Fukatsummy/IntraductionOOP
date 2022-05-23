#include<iostream>
using namespace std;

class Fraction
{
	int integer;//����� �����
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
	void to_proper()
	{
		//�������� ����� � ����������(�������� ����� �����)
		integer += numerator / denominator;
		numerator %= denominator;
	}
	void to_improper()
	{
		//��������� ����� � ������������ (�������� ����� �����)
		numerator += integer * denominator;
		integer = 0;
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

Fraction operator*(Fraction left, Fraction right)// �������� ���������
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
Fraction operator+(Fraction left, Fraction right)//�������� ��������
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator()*right.get_denominator() + left.get_denominator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
}
Fraction operator-(Fraction left, Fraction right)//�������� ���������
{
	return Fraction
	(
		left.get_numerator()*right.get_denominator() - left.get_denominator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
}
Fraction operator/(Fraction left, Fraction right)//�������� �������
{
	return Fraction
	(
		left.get_numerator()*right.get_denominator(),
		left.get_denominator()*right.get_numerator()
	);
}

//ostream& operator<<(ostream& out, const Fraction &fraction)//���������� � ����
//{
//	out << fraction.get_numerator() << "/" << fraction.get_denominator();
//	return out;
//}
//istream& operator>>(istream& in, const Fraction &fraction)//�������� ����������(�������� �� �����(�������))
//{
//	in >> fraction.get_numerator();
//	in >> fraction.get_denominator();
//	return in;
//}
bool operator>(const Fraction left, const Fraction right)
{
	return(left.get_numerator() / right.get_numerator() > (left.get_denominator() / right.get_denominator()));
}
bool operator==(const Fraction left, const Fraction right)
{
	return (left.get_numerator() == right.get_numerator() && left.get_denominator() == right.get_denominator());
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

	Fraction C = A + B;//����� ������
	C.print();

	Fraction D = A - B;//���������
	D.print();

	Fraction E = A / B;//�������
	E.print();

	Fraction F = C++;//���������
	C.print();
	F.print();

	Fraction G = D--;//���������
	D.print();
	G.print();

	//ostream&(Fraction);
	//istream&(Fraction);

	Fraction I = A > B;
	A.print();
	B.print();
	cout <<

	Fraction H = A == B;
	A.print();
	B.print();
#endif // CONSTRUCTOR_CHECK3


}
