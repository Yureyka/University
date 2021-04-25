#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

const int n = 9; // ���������� ������
const int MAX_INT = 1000000;
void solve(int g[n][n], int d[n], int s)
{
    int i, j, // i-� ��������, j - ��� ������ �����������
    v, // ����������� �������
    to, // ����� �� ������� v � to
    len; // ����� len
    bool used[n] = {false}; // ������ ��� ������� ������
    d[s] = 0;
    for (i = 0; i < n; i++)
    {
        v = -1;
        for (j = 0; j < n; j++) // ����� ������� � ����������� d[j]
        if (!used[j] && (v == -1 || d[j] < d[v]))
        v = j;
        used[v] = true; // ������� �������
        for (to = 0; to < n; to++)
        {
            if (g[v][to])
            {
                len = g[v][to];
                if (d[v] + len < d[to])
                {
                    d[to] = d[v] + len;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    cout << d[i] << " ";
}

int main()
{
    setlocale(0, "Russian");
    double start_time, end_time;
    int s = 0;
    int g[n][n] =
    {
        0, 2, 1, 0, 0, 0, 0, 0, 0,

        0, 0, 7, 2, 0, 0, 0, 0, 0,

        0, 0, 0, 0, 2, 3, 0, 6, 0,

        0, 0, 3, 0, 0, 0, 8, 0, 0,

        0, 0, 0, 0, 0, 0, 4, 0, 0,

        0, 0, 0, 0, 3, 0, 0, 0, 0,

        0, 0, 0, 0, 0, 2, 0, 0, 10,

        0, 0, 0, 0, 0, 0, 0, 0, 1,

        0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    int d[n];
    for (int i = 0; i < n; i++)
        d[i] = MAX_INT;
    start_time = clock();
    cout << "���������� ����������:" << endl;
    solve(g, d, s);
    end_time = clock();
    double time = end_time - start_time;
    cout<<"����� ������ ��������� (MS): "<<time/(double)CLOCKS_PER_SEC<< endl;
    return 0;
}
