#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int t,h1,m1,s1,h2,m2,s2;
    char ch;
    cin>>t;
    while(t--)
    {
        int sum=0;
        for(int i=0;i<2;i++)
        {
            scanf("%d:%d:%d %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
            while((ch=getchar())!='\n')
            {
                if(ch=='+')
                {
                    int x=(getchar()-'0');
                    //cout<<x<<endl;
                    sum+=24*x*3600;
                }
            }
            sum+=(h2-h1)*3600+(m2-m1)*60+s2-s1;

        }
        sum/=2;
        printf("%02d:%02d:%02d\n",sum/3600,sum%3600/60,sum%60);
    }
    return 0;
}
