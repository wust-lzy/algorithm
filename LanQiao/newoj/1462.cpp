#include<bits/stdc++.h>
using namespace std;
int data[20][5];
int main()
{
    int i,j,ans=0,a,b,c,d,e;
    for(i=0;i<20;i++)
        for(j=0;j<5;j++)
        cin>>data[i][j];
        for(a=0;a<20;a++)
            for(b=0;b<20;b++)
            for(c=0;c<20;c++)
            for(d=0;d<20;d++)
            for(e=0;e<20;e++)
        {
            if(a==b||a==c||a==d||a==e)
                continue;
            else if(b==c||b==d||b==e)
                continue;
            else if(c==d||c==e)
                continue;
            else if(d==e)
                continue;
            int sum=data[a][0]+data[b][1]+data[c][2]+data[d][3]+data[e][4];
            if(sum>ans)
                ans=sum;
        }
        cout<<ans;
    return 0;
}
