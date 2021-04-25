#include<iostream>
#include<conio.h>

using namespace std;

class Figure
{
    public:
        virtual double Per()=0;
};

class Rectangle : public Figure
{
    protected:
        double a, b;
    public:
        Rectangle(double, double);
        double Per(){return (a+b)*2.;}
};

Rectangle :: Rectangle(double a, double b)
{
    this -> a = a;
    this -> b = b;
}

class Circle : public Figure
{
    double r;
    public:
        Circle(double);
        double Per(){return (2*3.141592*r);}
};

Circle :: Circle(double r)
{
    this -> r = r;
}

class Quadr : public Rectangle
{
    double c, d;
    public:
        Quadr(double, double, double, double);
        double Per(){return (a + b + c + d);}
};

Quadr :: Quadr(double a, double b, double c, double d) : Rectangle(a, b)
{
    this -> c = c;
    this -> d = d;
}

int main()
{
      setlocale(LC_ALL, "Russian");
      Figure *f = new Rectangle(1., 2.);
      cout << "Периметр прямогугольника: " << f -> Per() << endl << endl;

      f = new Circle(2.);
      cout << "Периметр окружности: " << f -> Per() << endl << endl;

      f = new Quadr(3., 3., 4., 5.);
      cout << "Периметр четырехугольника: " << f -> Per() << endl;

      getch();
      return 0;
}
