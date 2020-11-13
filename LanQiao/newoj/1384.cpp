#include<bits/stdc++.h>
using namespace std;
char mp[150][150]={'0'};
int ans=0;
int go[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
void f(int x,int y)
{
    for(int i=0;i<8;i++)
    {
        string s="L";
        int dx=x,dy=y;
        for(int j=0;j<6;j++)
        {
            dx+=go[i][0];
            dy+=go[i][1];
            s+=mp[dx][dy];
        }
        if(s=="LANQIAO")  ans++;
    }
}
int main()
{
    int i,j;
    freopen("1384-in.txt","r",stdin);
    for(i=20;i<120;i++){
        for(j=20;j<120;j++){
            cin>>mp[i][j];
        }
    }
    /*for(i=10;i<110;i++){
        for(j=10;j<110;j++){
            cout<<mp[i][j];
        }
        cout<<endl;
    }*/
    for(i=20;i<120;i++){
        for(j=20;j<120;j++){
            if(mp[i][j]=='L')
            {
                f(i,j);
            }
        }
    }
    cout<<ans;
    return 0;
}
