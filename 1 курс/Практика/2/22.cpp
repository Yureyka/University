#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

const int n=2, m=5;
int m1[n] = {1,1};
int m2[n] = {1,1};
int m3[m], length;
char s1[n], s2[n];

int main()
{

for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
        m3[i+j]+=m1[i]*m2[j];

for (int i=0; i<m; i++)
{
    m3[i+1]+=m3[i]/10;
    m3[i]%=10;
}


for(int i = m; i>=0; i--)
    cout<<"  "<<m3[i];

length = m;

    return 0;
}









