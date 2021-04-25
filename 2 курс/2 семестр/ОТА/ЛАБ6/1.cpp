#include <conio.h>
#include <time.h>
#include <ctime>
#include <windows.h>
#include <iostream>
#include <stdio.h>
using namespace std;

const int N = 10000;

struct student {
	char fio[10];
	int faculty;
	int kurs;
};


void insertSort(student *a, int n)
{
    int i, j;
    for(i = 2; i <= n; i++)
    {
        a[0].kurs = a[i].kurs;
        for(j = i-1; a[j].kurs > a[0].kurs; j--)
            a[j+1].kurs = a[j].kurs;
        a[j+1].kurs = a[0].kurs;
    }
}



void bubbleSort(student *a, int n)
{
    int i, j;
    for(i = n; i > 1; i--)
        for(j = 1; j < i; j++)
    if(a[j].kurs > a[j+1].kurs)
    swap(a[j].kurs, a[j+1].kurs);
}



void merge(student *a, int l, int r)
{
    student b[N];
    int m = (l+r) / 2;
    int i, j, k;
    i = l;
    j = m+1;
    k = l;
    while(i <= m || j <= r)
    {
        if(i > m)
        {
            b[k++].kurs = a[j++].kurs;
            continue;
        }
        if(j > r)
        {
            b[k++].kurs = a[i++].kurs;
            continue;
        }
        if(a[i].kurs < a[j].kurs)
            b[k++].kurs = a[i++].kurs;
        else
            b[k++].kurs = a[j++].kurs;
    }
    for(i = l; i <= r; i++)
        a[i].kurs = b[i].kurs;
}

void mergeSort(student *a, int l, int r)
{
    if(l == r)
    return;
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m+1, r);
    merge(a, l, r);
}




int main()
{
	setlocale(0, "Russian");
	FILE *def, *res;
	def = fopen("Default.txt", "w+");
	res = fopen("Result.txt", "w+");
	student a[N];
	int n = N;
	int key;
	for (int i = 0; i < n; i++) a[i].kurs = rand()%100;
	for (int i = 0; i < n; i++) fprintf(def, "%i ", a[i].kurs);
	cout << "Как отсортировать массив?" << endl;
	cout << "1 - Вставками" << endl;
	cout << "2 - Пузырьком" << endl;
	cout << "3 - Слияниями" << endl;
	cin >> key;
	double start_time, end_time;
	switch (key)
	{
		case 1:
			start_time = clock();
			insertSort(a, N);
			end_time = clock();
			break;
		case 2:
			start_time = clock();
			bubbleSort(a, N);
			end_time = clock();
			break;
		case 3:
			start_time = clock();
			mergeSort(a, 0, N-1);
			end_time = clock();
			break;
	}
	double time = end_time - start_time;
	cout << "Исходный и отсортированный массивы \nсохранены в файлах Default.txt и Result.txt" << endl;
	for (int i = 0; i < n; i++) fprintf(res, "%i ", a[i].kurs);
	cout << "Время выполнения: = " << time/(double)CLOCKS_PER_SEC << endl;
	fclose(res);
	fclose(def);
	return 0;
}
