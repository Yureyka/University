#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>>
using namespace std;
struct date
{
    int day, month, year;
};

using namespace std;

date ret(date n);

int main()
{
    date n;
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
        n.day=1;
        n.month+=1;
    }
    if(n.month>12)
    {
        n.month=1;
        n.year+=1;
    }
    return n;
}














