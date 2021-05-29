#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, k, a[N];
bool flag = 0;
vector<int> ans,temp, e[105]; //每张纸片
int vis[105];
bool isok(int p,int k)  //第p张纸片是否符合,k表示起点
{
    for (int i = 0; i < e[p].size(); i++)
        if(a[k+i]!=e[p][i])
            return 0;
    return 1;
}
void dfs(int p,int len) //匹配小纸条数，当前的起点
{
    if(p==m)  //纸片用完，即为答案
    {
        ans = temp;
        flag = 1;
        return;
    }
    if(flag)
        return;
    for (int i = 1; i <= m;i++){
        if(!vis[i]&&isok(i,len))
        {
            vis[i] = 1;
            temp.push_back(i);
            dfs(p+1, len + e[i].size()-1);
            vis[i] = 0;//回溯
            temp.pop_back();
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n;i++)
        scanf("%d", &a[i]);
    cin >> m;
    for (int i = 1; i <= m;i++)//纸片下标从1开始
    {
        scanf("%d", &k);
        e[i].resize(k);
        for (int j = 0; j < k;j++)
            scanf("%d", &e[i][j]);
    }
    dfs(0, 1);
    printf("%d", ans[0]);
    for (int i = 1;i<ans.size();i++)
        printf(" %d", ans[i]);
    return 0;
}
/*
17
95 70 80 97 97 68 58 58 80 72 88 81 81 68 68 60 80
6
4 68 58 58 80
3 81 68 68
3 95 70 80
3 68 60 80
5 80 72 88 81 81
4 80 97 97 68

cout << isok(3, 1) << endl;//3
cout << isok(6, 3) << endl;//6
cout << isok(1, 6) << endl;//9
cout << isok(5, 9) << endl;//13
cout << isok(2, 13) << endl;//15
cout << isok(4, 15) << endl;//17
*/
