#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
struct date
{
    int day, month, year;
};
date n;
using namespace std;

date ret(date n);

int main()
{
    cin>>n.day>>n.month>>n.year;
    n=ret(n);
    cout<<n.day<<"."<<n.month<<"."<<n.year;

    return 0;
}

date ret(date n)
{
    n.day++;
    if(n.day>31)
    {
        n.day=0;
        n.month+=1;
    }
    if(n.month>12)
    {
        n.month=0;
        n.year+=1;
    }
    return n;
}














