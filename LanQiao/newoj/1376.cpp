#include<bits/stdc++.h>
using namespace std;
int main()
{
    int flag=0,i,j;
    for(i=1;!flag;i++)
    {
        j=i;
        if(j%5==1)
        {
            j-=(j/5+1);
            if(j%5==2)
            {
                j-=(j/5+2);
                if(j%5==3)
                {
                    j-=(j/5+3);
                    if(j%5==4)
                    {
                        j-=(j/5+4);
                        if(j%5==0&&j>0)
                        {
                            flag=1;
                            cout<<i;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
