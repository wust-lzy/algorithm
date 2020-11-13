#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>a,pair<int,int> b)
{
    return a.second < b.second;
}
int main()
{
    int i,n,t;
    vector<pair<int,int> >v;
    cin>>n;
    for(i=0;i<n;i++)
    {
            cin>>t;
            v.push_back(make_pair(i,t));
    }
    if(n==1||n==2)
        cout<<0;
    else
    {
      sort(v.begin(),v.end(),cmp);
      int ans=abs(v[n-1].first - v[0].first)-1;
      cout<<ans;
    }
    return 0;
}