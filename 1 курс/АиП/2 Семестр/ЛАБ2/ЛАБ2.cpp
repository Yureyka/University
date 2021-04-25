#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Input (int **mat, int n, int m)
{
    int i, j;
    cout<<"Input elements:"<<endl;
    for (i=0; i<n; i++)
        for (j=0; j<m; j++)
            cin>>mat[i][j];
}

void Output (int **mat, int n, int m)
{
    int i, j;
    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Nulstlb (int **mat, int n, int m)
{
    int k=0, i, j;
    for (j=0; j<m; j++)
        for (i=0; i<n; i++)
        {
            if(mat[i][j]==0)
            {
                k++;
                break;
            }
        }
    cout<<"Amount of column with zero elements: "<<k<<endl;
}

void Chain (int **mat, int n, int m)
{
 int k=0, num1=0, num2=0, row=0, i, j;
    for (i=0; i<n; i++)
    {
        k++;
        for(j=0; j<m-1; j++)
        {
            if(mat[i][j]==mat[i][j+1])
                num1++;
            else num1=0;
        }
        if(num1>num2)
        {
            num2=num1;
            row=k;
        }
    }
 cout<<"Number of row with longest chain: "<<row<<endl;
}

main()
{
    setlocale(LC_ALL, "Russian");
    int n, m, i, j, sum;
    cout << "Input number of rows: ", cin>>n;
    cout << "Input number of columns: ", cin>>m;
    int **mat=new int *[n];
    for(int i=0; i<n; ++i)
        mat[i]=new int[m];
    Input (mat, n, m);
    cout<<"Matrix:"<<endl;
    Output (mat, n, m);
    Nulstlb (mat, n, m);
    Chain (mat, n, m);


    return 0;
}
