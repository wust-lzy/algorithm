#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100010;
//奇数台阶异或值不为0必胜
int main()
{
    int n, ans = 0, x;
    cin >> n;
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &x);
        if(i&1)
            ans ^= x;
    }
    printf("%s\n", ans ? "Yes" : "No");
    return 0;
}