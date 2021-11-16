//IntroductionToOOP
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Point	//Создавая структуру или класс мы создаем новый тип данных
{
	double x;
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

	//					Constructors:
	/*Point()
	{
		x = y = double();	//В обе координаты ложим значение по умолчанию для double
		cout << "DefaultConstructor:\t" << this << endl;
	}*/
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "SingleArgumentConstructor:" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Construtor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//					Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	//					Methods:
	double distance(const Point& other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
		return distance;
		//sqrt - Square Root (Квадратный корень)
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

double distance(const Point& A, const Point& B)
{
	return sqrt
	(
		pow(A.get_x() - B.get_x(), 2) + 
		pow(A.get_y() - B.get_y(), 2)
	);
}

#define delimiter "\n-----------------------------------------------\n"
//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK
#define ASSIGNMENT_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	//type name;	//синтаксис объявления переменной
	int a;	//Объявление переменной 'a' типа 'int'
	Point A;//Объявление переменной 'A' типа 'Point'
			//Создание объекта 'A' структуры 'Point'
			//Объявление объекта 'A' структуры 'Point'
			//Создание экземпляра 'A' структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;	//Создаем (объявляем) Указатель на Point
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

#ifdef DISTANCE_CHECK
	Point A(2, 3);
	Point B(3, 4);
	cout << delimiter << endl;
	cout << "Расстояние от точки A до точки B: " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками A и B: " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками B и A: " << distance(B, A) << endl;
	cout << delimiter << endl;
#endif // DISTANCE_CHECK

#ifdef CONSTRUCTORS_CHECK
	cout << int() << endl;	//Значение по умолчанию для int.
	Point A;		//Default constructor
	/*A.set_x(2);
	A.set_y(3);*/
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B = 5;	//Single-argument constructor
	B.print();

	Point C(7);		//Single-argument constructor
	C.print();

	Point D(4, 5);
	D.print();

	Point E = D;	//Copy constructor
	E.print();

	Point F;	//Default constructor
	F = E;		//Copy assignment
	F.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;

	Point A, B, C;
	cout << "\n---------------------------------\n";
	A = B = C = Point(2, 3);
	cout << "\n---------------------------------\n";
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHECK

}

/*
------------------------------------------------------------------
.  - Оператор пямого доступа	 (Point operator)
-> - Оператор косвенного доступа (Arrow operator)
------------------------------------------------------------------
*/

/*
------------------------------------------------------------------
1. Инкапсуляция - Encapsulation;
	Модификаторы доступа:
		private:	закрытые поля, доступны только внутри класса/структуры
		public:		открытые поля, доступны из любого места программы
		protected:	защищенные поля, доступны изнутри класса, и изнутри дочерних классов.
					Этот модификатор доступа используется только при наследовании.
	get/set-методы:
	get(взять, получить) - открывают доступ на чтение
	set(задать, установить) - открывают доступ к закрытым переменным на запись.
	set-методы так же обеспечивают фильтрацию данных
2. Наследование - Inheritance;
3. Полиморфизм  - Polymorphism;
------------------------------------------------------------------
*/

/*
------------------------------------------------------------------
1. Constructor - это метод, который создает объект;
	-с параметрами;
	-без параметров;
	-конструктор по умолчанию - это конструктор, который МОЖЕТ БЫТЬ ВЫЗВАН без параметров;
	-конструктор копирования  - это конструктор, который копирует объект;
	-конструктор переноса;
2. ~Destructor  - это метод, который уничтожает объект по завершении его времени жизни;
   ~ - Tilda
3. AssignmentOperator;
------------------------------------------------------------------
*/