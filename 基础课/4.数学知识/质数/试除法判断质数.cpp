#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

bool isprime(int x)
{
    if(x<2)
        return 0;
    for (int i = 2; i<=x/i;i++)
    if(x%i==0)
        return 0;
    return 1;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        printf("%s\n", isprime(x) ? "Yes" : "No");
    }
    return 0;
}