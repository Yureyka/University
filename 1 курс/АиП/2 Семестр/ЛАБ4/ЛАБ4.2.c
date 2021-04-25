#include <stdio.h>
#include <string.h>
#include <conio.h>
//#include <iostream>
#include <windows.h>

const int len_fio=15;
struct stud
{
    char fio[len_fio], num;
    int usp[5];
};
const int size_p=sizeof(stud);

int creating(FILE *fbin);
int sorting(FILE *fbin);
int printing(FILE *fbin);
int searching(FILE *fbin);

int main()
{
    FILE *fbin;
    char c;
    fbin=fopen("123.dat","r+b");

    if (!fbin)
    {
        fbin=fopen("123.dat","w+b");
        if(!fbin)
        {
            puts("Can't open file\n");
            return 1;
        }
    }
    while (1)
    {
        system("cls");
        puts("1- Запись в файл");
        puts("2- Сортировка файла");
        puts("3- Вывод файла");
        puts("4- Поиск");
        puts("5- Выход");
        puts("______________________________");
        puts("Введите номер пункта меню\n");
        c=getch();
        switch (c)
        {
            case '1':creating(fbin);break;
            case '2':sorting(fbin);break;
            case '3':printing(fbin);break;
            case '4':searching(fbin);break;
            case '5':return 0;
        }
    }
}

int creating(FILE *fbin){
stud elem;
fseek(fbin,0,SEEK_END);
puts("Ввод данных о студентах");
puts("Для выхода введите символ *");
puts("_________________________________\n");
while (1) {
puts("Введите Ф.И.О. студента");
getline(elem.fio,len_fio);
if (!strcmp(elem.fio,"*"))
return 1;
puts("Введите группу");
scanf("%i",&elem.num);
puts("Введите успеваемость");
for(int i=0; i<5; i++)
    scanf("%f",&elem.usp[i]);
fwrite(&elem,size_p,1,fbin);
}
}

int printing(FILE *fbin){
stud elem;
int n;
clrscr();
rewind(fbin);
puts("Ф.И.О. Группа Успеваемость");
do
{
    n=fread(&elem,size_p,1,fbin);
    if (n<1) break;
    printf("%-15s%-6i",elem.fio,elem.year);
    for(int i=0; i<5; i++)
        printf("%-8.2f\n",elem.usp[i]);
}
while (1);
puts("_____________________________");
puts("Нажмите любую клавишу");
getch();
return 0;
}

int sorting(FILE *fbin) {
long i,j;
stud elem1,elem2;
puts("Для сортировки нажмите любую клавишу");
getch();
fseek(fbin,0,SEEK_END);
long len=ftell(fbin)/size_p;
rewind(fbin);

for(i=len-1;i>=1;i--)
 for (j=0;j<=i-1;j++) {
fseek(fbin,j*size_p,SEEK_SET);
fread(&elem1,size_p,1,fbin);
fread(&elem2,size_p,1,fbin);
if (strcmp(elem1.fio,elem2.fio)>=1) {
 fseek(fbin,(-2)*size_p,SEEK_CUR);

 fwrite(&elem2,size_p,1,fbin);
 fwrite(&elem1,size_p,1,fbin);
}
 }
puts("Для выхода нажмите любую клавишу");
getch();
return 0;
}

int searching(FILE *fbin){
int not_found;
char s[len_fio];
int n_studs=0;
int n;
float summa_salary=0;
stud elem;
while (1) {
puts("Введите фамилию или * ");
cin.getline(s,len_fio);
if (!strcmp(s,"*")) break;
rewind(fbin);
not_found=1;
do
{
 n=fread(&elem,size_p,1,fbin);
 if (n<1) break;
 if (strstr(elem.fio,s))
 if (elem.fio[strlen(s)]==' ')
 {
    strcpy(s,elem.fio);
    puts("_____________________________");
    puts("Ф.И.О. Год Зарплата");
    printf("%-15s%-6i%-8.2f\n",elem.fio,elem.year);
    for(int i=0; i<5; i++)
        printf("%-8.2f\n",elem.usp[i]);
    puts("_____________________________");
    not_found=0;
 }
}
while (1);
if (not_found)
puts("Такого студента нет в файле");
puts("Нажмите любую клавишу");
getch();
return 0;
}













