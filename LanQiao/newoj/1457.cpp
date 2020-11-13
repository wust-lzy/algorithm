#include<bits/stdc++.h>
using namespace std;
int a[100005];
int level(int n)
{
    int i=1,cnt=0;
    while(i-1<n)
    {
        cnt++;
        i*=2;
    }
    return cnt;
}
bool cmp(pair<int,long long>a,pair<int,long long>b)
{
    if(a.second!=b.second)
        return a.second>b.second;
    else
        return a.first<b.first;
}
int main()
{
    int n,cnt=0,k,i;
    vector<pair<int,long long>>v;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    k=level(n);
    for(i=0;i<k;i++)
    {
        long long sum=0;
        int j=(i==k-1)?(n-pow(2,k-1)+1):pow(2,i);
        for(int x=0;x<j;x++)
            sum+=a[cnt++];
        v.push_back(make_pair(i+1,sum));
    }
         sort(v.begin(),v.end(),cmp);
         cout<<v[0].first;
    return 0;
}
