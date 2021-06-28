#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v[m + 1];
    int vis[n + 1];
    for (int i = 1; i <= n;i++){
        scanf("%d", &vis[i]);
        v[vis[i]].push_back(i);
    }
    for (int i = 1; i <= n;i++){
        int idx = vis[i];
        int cnt = v[idx].size() - 1;
        if(cnt==0)
            printf("BeiJu\n");
        else{
            printf("%d\n", cnt);
        }
    }
        return 0;
}