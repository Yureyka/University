#include <fstream> 
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#include <time.h> 
#include <iomanip> 
#include <conio.h> 
#include <iostream> 
using namespace std; 

struct elem
{
	int number;
	string name;
	elem *next, *prev;
};

class product
{
private:
	elem * head, *tail;
public:
	product() : head(NULL), tail(NULL) {};
	
	product(product &cop)
	{
		elem *temp, *el;
		if (!cop.head) return;
		head = new elem;
		head->number = cop.head->number;
		head->name = cop.head->name;
		head->next = NULL;
		tail = head;
		temp = cop.head->next;
		while (temp)
		{
			el = new elem;
			tail->next = el;
			tail=el;
			tail->next = 0;
			tail->number = temp->number;
			tail->name = temp->name;
			temp = temp->next;
		}
	}
	
	~product()
	{
		elem *temp = head;
		while (head)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
	}
	
	void vvod(elem *temp);
	void add_el();
	void vivod();
	void change();
	int sozdanie();
	void del();
	void poisk();
};

void product::vvod(elem *temp)
{
	cout << "����� ������:" << endl;
	cin >> temp->number;
	cout << "�������� ������:" << endl;
	cin >> temp->name;
}

void product :: change()
{
	int i = 1, n;
	elem *tmp;
	cout<<"������� ����� ����������� ����:"<< endl;
	cin >> n;
	tmp = head;
	while (i!= n)
	{
		i++;
		tmp = tmp->next;
	}
	vvod(tmp);
}

int product :: sozdanie()
{
	char key;
	elem *newE;
	newE = new elem;
	vvod(newE);
	newE->next = head;
	head = newE;
	tail = newE;
	do
	{
		cout << "�������� ��� ������?" << endl;
		cout << "1 - ��" << endl;
		cout << "2 - ���" << endl;
		cin >> key;
		switch (key)
		{
			case '1': add_el(); break;
			case '2': return 0;
		}
	} 
	while (1);
}

void product :: add_el()
{
    elem *newE  = new elem;
    vvod(newE);
    if (!head) 
	{
        newE -> next = tail;
        tail = newE;
    }
    else 
	{
        newE -> next = head;
        head -> prev = newE;
    }
    head = newE;
    head -> prev = NULL;
 
}

void product::vivod()
{
	elem *temp;
	temp = head;
	if (head)
	{
		while (temp)
		{
			cout << "  " << temp->number<< "               " << temp->name << endl;
			temp = temp->next;
		}
	}
}
void product :: del()
{
	elem *temp = 0;
	if (head)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	else cout << "������ ����" << endl;
}

void product :: poisk()
{
    elem* temp2=head;
    int index, i;
    cout << "������� ����� ��� ������:" << endl;
    cin >> index;
    while(temp2)
    {
        if(temp2->number==index) i++;
        temp2=temp2->next;
    }
    if (i!=0) cout << "�������" << endl;
    else cout << "�� �������" << endl;
}

int main()
{
	setlocale(0, "rus");
	char key1, key2;
	product p1;
	cout << "��� �������� ������ ������� ������." << endl;
	p1.sozdanie();
	product p2(p1);
	system("cls");
	while (1)
	{
		cout << "1 - �������� ������" << endl;
		cout << "2 - ������� �����" << endl;
		cout << "3 - �������� �����" << endl;
		cout << "4 - ������� �����" << endl;
		cout << "5 - ����� ������" << endl;
		cout << "6 - �����" << endl;
		cin >> key2;   
		switch (key2)
		{
			case '1':
			{    
				cout << "-------------------------------" << endl;
				cout << "| �����    "<<"          �������� |" << endl;
				cout << "|-----------------------------|" << endl;
				cout << "|          ��������:          |" << endl;
				cout << "|-----------------------------|" << endl;
				p1.vivod();
				cout << "|-----------------------------|" << endl;
				cout << "|           �����:            |" << endl;
				cout << "|-----------------------------|" << endl;
				p2.vivod();
				cout << "------------------------------" << endl;
				system("pause");
				system("cls");
			}
				break;
			case '2':
			{   
				cout << "��� ������� �������?" << endl;
				cout << "1 - ��������" << endl;
				cout << "2 - �����" << endl;
				cin >> key1;
				switch (key1)
				{
					case'1':p1.del(); break;
					case'2':p2.del(); break;
				}
				system("pause");
				system("cls");
			}
				break;
			case '3':
			{
				cout << "���� �������� �������?" << endl;
				cout << "1 - ��������" << endl;
				cout << "2 - �����" << endl;
				cin >> key1;
				switch (key1)
				{
					case'1':p1.add_el(); break;
					case'2':p2.add_el(); break;
				}
				system("pause");
				system("cls");
			} 
				break;
			case'4':
			{
				cout << "��� �������� �������?" << endl;
				cout << "1 - ��������" << endl;
				cout << "2 - �����" << endl;
				cin >> key1;
				switch (key1)
				{
					case'1':p1.change(); break;
					case'2':p2.change(); break;
				}
				system("pause");
				system("cls");
			} 
				break;
			case '5':
			{
				p1.poisk();
				system("pause");
				system("cls");
				break;
			} 
			case '6': return 0;
			default: cout << "������� ����� �� 1 �� 6:" << endl;
		}
	}
}
