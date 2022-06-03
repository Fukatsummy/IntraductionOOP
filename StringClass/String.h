#pragma once

#include<iostream>
using namespace std;
using std::cout;


////////Class Declaration - Объявление класса//////////



class String;
String operator+(const String& left, const String& right);

class String
{
	int size;  //Размер строки в байтах 
	char* str;  //Указатель на строку
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();

	//      Constructors
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

	//      Operators
	String& operator=(const String& other);
	String& operator=(String&& other);
	String operator+=(const String& other);
	const char& operator[](int i)const;
	char& operator[](int i);

	//      Metods
	void print()const;
};
//////// Class Declaration end/////////////

String operator+(const String& left, const String& right);
ostream& operator<<(ostream& os, const String& obj);
