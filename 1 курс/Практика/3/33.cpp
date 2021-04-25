#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

const int lenfio=20, len=5;

struct stud
{
    char fio[lenfio], n[len];
    char fiz[len], ist[len], mat[len];
};
struct node
{
    stud data;
    node* left;
    node* right;
};

const int size_p=sizeof(stud);

node* addtree(node *top,const stud& newnode);
int menu();
int node_count(node *top,int &n);
void otobr(node *top, int otstup);
void prosmotr(node *top);
int write_file(ofstream &f, node* top);
int read_file(char* file, node* &top);
void del(node *top);
stud vvod();

int main()
{
    setlocale(0,"Russian");
    node *top=0;
    char *file="stud.txt";
    ofstream fout;
    read_file(file,top);
    while (1)
    {
        switch (menu())
        {
            case 1: {
                        top=addtree(top,vvod());
                        break;
                    }
            case 2: {
                        otobr(top,1);
                        cout<<"Нажмите любую клавишу "<<endl;
                        cin.get();
                        break;
                    }
            case 3: {
                        cout<<" Номер |     Ф.И.О.     | Физика | История | Математика "<<endl;
                        prosmotr(top);
                        cout<<"Нажмите любую клавишу "<<endl;
                        cin.get();
                        break;
                    }
            case 4: {
                        int level;
                        int n=0;
                        cout<<node_count(top,n)<<endl;
                        cout<<"Нажмите любую клавишу "<<endl;
                        cin.get();
                        break;
                    }
            case 5: {
                        ofstream fout(file);
                        if (!fout)
                        {
                            cout<<"Ошибка открытия файла"<<endl;
                            return 1;
                        }
                        write_file(fout,top);
                        cout<<"Данные сохранены в файле: "<<file<<endl;
                        cout<<"=============================="<<endl;
                        fout.close();
                        cout<<"Нажмите любую клавишу "<<endl;
                        cin.get();
                        break;
                    }
            case 6: {
                        del(top);
                        break;
                    }
            case 7: return 0;
            default: {
                        cout<<"Вам следует ввести число от 1 до 6"<< endl;
                        cin.get();
                        break;
                     }
        }
    }
}
//-------------------------------------------------------------------

node* addtree(node *top,const stud& newnode)
{
    if (!top)
    {
        top=new node;
        if (!top)
        {
            cout<<"Не хватает памяти"<<endl;
            return NULL;
        }
        top->data=newnode;
        top->left=NULL;
        top->right=NULL;
    }
    else
    if (strcmp(top->data.n,newnode.n)>0)
    top->left=addtree(top->left,newnode);
    else
    top->right=addtree(top->right,newnode);
    return top;
}

void otobr(node *top, int otstup)
{
    if (top)
    {
        otstup+=3;
        otobr(top->right,otstup);
        cout<<setw(otstup)<<'*'<<top->data.fio<<endl;
        otobr(top->left,otstup);
    }
}

void prosmotr(node *top)
{
    if (top)
    {
        cout<<setw(8)<<left<<top->data.n;
        cout<<setw(18)<<left<<top->data.fio;
        cout<<setw(9)<<left<<top->data.fiz;
        cout<<setw(10)<<left<<top->data.ist;
        cout<<setw(13)<<left<<top->data.mat<<endl;
        prosmotr(top->left);
        prosmotr(top->right);
    }
}

void del(node *top)
{
        if(top->left) del(*top->left);
        if(top->right) del(*top->right)
        delete top;
    cout<<"Нажмите любую клавишу "<<endl;
    cin.get();
}



stud vvod()
{
    stud p;
    cout<<"Введите номер"<<endl;
    cin.getline(p.n,len);
    cout<<"Введите ф.и.о."<<endl;
    cin.getline(p.fio,lenfio);
    cout<<"Введите оценку по физике"<<endl;
    cin.getline(p.fiz,len);
    cout<<"Введите оценку по истории"<<endl;
    cin.getline(p.ist,len);
    cout<<"Введите оценку по математике"<<endl;
    cin.getline(p.mat,len);
    return p;
}

int menu()
{
    key
    {
        system("CLS");

            cout<<endl;
            cout<<"==========ДЕРЕВЬЯ==========="<<endl<<endl;
            cout<<"1- Добавить элемент в дерево"<<endl;
            cout<<"2- Отобразить структуру дерева"<<endl;
            cout<<"3- Просмотр дерева"<<endl;
            cout<<"4- Подсчет узлов с одним потомком"<<endl;
            cout<<"5- Запись данных в файл"<<endl;
            cout<<"6- Удаление дерева"<<endl;
            cout<<"7- Выход"<<endl;
            cout<<"============================"<<endl;
            cout<<"Введите номер пункта меню"<<endl;
        cin>>buf;
        cin.get();
        item=atoi(buf);
        if (!item)
        {
            cout<<"Вам следует ввести число от 1 до 6"<<endl;
            cin.get();
        }
    while (!item);
    return item;
}

int node_count(node *top,int &n)
{
    if (top)
    {
        n=node_count(top->left, n);
        n=node_count(top->right, n);
        if((top->left!=NULL && top->right==NULL) || (top->left==NULL && top->right!=NULL))
            n++;
    }
    return n;
}

int read_file(char* file, node* &top )
{
    ifstream fin(file,ios::in);
    if (!fin)
    {
        cout<<"Не найден файл"<<file<<endl;
        return 1;
    }
    stud p;
    top = 0;
    while (fin.getline(p.n,len))
    {
        fin.getline(p.fio,lenfio);
        fin.getline(p.fiz,len);
        fin.getline(p.ist,len);
        fin.getline(p.mat,len);
        top=addtree(top,p);
    }
    return 0;
}

int write_file(ofstream &f, node* top)
{
    if (top)
    {
        f<<top->data.n<<endl;
        f<<top->data.fio<<endl;
        f<<top->data.fiz<<endl;
        f<<top->data.ist<<endl;
        f<<top->data.mat<<endl;
        write_file(f,top->left);
        write_file(f,top->right);
    }
    return 0;
}





