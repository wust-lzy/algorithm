#include <iostream>
using namespace std;

const int N = 20;
char g[N][N];//记录路径
int n;   
bool col[N], dg[N], udg[N]; //行列、对角线、反对角线
void dfs(int u)
{
    if(u==n){
        for (int i = 0; i < n;i++)//反对角线 y=x+by=x+b, 截距  b=y−x
            puts(g[i]);
        printf("\n");
        return;
    }
    for (int i = 0; i < n;i++){
        if(!col[i]&&!dg[i+u]&&!udg[n-u+i])//对角线 y=−x+by=−x+b, 截距是 b=y+x
        {
            g[u][i] = 'Q';
            col[i] = dg[i + u] = udg[n - u + i] = true;
            dfs(u + 1);
            col[i] = dg[i + u] = udg[n - u + i] = false; //回溯
            g[u][i] = '.';
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n;i++)
        for (int j = 0; j < n;j++)
            g[i][j] = '.';
            // fill(g[0], g[0] + n * n, '.');
    dfs(0);
    return 0;
}