#include<bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;
int n, m;
int father[3*N];

int findfather(int x)
{
    if(father[x]==x)
        return x;
    int f = findfather(father[x]);
    father[x] = f;
    return f;
}
void Union(int a,int b)
{
    int fa = findfather(a);
    int fb = findfather(b);
    if(fa!=fb)
        father[fa] = fb;
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= 3*n;i++)
        father[i] = i;
    int cnt = 0;
    while(m--)
    {
        int k, x, y;
        scanf("%d%d%d", &k, &x, &y);
        if(x>n||y>n)
        {
            cnt++;
            continue;
        }
        if(k==1){
            if(findfather(x)==findfather(y+n)||findfather(x)==findfather(y+2*n))
                cnt++;
            else{
                Union(x, y);
                Union(x + n, y + n);
                Union(x + 2 * n, y + 2 * n);
            }
        }
        else{
            if(x==y||findfather(x)==findfather(y)||findfather(x)==findfather(y+n))
                cnt ++;
            else{
                Union(x, y + 2 * n);
                Union(x + n, y);
                Union(x + 2 * n, y + n);
            }
        }
    }
    cout << cnt;

    return 0;
}