#include <conio.h>
#include <stdio.h>
#include <math.h>
main()
{   setlocale(0,"RUS");
	float a, b, x, z, xn, xk, dx;
    printf("������� �������� a: "); scanf("%f",&a);
	printf("������� �������� b: "); scanf("%f",&b);
    printf("������� xn: "); scanf("%f",&xn);
    printf("������� xk: "); scanf("%f",&xk);
    printf("������� ��� dx: "); scanf("%f",&dx);
    printf("������� �������� ������� z=f(x)\n");
    printf("  --------------------------\n");
    printf("  |     x     |  z = f(x)  |\n");
    printf("  |-----------|------------|\n");
    x=xn;
    while (x<=xk)
    { 	printf("  |  %-9.2f|",x);
    	if (x<=a) z = (pow(exp((x-1)/atan(x)), 1.0/3)+pow(tan(x), 2.0)+log(x)+6);
        else if (a<x && x<b) z = pow((asin(x)+sinh(x)), (cos(x)+x*x+exp(1)));
        else if (x>=b) z = pow((abs(pow(x, 1.3/x)-log10(1+x))), 1.3/(x*x));
		printf("  %-10.6f|\n",z);
    	x+=dx;
    }
    printf("  --------------------------\n");
    printf("������� ����� �������...");
	getch();
    return 0;
}
