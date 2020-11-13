#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005],b[100005],heap[100005],from[100005],step[100005],n,sum=1;
void swap(ll x,ll y)//手打swap交换，同时交换来源数组。
{
    ll k = heap[x];
    heap[x] = heap[y];
    heap[y] = k;
    k = from[x];
    from[x] = from[y];
    from[y] = k;
}
int main()
{
    scanf("%d",&n);
    for (ll i = 1;i <= n;i++) scanf("%d",&a[i]);
    for (ll i = 1;i <= n;i++) scanf("%d",&b[i]);
    for (ll i = 1;i <= n;i++) heap[i] = a[i]+b[1],from[i] = i,step[i] = 1; 
    //这一步就是优化。把c去掉了，取而代之的是现做现卖的合成。
    while (sum <= n)
    {
        printf("%d ",heap[1]);
        ll t = from[1];
        step[t]++;
        heap[1]=a[t] + b[ step[t] ];//现做现卖的合成。
        ll x = 1,s;
        while (x<<1 <= n)//经典的下传
        {
            s = x<<1;
            if (heap[s] > heap[s + 1] && s + 1 <= n) s++;
            if (heap[x] > heap[s])
            {
                swap(x,s);
                x = s;  
            }else break;
        }
        sum++;  
    }
    return 0;
}