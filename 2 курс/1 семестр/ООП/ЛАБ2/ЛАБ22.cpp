//#include <stdafx>
#include <iostream>
#include <math.h>
#define PI 3.14159;
using namespace std;
//������� ����� figure
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
cout<<"��� ����������� �����������"<<endl;
}

float figure::perimetr()
{
int i;
float psum;
for (psum=0, i=0; i<n; psum+=p[i], i++)
return psum;
}
//����� ���������� �������, ���� �� �����������, �
//������ ������ ����� ������������� �������� �������
float figure::square()
{
cout<<"���������� ������ �� ����������"<<endl;
return 0;
}
//����� ������ ���������� � ������ �����
//������������� � ������ ����������� ������
void figure::show_parametri()
{
cout<<"����������� ������";
}
//����������� ����� _circle (����������) ����������
//�� ������ figure
class _circle:public figure
{
public:
//�����������
_circle();
//������������� ������ perimetr(), square(), show_parametri()
float perimetr();
virtual float square();
virtual void show_parametri();
};
//����������� ����� RecTangle (�������������),
//���������� �� ������ figure
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
//����������� ������ _circle
_circle::_circle()
{
cout<<"��������� ����������"<<endl;
//� �������� ������ ���������� ���������
//������������ �������� ������
n=1;
p=new float[n];
cout<<"������� ������"<<endl;
cin>>p[0];
}
//����� ���������� ��������� ����������
float _circle::perimetr()
{
return 2*PI*p[0];
}
//����� ���������� ������� ����������
float _circle::square()
{
return PI*p[0]*p[0];
}
//����� ������ ���������� ����������
void _circle::show_parametri()
{
//����� ��������� � ���, ��� ��� ����������
cout<<"��� ���������� "<<endl;
//����� ������� ����������
cout<<"������ = "<<p[0]<<endl;
//����� ��������� ����������
cout<<"�������� = "<<perimetr()<<endl;
//����� ������� ����������
cout<<"������� = "<<square()<<endl;
}
//����������� ������ RecTangle
RecTangle::RecTangle()
{
cout<<"��������� ��������������"<<endl;
//���������� ������ = 4
n=4;
p=new float[n];
//���� ���� ������ ��������������
cout<<"������� ����� ������";
cin>>p[0]>>p[1];
p[2]=p[0];
p[3]=p[1];
}
//����� ���������� ������� ��������������
float RecTangle::square()
{
return p[0]*p[1];
}
//����� ������ ���������� ��������������
void RecTangle::show_parametri()
{
//����� ��������� � ���, ��� ��� �������������
cout<<"��� �������������"<<endl;
//����� ����� ������ ��������������
cout<<"a="<<p[0]<<"b="<<p[1]<<endl;
//����� ��������� ��������������. �������� ��������,
//��� � ������ RecTangle ���������� ����� perimetr()
//�������� ������ (figure)
cout<<"�������� = "<<perimetr()<<endl;
//����� ������� ��������������
cout<<" ������� = "<<square()<<endl;
}
