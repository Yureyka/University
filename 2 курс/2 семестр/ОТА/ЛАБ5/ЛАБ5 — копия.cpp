#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

const int INF = 1000000000; // �������������

const int n = 9; // ���������� ������

bool used[n] = { 0 }; // ������ ��� �������

int top[n] = { 0 }; // �������������� ������

int g[n][n] = {

        0, 2, 1, 0, 0, 0, 0, 0, 0,

        0, 0, 7, 2, 0, 0, 0, 0, 0,

        0, 0, 0, 0, 2, 3, 0, 6, 0,

        0, 0, 3, 0, 0, 0, 8, 0, 0,

        0, 0, 0, 0, 0, 0, 4, 0, 0,

        0, 0, 0, 0, 3, 0, 0, 0, 0,

        0, 0, 0, 0, 0, 2, 0, 0, 10,

        0, 0, 0, 0, 0, 0, 0, 0, 1,

        0, 0, 0, 0, 0, 0, 0, 0, 0,

}; // ������� ���������

int l; // l-� ������� ��� ����������

int s = 0; // ��������� �������

int f; // �������� �������

int d[n] = { 0 }; // ������ �������

int dfs(int v)

{

if (used[v])

return 0;

used[v] = true;

for (int to = 0; to < n; to++)

if (g[v][to])

dfs(to);

top[l++] = v; // ���������� ������� v � ��������������� ������

}

int topSort()

{

l = 0; // ����� ����������� ������� � ��������������� ������

for (int i = 0; i < n; i++)

dfs(i); // ��������� �������� �� ���� ������

reverse(top, top + l); // ���������� ������

return 0;

}

int solve()

{

int i, j;

for (i = 0; i < n; i++)

d[i] = INF;

d[s] = 0;

for (i = 1; i < n; i++)

for (j = 0; j < i; j++)

if (g[top[j]][top[i]])

d[top[i]] = min(d[top[i]], d[top[j]] + g[top[j]][top[i]]);

for (int i = 0; i < n; i++)

cout << d[i] << " ";

return 0;

}

int main()

{
setlocale(0, "Russian");

double start_time, end_time;

start_time = clock();

cout << "���������� ����������:" << endl;

topSort();

solve();

end_time = clock();

double time = end_time - start_time;

cout<<"����� ������ ��������� (MS): "<<time/(double)CLOCKS_PER_SEC<< endl;

}

