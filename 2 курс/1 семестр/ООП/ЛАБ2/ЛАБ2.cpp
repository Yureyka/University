#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

class Shape
{
    int n;
    float *p;
    Shape();
    virtual float perimetr();
    virtual void show_parametri();

    /*Shape::Shape()
    {
        cout<<"��� ����������� �����������"<<endl;
    }
*/
    float Shape::perimetr()
    {
        int i;
        float psum=0;
        for (i=0; i<n; i++)
            psum+=p[i]
        return psum;
    }
    void Shape::show_parametri()
};

class Circle : public Shape
{
    public:
        virtual float perimetr();
        virtual void show_parametri();
};

class Rectangle : public Shape
{
    public:
        RecTangle();
        virtual float perimetr();
        virtual void show_parametri();
};

class Quadr : public Shape
{
    public:
        virtual float perimetr();
        virtual void show_parametri();
};

int main ()
{
    setlocale(LC_ALL,"Rus");
    Circle r;
    r.show_parametri();
    RecTangle p1;
    p.show_parametri();
    Quadr p2;
    p.show_parametri();
    system("pause");

    Circle::Circle()
    {
        cout<<"��������� ����������"<<endl;
        n=1;
        p=new float[n];
        cout<<"������� ������"<<endl;
        cin>>p[0];
    }
    float Circle::perimetr()
    {
        return 2*PI*p[0];
    }
    float Circle::square()
    {
        return PI*p[0]*p[0];
    }
    void Circle::show_parametri()
    {
        cout<<"��� ����������"<<endl;
        cout<<"������= "<<p[0]<<endl;
        cout<<" ��������= "<<perimetr()<<endl;
    }

	RecTangle::RecTangle()
    {
        cout<<"��������� ��������������"<<endl;
        n=4;
        p=new float[n];
        cout<<"������� ����� ������";
        cin>>p[0]>>p[1];
        p[2]=p[0];
        p[3]=p[1];
    }

    float RecTangle::square()
    {
        return p[0]*p[1];
    }
    void RecTangle::show_parametri()
    {
    out<<"��� �������������"<<endl;
    cout<<"a="<<p[0]<<" b="<<p[1]<<endl;
    cout<<"��������= "<<perimetr()<<endl;
}

    Quadr::Quadr()
    {
        cout<<"��������� ����������������"<<endl;
        n=4;
        p=new float[n];
        cout<<"������� ����� ������";
        cin>>p[0]>>p[1]>>p[2]>>p[3];
    }

    float Quadr::square()
    {
        return p[0]*p[1];
    }
    void Quadr::show_parametri()
    {
    out<<"��� �������������"<<endl;
    cout<<"a="<<p[0]<<" b="<<p[1]<<endl;
    cout<<"��������= "<<perimetr()<<endl;
}
