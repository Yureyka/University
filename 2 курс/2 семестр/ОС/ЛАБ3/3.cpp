#include <cstring>
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

struct files
{
    char name[9], type[4];
    int year, mon, day;
    int count;
    int size;
    int hour, minute;
} file;

void input(struct files *file, int N);
void output(struct files *file, int N);
void sort(struct files *file, int N);

int main()
{
	setlocale(0,"RUS");
	char c; int N;
	cout<<"Введите размер массива структуры: "; cin>>N;
	files *file = new files[N];
	input(file, N);
	output(file, N);
	sort(file, N);
	output(file, N);
}


void input (struct files *file, int N)
{
	cout << "\nINPUTTING" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "Название файла: "; cin >> gets(file[i].name);
		cout << "Тип файла: "; cin >> gets(file[i].type);
        cout << "Дата: " << endl;
        cin >> file[i].day;
        cout << "/"; cin >> file[i].mon;
        cout << "/"; cin >> file[i].year;
        cout << "Кол-во обращений: "; cin >> file[i].count;
        cout << "Размер файла: "; cin >> file[i].size;
        cout << "Время последней модификации." << endl;
        cout << " Часы: "; cin >> file[i].hour;
        cout << " Минуты: "; cin >> file[i].minute;
        cout << "--------------------------------" << endl;
	}
}

void output (struct files *file, int N)
{
	cout << "\n|---------------------------------OUTPUT---------------------------------|" << endl;
	cout << "|------------------------------------------------------------------------|" << endl;
	cout << "| Название |  Тип  |   Дата   | Обращения |  Размер  | Время модификации |"<<endl;
	cout << "|------------------------------------------------------------------------|" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << setw(10) << file[i].name
			 << setw(6) << file[i].type
			 << setw(6) << file[i].day << "." << file[i].mon << "."
             << file[i].year
			 << setw(13) << file[i].count
			 << setw(9) << file[i].size
			 << setw(17) << file[i].hour << ":" << file[i].minute << endl;
        cout << "-------------------------------------------------------------------------" << endl;
	}
}

void sort (struct files *file, int N)
{
	int min = 0;
	files buf;
	for (int i = 0; i < N; i++)
    {
        min = i;
        for (int j = i + 1; j < N; j++)
            min = (file[j].size < file[min].size) ? j : min;
        if (i != min)
        {
            strcpy(buf.name, file[i].name);
            strcpy(buf.type, file[i].type);
            buf.year = file[i].year;
            buf.mon = file[i].mon;
            buf.day = file[i].day;
            buf.count = file[i].count;
            buf.size = file[i].size;
            buf.hour = file[i].hour;
            buf.minute = file[i].minute;
            strcpy(file[i].name, file[min].name);
            strcpy(file[i].type, file[min].type);
            file[i].year = file[min].year;
            file[i].mon = file[min].mon;
            file[i].day = file[min].day;
            file[i].count = file[min].count;
            file[i].size = file[min].size;
            file[i].hour = file[min].hour;
            file[i].minute = file[min].minute;
            strcpy(file[min].name, buf.name);
            strcpy(file[min].type, buf.type);
            file[min].year = buf.year;
            file[min].mon = buf.mon;
            file[min].day = buf.day;
            file[min].count = buf.count;
            file[min].size = buf.size;
            file[min].hour = buf.hour;
            file[min].minute = buf.minute;
        }
    }

}
