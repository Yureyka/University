#include <iostream>
#include <string>
#include <stdio.h>
#include <windows.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	string s;
	string p[30];
	int count = 0;


	cout << "������� ������: " << endl;
	getline(cin, s);

	cout << "�������� ������: " << endl;
	cout << s;

	for (count = 0; (s[count] = getchar() != ' ') ; count++)
    {
        p[count] = s[0];
        if ( s[count] == '\n' && s[count + 1] != '\n' )
        {
            p[count] += s[count];
            cout << p[count];
        }
    }

	cout << "���������: " << endl;
	cout<<s;

	return 0;
}
