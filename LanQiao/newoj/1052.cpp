#include<bits/stdc++.h>
using namespace std;
vector<int>prime;
const int m=120000;
int main()
{
    bool vis[m];
    for(int i=2;i<m;i++)
    {
        if(!vis[i])
        prime.push_back(i);
        for(int j=2*i;j<m;j+=i)
        vis[j]=1;
    }
    //cout<<prime.size();
    int k;
    cin>>k;
    cout<<prime[k-1];
    return 0;
}