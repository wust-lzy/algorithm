#include<bits/stdc++.h>
using namespace std;
const int maxn=25000;
vector<int>prime;
bool vis[maxn];
/*int main()
{
    vis[0]=vis[1]=true;
    for(int i=2;i<maxn;i++)
    {
        if(!vis[i])
        {
            prime.push_back(i);
            for(int j=i+i;j<maxn;j+=i)
                vis[j]=true;
        }
    }
    cout<<prime[2018];
    return 0;
}*/
int main()
{
    vis[0]=vis[1]=1;
    for(int i=2;i<maxn;i++){
        if(!vis[i]){
            prime.push_back(i);
            for(int j=2*i;j<maxn;j+=i)
            vis[j]=1;
        }
    }
    cout<<prime[2018];
    return 0;
}


