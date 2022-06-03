#include"String.h"

///////////-------------------------------//////////////
//////////Class definition - Определение класса/////////
int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}

///////////      Constructors   //////////////
String::String(int size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	cout << "DefConstructor:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)
{
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other) : String(other.str)
{
	//Должен выполнять DeepCopy(Побитовое копирование)
	// т.е выделить новую память и скопировать в неё содержимое др объектa
	cout << "CopyConstructor:" << this << endl;
}
String::String(String&& other) :size(other.size), str(other.str)
{
	//MoveConstructor выполняем поверхностное копирование(ShellowCopy)
	//this->size = other.size;
	//this->str = other.str; //Копируем адрес памяти, принадлежащий другому объекту
	other.size = 0;
	other.str = nullptr;//зануляем адрес памяти в другом объекте, чтобы эту память не удалил диструктор
	cout << "MoveConstructor:\t" << this << endl;
}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t" << this << endl;
}

//      Operators
String& String::operator=(const String& other)
{

	if (this == &other)return *this;  //other -оператор взятия адреса
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignment" << this << endl;
	return *this;
}
String& String::operator=(String&& other)
{
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssignment:" << this << endl;
	return *this;
}
String String::operator+=(const String& other)
{
	return *this = *this + other;
}
const char& String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}

//      Metods
void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}
ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}
istream& operator>>(istream& is, String obj)
{
	const int SIZE = 256;
	char buffer[SIZE] = {};
	cin.getline(buffer, SIZE);
	obj = buffer;
	return is;
}
//////////// Class Defenition END/////////////
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
