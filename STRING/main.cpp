#include<iostream>
using namespace std;

class String
{
private:
	int size;
	char* str;
public:
	int get_size()const
	{
		return size;
	}
	char* get_str()const
	{
		return str;
	}
	/*void set_size(int size)
	{
		this->size = size;
	}
	void set_str(char* str)
	{
		this->str = str;
	}*/
	//          CONSTRUCTORS:
	String(int size= 80)//Строка с заданым размером
	{
		this->size = size ;
		this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(const char* str)//Конструктор
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other)//Конструктор копирования
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:" << this << endl;
	}
	~String()
	{
		delete this->str;
		cout << "Destructor:\t" << this << endl;
	}
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "String:\t" << str << endl;
	}
};
ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

void main()
{
	setlocale(LC_ALL, "");

	String str1;//Почему ошибка? пишет не найден конструктор по умолчанию
	str1.print();

	String str3 = "Hello";
	str3.print();

	String str4 = "World";
	str4.print();

	String str5 = str3 + str4;
	cout << str5 << endl;

	cout << "Введите строку: "; cin >> str1;
	cout << str1 << endl;

}