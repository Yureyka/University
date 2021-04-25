#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

#define pi 3.16159265358979323846

using namespace std;

class Sol
{
    public:
        float x, y;
        void Input()
        {
            cout<<"������� �������� x:";
            try
            {
                if((cin>>x)==0) throw 1;
            }
            catch(float)
            {
                cin.clear();
                while(x<=0) continue;
                cout<<"������� x ������� ����!"<<endl;
                cin>>x;
            }
        }
        void Result()
        {
            y=(3.8*sinh(x))/(36*x*x*x);
            cout<<"��������� ����������: ";
            cout<<y<<endl;
        }
};

int main()
{
	setlocale(0, "rus");
    float r, l, S;
    ofstream fout("123.txt");
    cout<<"���������� ����� � ������� ����������:"<<endl;
    cout<<"������� ������: ";
    cin>>r;
    cout<<endl;
    cout<<"������� ����������: "<<(S=pi*r*r)<<endl;
    cout<<"����� ����������: "<<(l=2*pi*r)<<endl;
	fout.fill ('&'); fout.width (12);
    fout<<"S="<<setprecision(5)<<S<<endl;
    fout.fill ('&'); fout.width (12);
    fout<<"l="<<setprecision(5)<<l<<endl;
	cout<<"��������� ������� � ����!"<<endl;
	fout.close();
	cout<<endl<<endl;


	cout<<"������� �������:"<<endl;
	Sol ob;
	ob.Input();
	ob.Result();
    return 0;
}
