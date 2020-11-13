#include<bits/stdc++.h>
using namespace std;
string toBinarystr(int x)
{
    string s="--------";
    if(x >= 0)
    {
        for(int i=0; i<7; i++)
        {
            if(((x>>i)&1))
            s[8 - i-1]='1';
        }
    }
    else
    {
        s[0]='1';
        for(int i=0; i<7; i++)
        {
            if(((x+128)>>i)&1)
            {
                s[8-i-1]='1';
            }
        }
    }
    return  s;
}
int main()
{
    //freopen("C:\\Users\\晏书浓\\Desktop/2.in","r",stdin);
    for(int i=0; i<10; i++)
        for(int j=0; j<16;j++)
    {
        int x,y;
        cin >>x >> y;
        string s1=toBinarystr(x);
        string s2=toBinarystr(y);
        cout << s1+s2 << endl;
    }
    return 0;
}
