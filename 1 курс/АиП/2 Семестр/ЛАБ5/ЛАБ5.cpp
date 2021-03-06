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
    stud* next;
}  ;

const int size_p=sizeof(stud);

stud* add(stud* end, const stud& z);
stud* addf(const stud& z);
stud* addff(stud *beg,const stud& z);
stud* del(stud* beg);
stud  inpstruct();
int  menu();
void print(const stud& z);
void view(stud* beg);
int sorting(char* file);
int  readfile(char* file, stud** beg, stud** end);
int  writefile(char* file, stud* temp);

int main()
{
    setlocale(0,"Russian");
    stud *beg=0, *end=0;
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
            default: cout<<"??? ??????? ?????? ????? ?? 1 ?? 5"<< endl;
                     cin.get();
                     break;
        }
    }
}
//-------------------------------------------------------------------

stud* add(stud *end,const stud& z)
{
    stud *newE=new stud;
    *newE=z;
    newE->next=0;
    end->next=newE;
    end=newE;
    return end;
}

stud* addf(const stud& z)
{
    stud *beg=new stud;
    stud elem;
    *beg=z;
    beg->next=0;
    return beg;
}

stud* addff(stud *beg,const stud& z)
{
    stud *newE=new stud;
	*newE=z;
	newE->next=beg;
	beg=newE;
	return beg;
}

stud* del(stud *beg)
{
    stud *temp;
    if (!beg) { cout<<"??????? ??????"<<endl; return 0; }
    while(temp->next!=NULL)
    {
        temp=beg;
        beg=beg->next;
    }
    delete temp;
    return beg;
}



void Vstavka(stud *&ph, int v)
{

}

stud inpstruct()
{
    char buf[10];
    stud z;
    cout<<"??????? ?????"<<endl;
    cin.getline(z.n,len);
    cout<<"??????? ?.?.?."<<endl;
    cin.getline(z.fio,lenfio);
    cout<<"??????? ?????? ?? ??????"<<endl;
    cin.getline(z.fiz,len);
    cout<<"??????? ?????? ?? ???????"<<endl;
    cin.getline(z.ist,len);
    cout<<"??????? ?????? ?? ??????????"<<endl;
    cin.getline(z.mat,len);
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
        cout<<"1- ?????????? ???????? ? ???????"<<endl;
        cout<<"2- ???????? ??????"<<endl;
        cout<<"3- ?????????? ???????? ? ?????? ???????"<<endl;
        cout<<"4- ???????? ???????"<<endl;
        cout<<"5- ?????? ?????? ? ????"<<endl;
        cout<<"6- ?????"<<endl;
        cout<<"============================"<<endl;
        cout<<"??????? ????? ?????? ????"<<endl;
        cin>>buf;
        cin.get();
        item=atoi(buf);
        if (!item)
        {
            cout<<"??? ??????? ??????? ????? ?? 1 ?? 5"<<endl;
            cin.get();
        }
    }
    while (!item);
    return item;
}

void print(const stud& z)
{
    cout<<setw(8)<<left<<z.n;
    cout<<setw(18)<<left<<z.fio;
    cout<<setw(9)<<left<<z.fiz;
    cout<<setw(10)<<left<<z.ist;
    cout<<setw(13)<<left<<z.mat;;
}

void view(stud *beg)
{
    if (!beg)
    {
        cout<<"??????? ??????"<<endl;
        cin.get();
        return;
    }
    stud *temp=beg;
    cout<<" ????? |     ?.?.?.     | ?????? | ??????? | ?????????? "<<endl;
    while (temp)
    {
        print(*temp);
        cout<<endl;
        cin.get();
        temp=temp->next;
    }
    cout<<"??????? ????? ???????"<<endl;
    cin.get();
}

int readfile(char* file,stud** beg, stud** end)
{
    ifstream fin(file,ios::in);
    if (!fin) {cout<<"??? ?????"<<file<<endl; return 1;}
    stud z;
    *beg = 0;
    while (fin.getline(z.n,len))
    {
        fin.getline(z.fio,lenfio);
        fin.getline(z.fiz,len);
        fin.getline(z.ist,len);
        fin.getline(z.mat,len);
        if (*beg)
            *end=add(*end,z);
        else
        {
            *beg=addf(z);
            *end=*beg;
        }
    }
return 0;
}

int writefile(char* file, stud* temp)
{
    ofstream fout(file);
    if (!fout) {cout<<"?? ???? ??????? ???? ??? ??????"<<endl; return 1;}
    while (temp)
    {
        fout<<temp->n<<endl;
        fout<<temp->fio<<endl;
        fout<<temp->fiz<<endl;
        fout<<temp->ist<<endl;
        fout<<temp->mat<<endl;
        temp=temp->next;
    }
    cout<<"?????? ????????? ? ?????: "<<file<<endl;
    cout<<"=============================="<<endl;
    cout<<"??????? ????? ???????"<<endl;
    cin.get();
    return 0;
}





