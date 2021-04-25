#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Vvod (int ** matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cout << "������� ������� ������� ["<<i+1<<"]["<<j+1<<"]:";
            cin >> matrix[i][j];
        }
}

void Vivod (int ** matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void Summa (int ** matrix, int n, int m)
{
    int sum, i, j;
    for (j = 0; j < m; j++)
    {
        sum = 0;
        for (i = 0; i < n; i++)
        {
            if(matrix[i][j] < 0) break;
            sum += matrix[i][j];
        }
        if(i == n)
        {
            cout << "����� " << j << " = " << sum << "\n";
        }
    }
}






void Bolee1 (int ** matrix, int n, int m)
{
 int t, t1 = 0, r = 0, t2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            t2 = matrix[i][j];
            matrix[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                for (int f = 0; f < m; f++)
                {
                    if (t2 == matrix[k][f])
                    {
                        t = matrix[k][f];
                    }
                    else r++;
                }
                if (t1 > t) t = t1;
            }
            t1 = t;
            matrix[i][j] = t2;
        }
    }
    int kof;
    kof = n*n*n*n;
    if (r == kof) cout << "���������� ��������� ���!";
    else cout << "������������ �� ������������� ����� 1 ����: " << t;
}

main()
{
	 Setlocale (0,"RUS");
    int n, m, i, j, sum;
    cout << "������� ���-�� �����: ", cin >> n;
    cout << "������� ���-�� ��������: ", cin >> m;
    int ** matrix = new int * [n];
    for(int i = 0; i < n; ++i)	matrix[i] = new int[m];
    Vvod (matrix,n,m);
    cout << "��������� �������: \n";
    Vivod (matrix,n,m);
    cout << "����� �������� ��� ������������� ���������: \n";
	  Summa (matrix,n,m);
    Bolee1 (matrix, n, m);
    for(int i = 0; i<n; ++i)
       Delete [] matrix [i];
    Delete [] matrix;
	  return 0;
}
