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
		cout<<"1 - �������� � ������"<<endl;
		cout<<"2 - �������� � �����"<<endl;
		cout<<"3 - ������� ������"<<endl;
		cout<<"4 - ������� ��� ������"<<endl;
		cout<<"5 - ����� ���� ������"<<endl;
		cout<<"6 - ���� ������ �� ������ � ����"<<endl;
		cout<<"7 - �����"<<endl;
		cout<<"������� ����� ����: "; cin>>t;
		system("cls");
		switch (t)
		{
			case 1:
			{
                cout<<"����� ����������: "; cin>>buf.punct;
                cout<<"����� �����: "; cin>>buf.num;
                cout<<"���: "; cin>>buf.name;
                cout<<"����: "; cin>>buf.date;
                L.push_front(buf);
				system("pause");
				system("cls");
				break;
			}
			case 2:
			{
				int n;
				cout<<"������� ������� �� ������ ������? "; cin>>n;
				for (int i=0; i<n; i++)
				{
					cout<<"����� ����������: "; cin>>buf.punct;
					cout<<"����� �����: "; cin>>buf.num;
			        cout<<"���: "; cin>>buf.name;
			        cout<<"����: "; cin>>buf.date;
					L.push_back(buf);
				}
				system("cls");
				break;
			}
			case 3:
			{
				string nameb;
				bool p=false;
				if (L.empty()) cout<<"������� ���!"<<endl;
				else
				{
					cout<<"������� ��� ��������� ��� �������� ������ "; cin>>nameb;
					for (iter=L.begin(); iter!=L.end(); iter++)
					{
						if ((*iter).name==nameb)
						{
							p=true;
							L.erase(iter);
						}
					}
					if (!p) cout<<"������ �� �������!"<<endl;
				}
				system("pause");
				system("cls");
				break;
			}
			case 4:
			{
				if (L.empty()) cout<<"������� ���!"<<endl;
				else L.clear();
				system("pause");
				system("cls");
				break;
			}
			case 5:
			{
				if (L.empty()) cout<<"������� ���!"<<endl;
				else
				{
					cout<<"|"<<setw(16)<<"����� ����������"<<"|";
					cout<<setw(8)<<"����� �����"<<"|";
					cout<<setw(21)<<"��� ���������"<<"|";
					cout<<setw(12)<<"���� ������"<<"|"<<endl;
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
				if (L.empty()) cout<<"������� ���!"<<endl;
				else
				{
					cout<<"������� ����� � ���� ����� ";
					cin>>numb;
					cin>>dateb;
					cout<<"|"<<setw(16)<<"����� ����������"<<"|";
					cout<<setw(8)<<"����� �����"<<"|";
					cout<<setw(21)<<"��� ���������"<<"|";
					cout<<setw(12)<<"���� ������"<<"|"<<endl;
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
					if (!p) cout<<"������ �� �������!"<<endl;
				}
				system("pause");
				system("cls");
				break;
			}
			case 7: return 0;
		}
	}
}
