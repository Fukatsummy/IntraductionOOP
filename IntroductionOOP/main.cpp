#include<iostream>
using namespace std;
using std::cout;

class Point
{
	double x;// Характеристики
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//       Constructors:    
	Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}


	//       Methods:
	double distance(Point other)
	{
		//this - точка , для которой вызвался метод(от которой нужно найти расстояние)
		//other - точка, до которой нужно найти расстояние
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
		return distance;
	}

	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
	return distance;
}

//#define STRUCT_POINT
//#define CLASS_WORK
//#define TASK_1

void main()
{

	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT
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
#endif // STRUCT_POINT

#ifdef CLASS_WORK
	Point A;
	//double x=2, y=3;//для ввода с клавиатуры 
	//cout << "Введите координаты точки: "; cin >> x >> y;
	//A.set_x(x);
	//A.set_y(y);
	//Для отображения данных.
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;

	cout << "Растояние от точки А до точки В: " << A.distance(B) << endl;
	cout << "Растояние от точки А до точки В: " << B.distance(A) << endl;
	cout << "Растояние между точками А и В: " << distance(A,B) << endl;
	cout << "Растояние между точками А и В: " << distance(B,A) << endl;
#endif // CLASS_WORK

#ifdef TASK_1
	Point A;
	A.set_x(2);
	A.set_y(3);
	Point B;
	B.set_x(7);
	B.set_y(8);
	double distance;
	cout << sqrt((A.get_x() - B.get_x())*(A.get_x() - B.get_x()) + (A.get_y() - B.get_y())*(A.get_y() - B.get_y()))<<endl;
	cout << Distance(A, B) << endl;
#endif // TASK_1


	int a;
	Point A;
	A.print();
	//cout << A.get_x() << "\t" << A.get_y() << endl;
}

double Distance(Point A, Point B)
{
	return sqrt((A.get_x() - B.get_x())*(A.get_x() - B.get_x()) + (A.get_y() - B.get_y())*(A.get_y() - B.get_y()));
}