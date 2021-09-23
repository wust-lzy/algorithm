#include <iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int N = 1e4 + 10;
int a[N];
int n;
int main()
{
    scanf("%d", &n);
    int ans = 0;
    priority_queue<int,vector<int>,greater<int>> q;
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &a[i]);
        q.push(a[i]);
    }
    while(q.size()>1)//每次选两个小的 合成一堆
    {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        ans += a + b;
        q.push(a + b);
    }
    cout << ans;
    return 0;
}