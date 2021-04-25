#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <conio.h>
using namespace std;
struct stud
{
    char fio[25];
    char num[5];
    char usp[10];
    stud *next;
};

string s;
const int size_p=sizeof(stud);
int input();
int sorting();
int output(FILE *file);
int searching();

int n=0;

int main()
{
    setlocale(LC_ALL, "rus");
    fstream file ("123.bin", ios::in);
    if (!file)
    {   cout<<"����� � ����� ������ �� ����������!"<<endl;
        return 1;
    }
     while (1)
        {
             system("cls");
             puts("1- ������ � ����");
             puts("2- ���������� �����");
             puts("3- ����� �����");
             puts("4- ����� ��������");
             puts("5- �����");
             puts("______________________________");
             puts("������� ����� ������ ����...");
             char c=getch();
             switch (c)
             {
                 case '1':input();break;
                 case '2':sorting();break;
                 case '3':output();break;
                 case '4':searching();break;
                 case '5':return 0;
             }
        }
    return 0;
}

int input()
{
    fstream file("123.bin", ios::out);
    stud elem;
    file.seekp(0, ios::end);
    puts("���� ������ � �����������");
    puts("��� ������ ������� ������ *");
    puts("_________________________________\n");
    while (1)
        {
            puts("������� �������");
            cin.getline(elem.fio, 25);
            if (!strcmp(elem.fio,"*")) return 1;
            puts("������� ������");
            cin.getline(elem.num, 5);
            puts("������� ������������ �� ������, ����������, ����������� � ����������������");
            cin.getline(elem.usp, 10);
            n++;
        }
    file.close();
}

int sorting()
{
    int i, j, k=0;
    stud elem, elem1, elem2, tmp;
    fstream file("123.bin", ios::in);
    puts("��� ���������� ������� ����� �������");
    getch();
    file.seekg(0, ios::beg);
    stud *mass = new stud [n];
    while(!EOF)
    {
        mass[k]=elem;
        k++;
    }

            if(strcmp(elem1.fio, elem2.fio)>0)
            {
               tmp=elem1;
               elem1=elem2;
               elem2=tmp;
            }
    file.close();
    ofstream f("123.txt",ios::trunc);
    f.seekp(0, ios::end);
    for(i=0; i<n; i++)
    {
        f<<mass[i].fio;
        f<<mass[i].num;
        f<<mass[i].usp;
    }
    f.close();


    puts("��� ������ ������� ����� �������");
    getch();
    return 0;
}

int output(FILE *file)
{
    FILE *file;
    file=fopen("123.dat","r+b");
    stud elem;
    fseek(file, 0, SEEK_SET);
    do
    {
        n=fread(&elem,size_p,1,file);
        if (n<1) break;
        printf("%-15s%-6i%-8.2f\n",elem.fio,elem.num,elem.usp);
    }
    while (1);
    fclose(file);
}

int searching()
{
    fstream file("123.bin", ios::in);
    file.seekg(0, ios::end);
}
















