#include <conio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Device
{
    public:
        char name[15], prod[20];
        float pow;
        Device()
        {
            cout<<"Название: ";
            cin>>name;
            cout<<"Производитель: ";
            cin>>prod;
            cout<<"Мощность: ";
            cin>>pow;
        }

        void Output()
        {
            cout<<"Перечень устройств:"<<endl<<endl;
            cout<<"Название: "<<name<<endl;
            cout<<"Производитель: "<<prod<<endl;
            cout<<"Мощность: "<<pow<<endl;
        }
};

class Tune
{
    public:
        float freq, vol;
        Tune()
        {
            cout<<"Базовая громкость(дБ): ";
            cin>>vol;
            cout<<"Базовая частота (Гц): ";
            cin>>freq;
        }

    void Output()
    {
        cout<<"Необходимые параметры:"<<endl;
        cout<<"Громкость: "<<vol<<endl;
        cout<<"Частота: "<<freq<<endl;
    }
};

class Siren : public Device, public Tune
{
    public:
        int r1, r2;
        void Range()
        {
            cout<<"Добавьте необходимый диапазон частот: "<<endl;
            cout<<"Нижний порог: ";
            cin>>r1;
            cout<<"Верхний порог: ";
            cin>>r2;
        }

    void Output()
    {
        cout<<"Название: " <<name<<endl;
        cout<<"Производитель: "<<prod<<endl;
        cout<<"Громкость: "<<vol<<endl;
        cout<<"Диапазон частот: "<<r1<<".."<<r2<<endl;
    }
};

int main ()
{
    setlocale(0, "RUS");
    int k;
    Siren ob;
    while (1)
    {
        system("cls");
        cout << "1 - Вызов объектом производного класса методов базовых классов(Просмотр)" << endl;
        cout << "2 - Просмотр объекта производного класса " << endl;
        cout << "3 - Вызов уникального метода производного класса " << endl;
        cout << "4 - Выход " << endl;
        k=getch();
        switch (k)
        {
            case'1':
            {
                ob.Device::Output();
                cout<<"-----------------------"<<endl;
                ob.Tune::Output();
                system("pause");
                break;
            }
            case '2':
            {
                cout<<"Данные устройства:"<<endl;
                ob.Output();
                system("pause");
                break;
            }
            case '3':
            {
                ob.Range();
                system("pause");
                break;
            }
            case '4':
                return 0;
            default:
                cout <<"Выберите пункт меню"<< endl;
        }
    }
    return 0;
}
