#include <stdlib.h>
#include <iostream>

using namespace std;

void second (int A[4], int B[5])
{

}

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
