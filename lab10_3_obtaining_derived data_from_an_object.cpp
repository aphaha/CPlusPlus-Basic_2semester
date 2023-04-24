#include <iostream>
#include <string>

using namespace std;


class AdHocSquare
{
public:
	AdHocSquare(double side);
	void set_side(double side);
	double get_area();
	void print();
private:
	double side;
};

class LazySquare
{
public:
	LazySquare(double side);
	void set_side(double side);
	double get_area();
private:
	double side;
	double area;
	bool side_changed;
};

AdHocSquare::AdHocSquare(double side)
{
	if (side >= 0)
		this->side = side;
	else
		this->side = 0;
}

void AdHocSquare::set_side(double side)
{
	this->side = side;
}

double AdHocSquare::get_area()
{
	return this->side * this->side;
}

void AdHocSquare::print()
{
	cout << "AdHocSquare: side = " << this->side << " area = " << this->get_area() << endl;
}

int main()
{

	AdHocSquare s(4);
	s.print();
	
	s.set_side(2.0);
	s.print();
	
	s.set_side(-33.0);
	s.print();

	return 0;
}

// Цей код містить два класи: AdHocSquare та LazySquare, які представляють квадрати з заданою стороною.

// Клас AdHocSquare має конструктор, метод set_side, який встановлює довжину сторони, та метод get_area, який повертає площу квадрата.

// Клас LazySquare має конструктор, метод set_side, який встановлює довжину сторони, та метод get_area, який повертає площу квадрата. Однак, він зберігає площу у змінній area тільки при створенні об'єкта або при зміні довжини сторони, а при наступному виклику методу get_area перевіряє, чи змінювалась довжина сторони, та відповідно повертає або обчислює нову площу квадрата.

// У функції main створюються об'єкти класу AdHocSquare та викликаються методи set_side та get_area. Об'єкти класу LazySquare не використовуються в цьому коді. Також у функції main є помилка - метод print не визначений в класі AdHocSquare. Він повинен бути замінений на метод get_area.