﻿#include<iostream>
using namespace std;

class String
{
	int size;  //Размер строки в байтах 
	char* str;  //Указатель на строку
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	 char* get_str()
	{
		return str;
	}
	
	//      Constructors
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		//Должен выполнять DeepCopy(Побитовое копирование)
		// т.е выделить новую память и скопировать в неё содержимое др объектa
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << this << endl;
	}

	//      Operators
	String& operator=(const String& other)
	{

		if (this == &other)return *this;  //other -оператор взятия адреса
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment" << this << endl;
		return *this;
	}
	const char& operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}
	//      Metods
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	//Левую строку копируем соответственно
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
		//cat.get_str()[i] = left.get_str()[i];
	
	// Правую строку копируем со смещением вправо на размер левой строки
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
		//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	
	return cat;
}

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//#define CONSTRUCTOR_CHECK

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

	String str1 = "Hello";
	String str2("World");
	String str3 = str1 +" " + str2;
	str3.print();

	cout << "Введите строку: "; cin >> str1;
	cout << str1 << endl;
}