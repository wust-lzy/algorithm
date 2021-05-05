#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f,g,vis[7],ans=0;
int check()
{
    int cnt=0;
    for(int i=0;i<7;i++)
    cnt+=vis[i];
    if(!cnt) return 0;
    else if(cnt==1||cnt==7)  return 1;
    else //有2~6根管子，判断他们的邻居是不是都没亮
    {
        if(a)
        {
            if(!b&&!f) return 0;
        }
        if(b)
        {
            if(!a&&!g&&!c) return 0;
        }
        if(c)
        {
            if(!b&&!g&&!d) return 0;
        }
        if(d)
        {
            if(!e&&!c)  return 0;
        }
        if(e)
        {
            if(!g&&!d&&!f) return 0;
        }
        if(f)
        {
            if(!a&&!g&&!e)  return 0;
        }
        if(g)
        {
            if(!b&&!c&&!e&&!f) return 0;
        }
        return 1;
    }  
}
int main()
{//七重循环
    for(a=0;a<2;a++)
    for(b=0;b<2;b++)
    for(c=0;c<2;c++)
    for(d=0;d<2;d++)
    for(e=0;e<2;e++)
    for(f=0;f<2;f++)
    for(g=0;g<2;g++){
        vis[0]=a;vis[1]=b;vis[2]=c;vis[3]=d;
        vis[4]=e;vis[5]=f;vis[6]=g;
        ans+=check();
    }
    cout<<ans-3;
    return 0;
}