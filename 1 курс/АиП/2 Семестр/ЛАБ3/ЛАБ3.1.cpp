#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <locale>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    char s[100], s1[2];
    int k=0, n=0;
    FILE *f = fopen("123.txt", "rt");
    if (!f)
    {
        printf("Файла с таким именем не существует!\n");
        return 1;
    }
    while (fgets(s, 100, f))
    {
        for(int i=0; i<strlen(s); i++)
        {
            if (k==2)
            {
                puts(s);
                k=0;
                break;
            }
            if (isdigit(s[i])) k++;
        }
    }
    fclose(f);
    return 0;
}

