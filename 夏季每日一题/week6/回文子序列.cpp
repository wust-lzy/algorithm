#include <iostream>
#include<string.h>
using namespace std;

const int N = 5005;
int vis[N];
int main()
{
    int t, n, x;
    cin >> t;
    while(t--){
        bool flag = false;
        cin >> n;
        memset(vis, -1, sizeof(vis));//初始化哈希表
        for (int i = 0; i < n;i++)
        {
            cin >> x;
            if(vis[x]==-1)//记录第一次x出现的位置
                vis[x] = i;
            if(i-vis[x]>=2)//回文元素长度>=3
                flag = true;
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}