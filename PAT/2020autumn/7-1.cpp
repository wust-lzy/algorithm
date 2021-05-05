#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n,minn=500,index=-1;
    cin >> n;
    vector<int> v(n),ans(n);
    for (int i = 0; i < n;i++)
    {
        scanf("%d", &v[i]);
        if(minn>v[i])
        {
            minn = v[i];
            index = i;
        }
    }
    ans[index] = 200;
    for (int i = index-1; i >=0;i--)
    {
        if(v[i]>v[i+1])
            ans[i] = ans[i + 1] + 100;
        else if(v[i]==v[i+1])
            ans[i] = ans[i + 1];
        else
            ans[i] = ans[i + 1] - 100;
    }
    minn = 50000000;
    for (int i = index; i >=0;i--) //处理index前面的牛奶
        minn = min(minn, ans[i]);
    if(minn<200)
    {
        int temp = 200 - minn;
        for (int i = index; i >=0;i--)
            ans[i] += temp;
    }

    for (int i = index+1; i<n;i++) //处理后面的牛奶
    {
        if(v[i]>v[i-1])
            ans[i] = ans[i-1] + 100;
        else if(v[i]==v[i-1])
            ans[i] = ans[i-1];
        else
            ans[i] = ans[i-1] - 100;
    }
    minn = 50000000;
    for (int i = index+1; i<n;i++) 
        minn = min(minn, ans[i]);
    if(minn<200)
    {
        int temp = 200 - minn;
        for (int i = index + 1; i < n;i++)
            ans[i] += temp;
    }

    ll sum = 0;
    for(int e:ans)
        sum += e;
    cout << sum;
    return 0;
}