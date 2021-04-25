#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <locale>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    string s, s1, temp;
    int k, n = 0;
    ifstream f ("123.txt", ios::in);
    if (!f)
    {   cout<<"Файла с таким именем не существует!"<<endl;
        return 1;
    }
    while (getline(f, s))
    {
        size_t digits=s.find_first_of("1234567890+-");
    if(digits<=s.size()) cout<<s<<endl;
    }
    f.close();
    return 0;
}

