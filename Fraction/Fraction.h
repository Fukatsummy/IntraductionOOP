#pragma once
#include<iostream>
using namespace std;
using std::cout;
//#include"Fraction.h"

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
//     Dec
class Fraction
{
	int integer;//Целое число
	int numerator;
	int denominator;

public:
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);
	Fraction();
	Fraction(int integer);
	Fraction(double decimal);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
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
	Fraction(const Fraction& other);
	~Fraction();
	Fraction& operator()(int integer, int numerator, int denominator);
	Fraction& operator++();
	Fraction operator++(int);
	Fraction operator--();
	Fraction operator--(int);
	Fraction& operator=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	//       Type-cast operators
	explicit operator int()const;
	operator double()const;//перегружает(преобразовывает) инт в дабл


	//        Methods
	Fraction& to_proper();
	Fraction& to_improper();
	Fraction inverted()const;
	Fraction& reduce();
	void print()const;
	ostream& print(ostream& os)const;
};

std::istream& operator>>(istream& is, Fraction& obj);
std::ostream& operator <<(ostream& os, const Fraction& obj);
Fraction operator+(Fraction left, Fraction right);
Fraction operator*(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);