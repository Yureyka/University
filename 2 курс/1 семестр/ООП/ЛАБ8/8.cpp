#include <iostream>
#include <iomanip>
#include <list>
#include <iterator>
#include <string>
#include <algorithm>
#include <windows.h>
using namespace std;

class Accounting
{
    public:
        string punct, num, name, date;
        Accounting(string p, string n, string nn, string d)
        {
            punct=p;
            num=n;
            name=nn;
            date=d;
        }
        Accounting() {}
        ~Accounting() {}

        bool operator() (const Accounting &first, const Accounting &second)
        {
            return (first.name<second.name);
        }
};

int main()
{
	setlocale(0,"rus");

	Accounting buf;
	list<Accounting> L;
	list<Accounting>::iterator iter;

	int t, count, N=0;
	while (1)
	{
		cout<<"1 - Добавить в начало"<<endl;
		cout<<"2 - Добавить в конец"<<endl;
		cout<<"3 - Удалить заявку"<<endl;
		cout<<"4 - Удалить все заявки"<<endl;
		cout<<"5 - Вывод всех заявок"<<endl;
		cout<<"6 - Выод заявок по номеру и дате"<<endl;
		cout<<"7 - Выход"<<endl;
		cout<<"Введите пункт меню: "; cin>>t;
		system("cls");
		switch (t)
		{
			case 1:
			{
                cout<<"Пункт назначения: "; cin>>buf.punct;
                cout<<"Номер рейса: "; cin>>buf.num;
                cout<<"Имя: "; cin>>buf.name;
                cout<<"Дата: "; cin>>buf.date;
                L.push_front(buf);
				system("pause");
				system("cls");
				break;
			}
			case 2:
			{
				int n;
				cout<<"Сколько записей вы хотите ввести? "; cin>>n;
				for (int i=0; i<n; i++)
				{
					cout<<"Пункт назначения: "; cin>>buf.punct;
					cout<<"Номер рейса: "; cin>>buf.num;
			        cout<<"Имя: "; cin>>buf.name;
			        cout<<"Дата: "; cin>>buf.date;
					L.push_back(buf);
				}
				system("cls");
				break;
			}
			case 3:
			{
				string nameb;
				bool p=false;
				if (L.empty()) cout<<"Записей нет!"<<endl;
				else
				{
					cout<<"Введите имя пассажира для удаления записи "; cin>>nameb;
					for (iter=L.begin(); iter!=L.end(); iter++)
					{
						if ((*iter).name==nameb)
						{
							p=true;
							L.erase(iter);
						}
					}
					if (!p) cout<<"Запись не найдена!"<<endl;
				}
				system("pause");
				system("cls");
				break;
			}
			case 4:
			{
				if (L.empty()) cout<<"Записей нет!"<<endl;
				else L.clear();
				system("pause");
				system("cls");
				break;
			}
			case 5:
			{
				if (L.empty()) cout<<"Записей нет!"<<endl;
				else
				{
					cout<<"|"<<setw(16)<<"Пункт назначения"<<"|";
					cout<<setw(8)<<"Номер рейса"<<"|";
					cout<<setw(21)<<"Имя пассажира"<<"|";
					cout<<setw(12)<<"Дата вылета"<<"|"<<endl;
					for (iter=L.begin(); iter != L.end(); ++iter)
					{
						cout<<"|"<<setw(16)<<(*iter).punct<<"|";
                        cout<<setw(9)<<(*iter).num<<"  |";
                        cout<<setw(20)<<(*iter).name<<" |";
                        cout<<setw(12)<<(*iter).date<<"|"<<endl;
					}
				}
				system("pause");
				system("cls");
				break;
			}

			case 6:
			{
				string numb, dateb;
				bool p=false;
				if (L.empty()) cout<<"Записей нет!"<<endl;
				else
				{
					cout<<"Введите номер и дату рейса ";
					cin>>numb;
					cin>>dateb;
					cout<<"|"<<setw(16)<<"Пункт назначения"<<"|";
					cout<<setw(8)<<"Номер рейса"<<"|";
					cout<<setw(21)<<"Имя пассажира"<<"|";
					cout<<setw(12)<<"Дата вылета"<<"|"<<endl;
					for (iter=L.begin(); iter!=L.end(); iter++)
					{
						if ((*iter).num==numb && (*iter).date==dateb)
						{
							p=true;
							cout<<"|"<<setw(16)<<(*iter).punct<<"|";
                            cout<<setw(8)<<(*iter).num<<"  |";
                            cout<<setw(20)<<(*iter).name<<" |";
                            cout<<setw(12)<<(*iter).date<<"|"<<endl;
						}
					}
					if (!p) cout<<"Запись не найдена!"<<endl;
				}
				system("pause");
				system("cls");
				break;
			}
			case 7: return 0;
		}
	}
}
