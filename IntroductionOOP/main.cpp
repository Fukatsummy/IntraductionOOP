#include<iostream>
using namespace std;

struct Point
{
	double x;// Характеристики
	double y;
};

void main()
{

	setlocale(LC_ALL, "");

	int a;// объявление переменной 'а' типа int
	Point A;//Объект//Объявление переменной 'А' типа 'Point'
	        //Объявление объекта 'А' структуры 'Point'
	        //Создание экземпляра 'А' структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
	cout << (*pA).x << "\t" << (*pA).y << endl;//второй вариант

	cout << sizeof(Point) << endl; //Размер
	cout << typeid(A).name() << endl;
}