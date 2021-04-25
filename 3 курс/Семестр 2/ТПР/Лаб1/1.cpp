#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	setlocale (LC_ALL, "Russian");
	int n;
	ifstream fin("in.txt");
	fin >> n;
	int matr[n][n];
	int MaxR[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			fin >> matr[i][j];
	int count = 0;
	int sum;
	int floor = 1;
	int t_c = 0;
	while (count < n)
	{
		t_c = count;
		cout << endl << "Tier " << floor++ << ": ";
		for (int j = 0; j < n; j++)
		{
			sum = 0;
			for (int i = 0; i < n; i++)
				sum += matr[i][j];
			if (sum == 0)
			{
				cout << "x" << j + 1 << " ";
				MaxR[count] = j;
				count++;
			}
		}
		if (t_c == count)
		{
			cout << "Ќевозможно определить вершину-источник" << endl;
			break;
		}
		for (int q = count - 1; q >= 0; q--)
			for (int j = 0; j < n; j++)
				matr[MaxR[q]][j] = 0;
		for (int q = count - 1; q >= 0; q--)
			for (int i = 0; i < n; i++)
				matr[i][MaxR[q]] = 1;
		for (int i = 0; i < n; i++)
		{
			cout << endl;
			for (int j = 0; j < n; j++)
				cout << matr[i][j] << " ";
		}
	}
	cout << endl;
	return 0;
}
