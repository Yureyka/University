#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

int main()
{
	setlocale(0, "Russian");

	string s;
	int i = 0;

	cout << "������� ������: " << endl;
	getline(cin, s);

	s+=" .";

	cout << "�������� ������: " << endl;
	cout<<s<<endl;

    while (s[i] != '.')
    {
        if(s[i] != ' ')
        {
            while(s[i+1] != ' ')
            {
                s[i+1] = ' ';
                i++;
            }
        }
        i++;
    }

	cout << "���������: " << endl;
	cout<<s;

	return 0;
}
