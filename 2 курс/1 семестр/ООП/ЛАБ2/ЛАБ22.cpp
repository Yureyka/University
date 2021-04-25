//#include <stdafx>
#include <iostream>
#include <math.h>
#define PI 3.14159;
using namespace std;
//базовый класс figure
class figure
{
public:
int n;
float *p;
figure();
float perimetr();
virtual float square();
virtual void show_parametri();
};
figure::figure()
{
cout<<"Это абстрактный конструктор"<<endl;
}

float figure::perimetr()
{
int i;
float psum;
for (psum=0, i=0; i<n; psum+=p[i], i++)
return psum;
}
//метод вычисления площади, пока он абстрактный, в
//каждом классе будет перегружаться реальным методом
float figure::square()
{
cout<<"Квадратная фигура не абстрактна"<<endl;
return 0;
}
//метод вывода информации о фигуре будет
//перегружаться в каждом производном классе
void figure::show_parametri()
{
cout<<"Абстрактная фигура";
}
//производный класс _circle (окружность) основанный
//на классе figure
class _circle:public figure
{
public:
//конструктор
_circle();
//перегружаемые методы perimetr(), square(), show_parametri()
float perimetr();
virtual float square();
virtual void show_parametri();
};
//производный класс RecTangle (прямоугольник),
//основанный на классе figure
class RecTangle:public figure
{
public:
RecTangle();
virtual float square();
virtual void show_parametri();
};

int main()
{
setlocale(LC_ALL,"Rus");
_circle RR;
RR.show_parametri();
RecTangle PP;
PP.show_parametri();

}
//конструктор класса _circle
_circle::_circle()
{
cout<<"Параметры окружности"<<endl;
//в качестве сторон окружности выступает
//единственный параметр радиус
n=1;
p=new float[n];
cout<<"Введите радиус"<<endl;
cin>>p[0];
}
//метод вычисления периметра окружности
float _circle::perimetr()
{
return 2*PI*p[0];
}
//метод вычисления площади окружности
float _circle::square()
{
return PI*p[0]*p[0];
}
//метод вывода параметров окружности
void _circle::show_parametri()
{
//вывод сообщения о том, что это окружность
cout<<"Это окружность "<<endl;
//вывод радиуса окружности
cout<<"Радиус = "<<p[0]<<endl;
//вывод периметра окружности
cout<<"Периметр = "<<perimetr()<<endl;
//вывод площади окружности
cout<<"Площадь = "<<square()<<endl;
}
//конструктор класса RecTangle
RecTangle::RecTangle()
{
cout<<"Параметры прямоугольника"<<endl;
//количество сторон = 4
n=4;
p=new float[n];
//ввод длин сторон прямоугольника
cout<<"Введите длину сторон";
cin>>p[0]>>p[1];
p[2]=p[0];
p[3]=p[1];
}
//метод вычисления площади прямоугольника
float RecTangle::square()
{
return p[0]*p[1];
}
//метод вывода параметров прямоугольника
void RecTangle::show_parametri()
{
//вывод сообщения о том, что это прямоугольник
cout<<"Это прямоугольник"<<endl;
//вывод длины сторон прямоугольника
cout<<"a="<<p[0]<<"b="<<p[1]<<endl;
//вывод периметра прямоугольника. Обратите внимание,
//что в классе RecTangle вызывается метод perimetr()
//базового класса (figure)
cout<<"Периметр = "<<perimetr()<<endl;
//вывод площади прямоугольника
cout<<" Площадь = "<<square()<<endl;
}
