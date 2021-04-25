#include <cstdio>
#include <cstring>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <locale.h>

using namespace std;

int main()
{
    string s;
    int n=0;
    ifstream file("123.txt");
    ofstream of("321.txt");
    if (!file)
    {
        puts("Can't open inpfile\n");
        return 1;
    }
    if (!of)
    {
        puts("Can't open outpfile\n");
        return 1;
    }
    while(getline(file, s))
    {
        if(s[0]==' ')
        {
            cout<<s<<endl;
            n++;
        }
    }
    of<<n<<endl;
    cout<<n;
    file.close();
    of.close();
    return 0;
}













