#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

struct data
{
    char adr[20], size[20];
    data* next;
    data* prev;
}  ;

const int size_p=sizeof(data);

data* add(data* end, const data& z);
data* del(data* beg);
data  inpstruct();
int  menu();
void print(const data& z);
void view(data* beg);
int sorting(char* file);
int  readfile(char* file, data** beg, data** end);
int  writefile(char* file, data* temp);

int main()
{
    setlocale(0,"Russian");
    data *beg=0, *end=0;
    char *file="123.txt";
    readfile(file, &beg, &end);
    while (1)
    {
        switch (menu())
        {
            case 1:  if (beg)
            {
                end=add(end,inpstruct());
            }
                     else {
                            beg=addf(inpstruct());
                            end=beg;
                          }
                     break;
            case 2: beg=del(beg);
                    cin.get();
                    break;
            case 3: addff(beg, inpstruct());
                    break;
            case 4: view(beg); break;
            case 5: writefile(file,beg); break;
            case 6: return 0;
            default: cout<<"Âàì ñëåäóåò ââåñòè íîìåð îò 1 äî 5"<< endl;
                     cin.get();
                     break;
        }
    }
}
//-------------------------------------------------------------------

data* add(data *end,const data& z)
{
    data *newE=new data;
    *newE=z;
    newE->next=0;
    end->next=newE;
    end=newE;
    return end;
}

data* addf(const data& z)
{
    data *beg=new data;
    data elem;
    *beg=z;
    beg->next=0;
    return beg;
}

data* del(data *beg)
{
    data *temp;
    if (!beg) { cout<<"Î÷åðåäü ïóñòàÿ"<<endl; return 0; }
    while(temp->next!=NULL)
    {
        temp=beg;
        beg=beg->next;
    }
    delete temp;
    return beg;
}

data* searching(data *beg)
{

}

data inpstruct()
{
    char buf[10];
    data z;
    z.adr = &z;
    z.size = sizeof(z)
    return z;
}

int menu()
{
    char buf[10];
    int item;
    do
    {
        system("cls");
        cout<<endl;
        cout<<"1- ÏÎÊÀÇÀÒÜ ÑÎÑÒÎßÍÈÅ ÏÀÌßÒÈ"<<endl;
        cout<<"2- ÂÛÄÅËÅÍÈÅ ÏÀÌßÒÈ"<<endl;
        cout<<"3- ÎÑÂÎÁÎÆÄÅÍÈÅ ÏÀÌßÒÈ"<<endl;
        cout<<"4- ÏÐÎÑÌÎÒÐ ÑÏÈÑÊÀ"<<endl;
        cout<<"5- Âûõîä"<<endl;
        cout<<"============================"<<endl;
        cout<<"Ââåäèòå íîìåð ïóíêòà ìåíþ"<<endl;
        cin>>buf;
        cin.get();
        item=atoi(buf);
        if (!item)
        {
            cout<<"Âàì ñëåäóåò ââîäèòü ÷èñëî îò 1 äî 5"<<endl;
            cin.get();
        }
    }
    while (!item);
    return item;
}

void print(const data& z)
{
    cout<<setw(8)<<left<<z.n;
    cout<<setw(18)<<left<<z.fio;
    cout<<setw(9)<<left<<z.fiz;
    cout<<setw(10)<<left<<z.ist;
    cout<<setw(13)<<left<<z.mat;;
}

void view(data *beg)
{
    if (!beg)
    {
        cout<<"Î÷åðåäü ïóñòàÿ"<<endl;
        cin.get();
        return;
    }
    data *temp=beg;
    cout<<" Àäðåñ ïåðâîãî áàéòà | Ðàçìåð áëîêà "<<endl;
    while (temp)
    {
        print(*temp);
        cout<<endl;
        cin.get();
        temp=temp->next;
    }
    cout<<"Íàæìèòå ëþáóþ êëàâèøó"<<endl;
    cin.get();
}
