#include <iostream>
using namespace std;

const int N = 10;
int n;
int path[N];    //记录路径
bool vis[N];    //是否已选
void dfs(int u)
{
    if(u==n){
        for (int i = 0; i < n;i++)
            printf("%d ", path[i]);
        printf("\n");
    }
    for (int i = 1; i <= n;i++){
        if(!vis[i])
        {
            path[u] = i;
            vis[i] = true;
            dfs(u + 1);
            vis[i] = false; //回溯
        }
    }
}
int main()
{
    cin >> n;
    dfs(0);
    return 0;
}