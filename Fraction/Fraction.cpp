#include"Fraction.h"


//      Def
int Fraction::get_integer()const
{
	return integer;
}
int Fraction::get_numerator()const
{
	return numerator;
}
int Fraction::get_denominator()const
{
	return denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0)denominator = 1;
	this->denominator = denominator;
}
Fraction::Fraction()
{
	this->integer = 0;
	this->numerator = 0;
	this->denominator = 1;
	cout << "DefConstructor:\t" << this << endl;
}
Fraction::Fraction(int integer)
{
	this->integer - integer;
	this->numerator = 0;
	this->denominator = 1;
	cout << "1argConstructor:\t" << this << endl;
}
Fraction::Fraction(double decimal)
{
	decimal += 1e-10;
	integer = decimal;
	decimal -= integer;
	denominator = 1e+9;
	numerator = decimal * denominator;
	reduce();
	cout << "Constructor DBL:\t" << this << endl;

}
Fraction::Fraction(int numerator, int denominator)
{
	this->integer = 0;
	this->numerator = numerator;
	this->set_denominator(denominator);
	cout << "Constructor:\t\t" << this << endl;
}
Fraction::Fraction(int integer, int numerator, int denominator)
{
	this->integer = integer;
	this->numerator = numerator;
	this->denominator = denominator;
	cout << "Constructor:\t\t" << this << endl;
}
//Fraction(double decimal)//преобразование из десятичной дроби
//{
//	decimal += 1e-10;
//	integer = decimal;
//	//denominator = 10000;
//	decimal -= integer;
//	numerator = 0;
//	int i = 0;
//	int digit = 0;//старший дробный рязряд
//	for (; decimal && i < 9; i++)
//	{
//		numerator *= 10;
//		decimal *= 10;
//		digit = decimal;
//		numerator += digit;
//		decimal -= digit;
//	}
//	denominator=pow(10,i);
//	cout << "1argConstructor: " << this << endl;
//}
Fraction::Fraction(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyConstructor:\t" << this << endl;
}
Fraction::~Fraction()
{
	cout << "Destructor:\t\t" << this << endl;
}

Fraction& Fraction::operator()(int integer, int numerator, int denominator)
{
	set_integer(integer);
	set_numerator(numerator);
	set_denominator(denominator);
	return *this;
}
Fraction& Fraction::operator++()
{
	integer++;
	return *this;
}
Fraction Fraction::operator++(int)
{
	Fraction old = *this;
	integer++;
	return old;
}
Fraction Fraction::operator--()
{
	integer--;
	return *this;
}
Fraction Fraction::operator--(int)
{
	Fraction old = *this;
	integer--;
	return old;
}
Fraction& Fraction::operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssigment:\t" << this << endl;
	return *this;
}
Fraction& Fraction::operator*=(const Fraction& other)
{
	return *this = *this*other;
}
//       Type-cast operators
Fraction::operator int()const
{
	return integer;
}
Fraction::operator double()const //перегружает(преобразовывает) инт в дабл
{
	return integer + (double)numerator / denominator;
}

//        Methods
Fraction& Fraction::to_proper()
{
	//переодит дробь в правильную(выделяет целую часть)
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}
Fraction& Fraction::to_improper()
{
	//переводит дробь в неправильную (выделяет целую часть)
	numerator += integer * denominator;
	integer = 0;
	return*this;
}
Fraction Fraction::inverted()const
{
	Fraction inverted = *this;
	inverted.to_improper();
	int buffer = inverted.numerator;
	inverted.numerator = inverted.denominator;
	inverted.denominator = buffer;
	return inverted;
}
Fraction& Fraction::reduce()
{
	int more, less, rest;
	if (numerator > denominator)
	{
		more = numerator;
		less = denominator;
	}
	else
	{
		less = numerator;
		more = denominator;
	}
	do
	{
		rest = more % less;
		more = less;
		less = rest;
	} while (rest);
	int GCD = more;//GCD - Greates Common Division (Набольший общий делитель)
	if (GCD == 0)return *this;
	numerator /= GCD;
	denominator /= GCD;
	return *this;
}
void Fraction::print()const
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
ostream& Fraction::print(ostream& os)const
{
	if (integer)os << integer;
	if (numerator)
	{
		if (integer)cout << "(";
		os << numerator << "/" << denominator;
		if (integer)os << ")";
	}
	if (integer == 0 && numerator == 0)os << 0;
	return os;
}

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




#ifdef FULL_CONPARISON
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
}

bool operator !=(const Fraction left, const Fraction right)
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
bool operator ==(const Fraction& left, const Fraction& right)
{
	return (double)left == right;
}
#endif // FULL_CONPARISON

std::ostream& operator <<(ostream& os, const Fraction& obj)
{
	/*if (obj.get_integer())os << obj.get_integer;
	if (obj.get_numerator)
	{
		if (obj.get_integer)os << "(";
		os << obj.get_numerator << "/" << obj.get_denominator;
		if (obj.get_integer)os << ")";
	}
	if (obj.get_integer == 0 && obj.get_numerator == 0)os << 0;
	return os;*/
	return obj.print(os);
}
std::istream& operator>>(istream& is, Fraction& obj)
{
	const int SIZE = 256;
	char buffer[SIZE] = {};// это массив элементов char
	//cin >> buffer;
	cin.getline(buffer, SIZE);// позволяет использовать пробел при вводе 
	char delimiters[] = "()/ ";// знаки разделители
	char* sz_numbers[3] = {}; // массив строк, который будет хранить числа в строковом формате
	//sz - string zero(строка, заканчивающаяся нулем)
	int i = 0;// счетчик цикла
	for (char*pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
	{
		sz_numbers[i++] = pch;
	}
	obj = Fraction();//Обнуляем объект(сбрасываем его в объект по умолчанию)
	switch (i)
	{
	case 1: obj.set_integer(atoi(sz_numbers[0])); break;
		//atoi - ASCII-string to integer (преобразует строку в число)
	case 2:
		obj.set_numerator(atoi(sz_numbers[0]));
		obj.set_denominator(atoi(sz_numbers[1])); break;
	case 3:
		obj.set_integer(atoi(sz_numbers[0]));
		obj.set_numerator(atoi(sz_numbers[1]));
		obj.set_denominator(atoi(sz_numbers[2]));
	}
	return is;
}
//        Def