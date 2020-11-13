#include<bits/stdc++.h>
using namespace std;
int main()
{
    char g[10000];
    int k=0;
    for(int i=1;i<1000;i++)
    {
        if(i<10)
        {
            g[k++]=i+'0';
        }
        else if(i<100)
        {
            g[k++]=i/10+'0';
            g[k++]=i%10+'0';
        }
        else
        {
            g[k++]=i/100+'0';
            g[k++]=i/10%10+'0';
            g[k++]=i%10+'0';
        }
    }
    //cout<<k;
    int n;
    while(cin>>n)
    {
        char c[500][500];
        int i,j,cnt=0;
        for(i=0;i<n-1;i++)//先打印i-1行
        {
            for(j=0;j<n-1-i;j++)
            {
                c[i][j]='.';
            }
            c[i][n-1-i]=g[cnt++];
            if(i>0)
            {
                for(j=n-i;j<2*i-1+n-i;j++)
                    c[i][j]='.';
            }
        }
        for(j=0;j<2*n-1;j++)//打印第n行
            c[i][j]=g[cnt++];
        for(i=n-2;i>0;i--)
        {
            c[i][i+n-1]=g[cnt++];
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<i+n;j++)
            {
                cout<<c[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}

