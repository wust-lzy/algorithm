#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    for(int i=1;i<=100;i++)
    {
        for(int j=40;j>0;j--)
        {
            if(i+20*i+5*j==200)
            cout<<11*i+j;
        }
    }
    return 0;
}