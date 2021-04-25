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
            cout<<"��������: ";
            cin>>name;
            cout<<"�������������: ";
            cin>>prod;
            cout<<"��������: ";
            cin>>pow;
        }

        void Output()
        {
            cout<<"�������� ���������:"<<endl<<endl;
            cout<<"��������: "<<name<<endl;
            cout<<"�������������: "<<prod<<endl;
            cout<<"��������: "<<pow<<endl;
        }
};

class Tune
{
    public:
        float freq, vol;
        Tune()
        {
            cout<<"������� ���������(��): ";
            cin>>vol;
            cout<<"������� ������� (��): ";
            cin>>freq;
        }

    void Output()
    {
        cout<<"����������� ���������:"<<endl;
        cout<<"���������: "<<vol<<endl;
        cout<<"�������: "<<freq<<endl;
    }
};

class Siren : public Device, public Tune
{
    public:
        int r1, r2;
        void Range()
        {
            cout<<"�������� ����������� �������� ������: "<<endl;
            cout<<"������ �����: ";
            cin>>r1;
            cout<<"������� �����: ";
            cin>>r2;
        }

    void Output()
    {
        cout<<"��������: " <<name<<endl;
        cout<<"�������������: "<<prod<<endl;
        cout<<"���������: "<<vol<<endl;
        cout<<"�������� ������: "<<r1<<".."<<r2<<endl;
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
        cout << "1 - ����� �������� ������������ ������ ������� ������� �������(��������)" << endl;
        cout << "2 - �������� ������� ������������ ������ " << endl;
        cout << "3 - ����� ����������� ������ ������������ ������ " << endl;
        cout << "4 - ����� " << endl;
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
                cout<<"������ ����������:"<<endl;
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
                cout <<"�������� ����� ����"<< endl;
        }
    }
    return 0;
}
