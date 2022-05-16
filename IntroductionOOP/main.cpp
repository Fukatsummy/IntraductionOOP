#include<iostream>
using namespace std;
using std::cout;


#define delimiter "\n------------------\n"
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

	//Point()
	//{
	//	x = y = 0;//зануляет переменные
	//	cout << "DefaultConstructor:\t" << this << endl;
	//}
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "Single argument constructor:" << this << endl;
	}*/
	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this<<endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//       Operators:
	Point operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}


	//       Methods:
	double distance(const Point& other)
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
//#define CONSTRUCTOR_CHECK
//#define ASSIGNMENT_CHECK_1
#define ASSIGNMENT_CHECK_2

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
	cout << delimiter;
	cout << "Растояние от точки А до точки В: " << A.distance(B) << endl;
	cout << delimiter;
	cout << "Растояние от точки А до точки В: " << B.distance(A) << endl;
	cout << delimiter;
	cout << "Растояние между точками А и В: " << distance(A,B) << endl;
	cout << delimiter;
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

#ifdef CONSTRUCTOR_CHECK
	int a(2);
	cout << a << endl;

	Point A;
	A.print();
	//cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B = 5;//sindle argument constructor
	B.print();

	Point C(8);//sindle argument constructor
	C.print();

	Point D(2, 3);
	D.print();

	Point E = D;//Copy Constructor
	E.print();

	Point F(D);//Copy Constructor
	F.print();
#endif // CONSTRUCTOR_CHECK

#ifdef ASSIGNMENT_CHECK_1
	Point A(2, 3);
	Point B = A;  //Copy Constructor потому что создается объект 'В'
	Point C; // default constructor
	C = B;  //Copy Assignment потому что объект 'С' уже существует  
#endif // ASSIGNMENT_CHECK_1

#ifdef ASSIGNMENT_CHECK_2

	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	A = B = C = Point(2, 3);
	A.print();
#endif // ASSIGNMENT_CHECK_2


}

double Distance(const Point& A,const Point& B)
{
	return sqrt((A.get_x() - B.get_x())*(A.get_x() - B.get_x()) + (A.get_y() - B.get_y())*(A.get_y() - B.get_y()));
}