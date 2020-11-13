#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    double a=sqrt((6.4-2.3)*(6.4-2.3)+(3.1-2.5)*(3.1-2.5));
    double b=sqrt((6.4-5.1)*(6.4-5.1)+(3.1-7.2)*(3.1-7.2));
    double c=sqrt((2.3-5.1)*(2.3-5.1)+(2.5-7.2)*(2.5-7.2));
    double p=(a+b+c)/2;
    double s=sqrt(p*(p-a)*(p-b)*(p-c));
    double s2=0.01;
    printf("%.03lf\n",s);
    printf("%.03lf\n",s2);
    return 0;
}