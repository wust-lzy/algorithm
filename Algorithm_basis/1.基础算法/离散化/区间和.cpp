#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int N = 300010;
int a[N], s[N];
vector<int> all;
vector<pair<int, int> > p,q;

int f(int x){
    int l = 0, r = all.size() - 1;
    while(l<r){
        int mid = l + r >> 1;
        if(all[mid]>=x)
            r = mid;
        else
            l = mid + 1;
    }
    return r + 1;
}
int main()
{
    int n, m, l, r;
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        int x, c;
        scanf("%d %d", &x, &c);
        p.push_back({x, c});
        all.push_back(x);
    }
    while(m--){
        scanf("%d %d", &l, &r);
        q.push_back({l, r});
        all.push_back(l);
        all.push_back(r);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(),all.end()),all.end());//所有的下标去重
    for(pair<int,int>it:p){
        int idx = f(it.first);
        a[idx] += it.second;
    }
    for (int i = 1; i <= all.size();i++)//求前缀和
        s[i] = s[i - 1] + a[i];
    
    for(pair<int,int> it:q){
        l = f(it.first), r = f(it.second);
        printf("%d\n", s[r] - s[l-1]);
    }
    return 0;
}