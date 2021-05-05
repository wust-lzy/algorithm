#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f(int n)
{
    int cnt = 0;
    for (int i = 1; i <= sqrt(n);i++)
    {
        if(n%i==0)
        {
            if(i==sqrt(n)&&n/i==i)
                cnt++;
            else
            {
                cnt += 2;
            }  
        } 
    }
    return cnt;
}
int main()
{
    for (int i = 1;;i++)
    {
        if(f(i)==100)
        {
            cout << i;
            break;
        }
        //cout << f(i) << " ";
    }
    return 0;
}