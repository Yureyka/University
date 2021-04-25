#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void create_array(int N, int vector[])
{
    srand(time(NULL));
    for(int i = 0; i < N; i++)
    {
        vector[i] = rand () % 71;
    }
}

void tasksum(int N, int vector[])
{
    int counter = 0;
    int V = 20;
    int Cnt[N];
    int i = 0;
    counter+=3;
    do
    {
        Cnt[i] = 0;
        i += 1;
    }
    while (i < N);
    counter+=5*N;
    do
    {
        int Sum = 0;
        for(int i = 0; i < N; i++)
        Sum = Sum + vector[i]*Cnt[N-i];
        counter+=1 * 8*N;
        if (Sum == V)
        {
            counter+=2;
            for(int i = 1; i <= N; i++)
                cout << Cnt[i] << " ";
            counter+=1+4*N;
            cout <<endl<< "Число операций: "<<counter<<endl;
            return;
        }
        int j = N;
        while (Cnt[j] == 1)
        {
            Cnt[j] = 0;
            j = j-1;
            counter += 6*N;
        }
        Cnt[j] = 1;
        counter += 6;
    }
    while (Cnt[0] != 1);
    for(int i = 1; i <= N; i++)
    {
        cout << Cnt[i] << " ";
    }
    cout <<endl<< "Число операций: "<<counter<<endl;
}

int main()
{
    setlocale(0, "Russian");
    int N;
    cout << "Чисел в векторе: ";
    cin >> N;
    cout << "Максимальное число в векторе: 70" << endl;
    cout << "V = 20" << endl;
    int vector[N];
    create_array(N, vector);
    cout << "Рандомный вектор" << endl;
    for(int i = 0; i < N; i++)
    {
        cout << vector[i] <<" ";
    }
    cout<<endl;
    tasksum(N, vector);
    system("pause");
    cout << "\n\nВектор, введенный вручную" << endl;
    int vector1[N];
    for(int i=0; i<N ;i++)
    {
        cin >> vector1[i];
    }
    tasksum(N, vector1);
    cout<<endl;
    system("pause");
    return 0;
}
