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
