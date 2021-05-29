#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int find_num(int *a,int n,int val)
{
    int sum = 0;
    for (int i = 0; i < n;i++)
    {
        if(a[i]==val)
            sum++;
    }
    return sum;
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int a[n];
        int  ans1 = 0, ans2 = 0;
        for (int i = 0; i < n; i++)
            scanf("%d", a+i);
        sort(a, a + n);
        ans2 = find_num(a, n, a[0]) * find_num(a, n, a[n - 1]);
        int minn = a[1] - a[0];
        for (int i = 2; i < n;i++){
            minn = min(minn, a[i] - a[i - 1]);
        }
        if(minn==0){
            for (int i = 1; i < n;i++){
                int j = i - 1;
                while(j>=0&&a[j]==a[i])
                {
                    ans1++;
                    j--;
                }
            }
        }
        else
        {
            for (int i = 1; i < n;i++){
                if(a[i]-a[i-1]==minn)
                    ans1++;
            }
        }
        printf("%d %d\n", ans1, ans2);
    }
     return 0;
}
