#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <conio.h>

const int d_f=20,
d_a=80;

struct gruz_p
{char fio[d_f],
address[d_a];
};
struct node
 { gruz_p data;

node* left;
node* right;
};

node* addtree(node *top,const gruz_p& newnode);
int menu();
int node_count(node *top,int level,int &n);

void otobr(node *top, int otstup);
void prosmotr(node *top);

int write_file(ofstream &f, node* top);
int read_file(char* filename, node* &top);
gruz_p vvod();

int main()
{ node *top=0;
 char *filename="gruz.txt";
 ofstream fout;
 read_file(filename,top);

 while (1)
 { switch (menu())
{case 1:
 top=addtree(top,vvod());
 break;
case 2:
 otobr(top,1);
 cout<<"Нажмите любую клавишу "<<endl;
 cin.get();
 break;
case 3:
 prosmotr(top);
 cout<<"Нажмите любую клавишу "<<endl;
 cin.get();
 break;
case 4:
 int level;
 int n=0;
 cout<<"Введите значение уровня"<<endl;
 cin>>level;
 cin.get();
 cout<<"На данном уровне:"<<node_count(top,level,n)
<<"вершин"<<endl;
 cout<<"Нажмите любую клавишу "<<endl;
 cin.get();
 break;
case 5:
 fout.open(filename);
 if (!fout){
cout<<"Ошибка открытия файла"<<endl; return 1;}
 write_file(fout,top);
 cout<<"Данные сохранены в файле: "<<filename<<endl;
 cout<<"=============================="<<endl;
 fout.close();
 cout<<"Нажмите любую клавишу "<<endl;
 cin.get();
 break;
case 6:
 return 0;
default:
 cout<<"Вам следует ввести число от 1 до 6"<< endl;
 cin.get();
 break;
}
 }
}

node* addtree(node *top,const gruz_p& newnode)
{ if (!top)
{top=new node;
if (!top) {cout<<"Не хватает памяти"<<endl;
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
top->right=addtree(top->right,newnode);
return top;
}

void otobr(node *top, int otstup)
{ if (top)
{otstup+=3;
otobr(top->right,otstup);

cout<<setw(otstup)<<'*'<<top->data.fio<<endl;
otobr(top->left,otstup);
}
}

void prosmotr(node *top)
{ if (top)
{cout<<top->data.fio<<endl;
cout<<top->data.address<<endl;
prosmotr(top->left);
prosmotr(top->right);
}
}

gruz_p vvod()
{ gruz_p p;
cout<<"Введите ф.и.о."<<endl;
cin.getline(p.fio,d_f);
cout<<"Введите адрес"<<endl;
cin.getline(p.address,d_a);
return p;
}

int menu()
{ char buf[10];
int item;
do
 {clrscr();
 cout<<endl;
 cout<<"==========ДЕРЕВЬЯ==========="<<endl<<endl;
 cout<<"1- Добавить элемент в дерево"<<endl;
 cout<<"2- Отобразить структуру дерева"<<endl;
 cout<<"3- Просмотр дерева"<<endl;
 cout<<"4- Подсчет узлов на заданном уровне"<<endl;
 cout<<"5- Запись данных в файл"<<endl;
 cout<<"6- Выход"<<endl;
 cout<<"============================"<<endl;
 cout<<"Введите номер пункта меню"<<endl;
 cin>>buf;
 cin.get();
 item=atoi(buf);
 if (!item)
 { cout<<"Вам следует ввести число от 1 до 6"<<endl;
 cin.get();
 }
} while (!item);
return item;
}

int node_count(node *top,int level,int &n)
{
if ((level>=1)&&top)
 { if (level==1) n++;

n=node_count(top->left,level-1,n);

n=node_count(top->right,level-1,n);

}
return n;
}

int read_file(char* filename, node* &top )
{ ifstream fin(filename,ios::in);
if (!fin) {cout<<"Не найден файл"<<filename<<endl; return 1;}
gruz_p p;
top = 0;
while (fin.getline(p.fio,d_f))
{ fin.getline(p.address,d_a);
 top=addtree(top,p);
}
return 0;
}

int write_file(ofstream &f, node* top)
{ if (top)
 { f<<top->data.fio<<endl;
 f<<top->data.address<<endl;
 write_file(f,top->left);
 write_file(f,top->right);
 }
return 0;

}





