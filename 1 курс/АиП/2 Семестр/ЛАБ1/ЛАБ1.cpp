#include <stdio>
#include <cmath>
main()
{
float a, b, x, xn, xk, dx, z;
printf("Введите параметр a: "), scanf("%f",&a);
printf("Введите параметр b: "), scanf("%f",&b);
printf("Введите xn: "), scanf("%f",&xn);
printf("Введите xk: "), scanf("%f",&xk);
printf("Введите шаг dx: "), scanf("%f",&dx);

printf("  ┌───────────┬────────────┐\n");
printf("  │     x     │    z=f(x)  │\n");
printf("  ├───────────┼────────────┤\n");

x=xn;
while (x<xk)
{
    printf("  │  %-9.3f│",x);
    if (x<=a) z = pow(exp((x-1)/(atan(x)), 1.0 / 3)+pow(tan(x), 2)+log(x)+6;
    else if (a<x && x<b) z = pow(asin(x)+sinh(x), cos(x)+x*x+exp);
        else if (x>=b) z = pow(abs(pow(x, 1.3/x)-log10(1+x)), 1.3/(x*x));
    printf("  %-10d│\n",(int)z);
    printf("  %-10.3f│\n",z);
    x+=dx;
}
printf("  └───────────┴────────────┘\n");
printf("Нажмите любую клавишу...");
getch();

return 0;


}
