#include<iostream>
using namespace std;

class String;
String operator+(const String& left, const String& right);

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
	explicit String(int size = 80):size(size),str(new char[size]{})
	{
		//this->size = size;
		//this->str = new char[size] {};
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char* str):size(strlen(str)+1),str(new char[size] {})
	{
		//this->size = strlen(str) + 1;
		//this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other):size(other.size), str(new char[size]{})
	{
		//this->size = other.size;
		//Должен выполнять DeepCopy(Побитовое копирование)
		// т.е выделить новую память и скопировать в неё содержимое др объектa
		//this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:" << this << endl;
	}
	String(String&& other):size(other.size),str(other.str)
	{
		//MoveConstructor выполняем поверхностное копирование(ShellowCopy)
		//this->size = other.size;
		//this->str = other.str; //Копируем адрес памяти, принадлежащий другому объекту
		other.size = 0;
		other.str = nullptr;//зануляем адрес памяти в другом объекте, чтобы эту память не удалил диструктор
		cout << "MoveConstructor:\t" << this << endl;
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
	String& operator=(String&& other)
	{
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str=nullptr;
		cout << "MoveAssignment:" << this << endl;
		return *this;
	}
	String operator+=(const String& other)
	{
		return *this = *this + other;
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


//#define CONSTRUCTOR_CHECK
//#define MOVE_METODS_CHECK
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
#endif // COLLING_CONSTRUCTOR



}