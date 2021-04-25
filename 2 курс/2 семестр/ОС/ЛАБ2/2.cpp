#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

int main()
{
	setlocale(0, "Russian");

	string s;
	int i = 0;

	cout << "Введите строку: " << endl;
	getline(cin, s);

	s+=" .";

	cout << "Исходная строка: " << endl;
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

	cout << "Результат: " << endl;
	cout<<s;

	return 0;
}
