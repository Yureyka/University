#include <conio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Vector
{
    int n;
    float *V;
    public:
        Vector(int n1)
        {
            n=n1;
            V = new float [n];
            cout<<"Введите значения вектора: "<<endl;
            for(int i=0; i<n; i++)
                cin>>V[i];
            cout<<endl;

            for(int i=0; i<n; i++)
                cout<<V[i]<<" ";
            cout<<endl<<endl;
        }

        Vector &operator ++ ()
        {
            for(int i=0; i<n; i++)
                V[i]+=V[i];
            for(int i=0; i<n; i++)
                cout<<V[i]<<" ";
            return *this;
        }

        Vector &operator + (Vector &ob2)
        {
            for(int i=0; i<n; i++)
                V[i]+=ob2.V[i];
            for(int i=0; i<n; i++)
                cout<<V[i]<<" ";
            return *this;
        }

        ~Vector()
        {
            delete V;
        }

    friend Vector &operator -- (Vector &ob1);
    friend Vector &operator > (Vector &ob1, Vector &ob2);
    friend ostream & operator << (ostream& output, const Vector & ob);
	friend istream & operator >> (istream& input, Vector &ob);
};

Vector &operator -- (Vector &ob1)
{
    for(int i=0; i<ob1.n; i++)
        ob1.V[i]-=6;
    for(int i=0; i<ob1.n; i++)
        cout<<ob1.V[i]<<" ";
}

Vector &operator > (Vector &ob1, Vector &ob2)
{
    int c=0;
    for(int i=0; i<ob1.n; i++)
    {
        for(int j=0; j<ob2.n; j++)
            if(ob1.V[i]>ob2.V[j]) c++;
        if(c==ob1.n) break;
        else c=0;
    }
    if(c==ob1.n) cout<<"Имеется";
    else cout<<"Не имеется";
}

ostream & operator << (ostream& output, const Vector &ob)
{
    output<<endl<<"Результат работы оператора вывода"<<endl;
    for(int i=0; i<ob.n; i++)
        output<<'|'<<ob.V[i]<<'|';
    return output;
}

istream & operator >> (istream& input, Vector &ob)
{
	for(int i=0; i<ob.n; i++)
        input>>ob.V[i];
	return input;
}

int main ()
{
    setlocale(0, "RUS");
    Vector ob1(4), ob2(4);
    cout<<"Оператор ++: "<<endl;
    ++ob1;
    cout<<endl;
    cout<<"Оператор --: "<<endl;
    --ob1;
    cout<<endl;
    cout<<"Оператор +: "<<endl;
    ob1+ob2;
    cout<<endl;
    cout<<"Оператор >: "<<endl;
    ob1>ob2;
    cout<<endl;
    cin>>ob2;
    cout<<ob2;
    return 0;
}
