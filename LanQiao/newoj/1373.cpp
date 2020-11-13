#include<bits/stdc++.h>
using namespace std;
pair<int,int>v[100005];//记录ts，和id
bool id[100005];
int cnt[100005]={0};
int main()
{
    int n,d,k,i,j;
    cin>>n>>d>>k;
    for(i=0;i<n;i++)
        cin>>v[i].first>>v[i].second;
    sort(v,v+n);//按照时间来排序
    for(i=0,j=0;i<n;i++)//i代表前面的时间，j代表后面的时间
    {
        cnt[v[i].second]++;//v[i]时刻对应的id的赞++
        while(v[i].first-v[j].first>=d)
        {
            cnt[v[j].second]--;
            j++;//后指针前移
        }
        if(cnt[v[i].second]>=k)
        {
            id[v[i].second]=1;
        }
    }
    for(i=0;i<=100000;i++)
    {
        if(id[i])
            cout<<i<<endl;
    }
    return 0;
}

