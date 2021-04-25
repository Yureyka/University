#include <conio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

template <class T>

T Sort(T **M, int x, int y)
{
    int t;
    for(int k=0; k<y; k++)
    {
        for(int i=0; i<x; i++)
            for(int j=0; j<y-1; j++)
            {
                if(M[i][j]>M[i][j+1])
                {
                    t=M[i][j];
                    M[i][j]=M[i][j+1];
                    M[i][j+1]=t;
                }
            }
    }
}

int main ()
{
    setlocale(0, "RUS");
    int n, m;

    cout<<"¬ведите количество строк и столбцов массива: "<<endl;
    cin>>n>>m;
    int **Mat1 = new int*;
    for(int i=0; i<n; i++)
        Mat1[i] = new int;

    cout<<"¬ведите значени€ элементов массива: "<<endl;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>Mat1[i][j];
    cout<<endl;
    Sort(Mat1, n, m);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout<<Mat1[i][j]<<" ";
        cout<<endl;
    }

    for(int i=0; i<n; i++)
        delete Mat1[i];
    delete Mat1;
    return 0;
}
