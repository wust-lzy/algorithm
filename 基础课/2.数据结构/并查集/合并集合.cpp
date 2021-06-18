#include <iostream>
using namespace std;

const int N = 1e5 + 5;
int father[N];
//路径压缩
int findfather(int x){
    if(x==father[x])
        return x;
    int f = findfather(father[x]);
    father[x] = f;
    return f;
}

void Union(int a,int b){
    int fa = findfather(a);
    int fb = findfather(b);
    if(fa!=fb){
        father[fa] = fb;
    }
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n;i++)
        father[i] = i;
    while (m--){
        char c;
        int a, b;
        cin >> c >> a >> b;
        if(c=='M')
            Union(a, b);
        else
            printf("%s\n", findfather(a) == findfather(b) ? "Yes" : "No");
    }
    return 0;
}