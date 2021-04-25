#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <conio.h>
#include <iostream>
#include <windows.h>

const int lenfio=20, len=15;

struct stud
{
    char n[len], year[len], sal[len], sex[len];
    char fio[lenfio], fam[len];
};
struct node
{
    stud data;
    node* left;
    node* right;
};

node* addtree(node *top,const stud& newnode);
int menu();
int nc(node *top,int level,int &n);

void otobr(node *top, int o);
void view(node *top);

int writefile(ofstream &f, node* top);
int readfile(char* file, node* &top);
stud input();

int main()
{
    node *top=0;
    char *file="123.txt";
    ofstream fout;
    readfile(file,top);
    while (1)
    {
        switch (menu())
        {
            case 1: top=addtree(top,input()); break;
            case 2: otobr(top,1);
                    cout<<"������� ����� ������� "<<endl;
                    cin.get();
                    break;
            case 3: view(top);
                    cout<<"������� ����� ������� "<<endl;
                    cin.get();
                    break;
            case 4: int level;
                    int n=0;
                    cout<<"������� �������� ������"<<endl;
                    cin>>level;
                    cin.get();
                    cout<<"�� ������ ������:"<<nc(top,level,n)<<"������"<<endl;
                    cout<<"������� ����� ������� "<<endl;
                    cin.get();
                    break;
            case 5: fout.open(file);
                    if (!fout)
                    {
                        cout<<"������ �������� �����"<<endl;
                        return 1;
                    }
                    writefile(fout,top);
                    cout<<"������ ��������� � �����: "<<file<<endl;
                    cout<<"=============================="<<endl;
                    fout.close();
                    cout<<"������� ����� ������� "<<endl;
                    cin.get();
                    break;
            case 6: return 0;
            default: cout<<"��� ������� ������ ����� �� 1 �� 6"<< endl;
                     cin.get();
                     break;
        }
    }
}

node* addtree(node *top,const stud& newnode)
{
    if (!top)
    {
        top=new node;
        if (!top)
        {
            cout<<"�� ������� ������"<<endl;
            return NULL;
        }
        top->data=newnode;
        top->left=NULL;
        top->right=NULL;
    }
    else
        if (strcmp(top->data.fio,newnode.fio)>0)
            top->left=addtree(top->left,newnode);
        else
            top->right=addtree(top->right,newnode);/
    return top;
}

void otobr(node *top, int o)
{
    if (top)
    {
        o+=3;
        otobr(top->right,o);
        cout<<setw(o)<<'*'<<top->data.fio<<endl;
        otobr(top->left,otstup);
    }
}

void view(node *top)
{
    if (top)
    {
        cout<<top->data.num<<endl;
        cout<<top->data.fio<<endl;
        cout<<top->data.year<<endl;
        cout<<top->data.sex<<endl;
        cout<<top->data.fam<<endl;
        cout<<top->data.sal<<endl;
        prosmotr(top->left);
        prosmotr(top->right);
    }
}

stud input()
{
    stud p;
    cout<<"������� �����"<<endl;
    cin.getline(p.n,len);
    cout<<"������� �.�.�."<<endl;
    cin.getline(p.fio,lenfio);
    cout<<"������� ��� ��������"<<endl;
    cin.getline(p.year,len);
    cout<<"������� ���"<<endl;
    cin.getline(p.sex,len);
    cout<<"������� �������� ���������"<<endl;
    cin.getline(p.fam,len);
    cout<<"������� ���������"<<endl;
    cin.getline(p.sal,len);
return p;
}

int menu()
{
    char buf[10];
    int item;
    do
    {
        system("cls");
        cout<<endl;
        cout<<"==========�������==========="<<endl<<endl;
        cout<<"1- �������� ������� � ������"<<endl;
        cout<<"2- ���������� ��������� ������"<<endl;
        cout<<"3- �������� ������"<<endl;
        cout<<"4- ������� ����� �� �������� ������"<<endl;
        cout<<"5- ������ ������ � ����"<<endl;
        cout<<"6- �����"<<endl;
        cout<<"============================"<<endl;

        cout<<"������� ����� ������ ����"<<endl;
        cin>>buf;
        cin.get();
        item=atoi(buf);
        if (!item)
        {
            cout<<"��� ������� ������ ����� �� 1 �� 6"<<endl;
            cin.get();
        }
    }
    while (!item);
        return item;
}

int nc(node *top,int level,int &n)
{
    if ((level>=1)&&top)
    {
        if (level==1) n++;
        n=nc(top->left,level-1,n);
        n=nc(top->right,level-1,n);

    }
    return n;
}

int readfile(char* file, node* &top )
{
    ifstream fin(file,ios::in);
    if (!fin)
        {
            cout<<"�� ������ ����"<<file<<endl;
            return 1;
        }
    stud p;
    top = 0;
    while (fin.getline(p.fio,lenfio))
    {
        fin.getline(z.n,len);
        fin.getline(z.year,len);
        fin.getline(z.sex,len);
        fin.getline(z.fam,len);
        fin.getline(z.sal,len);
        fin.get();
        top=addtree(top,p);
    }
    return 0;
}

int writefile(ofstream &f, node* top)
{
    if (top)
    {
        f<<top->data.n<<endl;
        f<<top->data.fio<<endl;
        f<<top->data.year<<endl;
        f<<top->data.sex<<endl;
        f<<top->data.fam<<endl;
        f<<top->data.sal<<endl;
        writefile(f,top->left);
        writefile(f,top->right);
    }
    return 0;
}











