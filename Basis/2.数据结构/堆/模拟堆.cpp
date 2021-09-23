#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e5+10;
int heap[N], sz=0, ph[N], hp[N];  //ph[k]第k个插入点的坐标  hp[]反过来

void heap_swap(int a,int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(heap[a], heap[b]);
}
void downjust(int low, int high)
{
    int i = low, j = i * 2;
    while(j<=high)
    {
        if(j+1<=high&&heap[j+1]<heap[j])//右孩子小于左孩子
            j++;
        if(heap[j]<heap[i])
        {
            heap_swap(heap[j], heap[i]);
            i = j;
            j = i * 2;
        }
        else
            break;
    }
}

void down(int u)
{
    int t = u;
    if (u * 2 <= sz && heap[u * 2] < heap[t]) t = u * 2;
    if (u * 2 + 1 <= sz && heap[u * 2 + 1] < heap[t]) t = u * 2 + 1;
    if (u != t)
    {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u)
{
    while (u / 2 && heap[u] < heap[u / 2])
    {
        heap_swap(u, u / 2);
        u >>= 1;
    }
}

void upjust(int low,int high)
{
    int i = high, j = i / 2;//i为预调整的结点,j为其父亲
    while(j>=low)
    {
        if(heap[j]>heap[i])
        {
            heap_swap(heap[j],heap[i]);
            i = j;
            j = i / 2;
        }
        else
            break;
    }
}
int main()
{
    int n, m=0;
    cin >> n;
    while (n--)
    {
        char op[5];
        int k, x;
        scanf("%s", op);
        if(!strcmp(op,"I"))
        {
            scanf("%d", &x);
            sz++;
            m++;
            ph[m] = sz;
            hp[sz] = m;
            heap[sz] = x;
            up(sz);
        }
        else if(!strcmp(op,"PM"))
            printf("%d\n", heap[1]);
        else if(!strcmp(op,"DM"))
        {
            heap_swap(1, sz);
            sz--;
            down(1);
        }
        else if(!strcmp(op,"D"))
        {
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, sz);
            sz--;
            up(k);
            down(k);
        }
        else
        {
            scanf("%d%d", &k, &x);
            k = ph[k];
            heap[k] = x;
            up(k);
            down(k);
        }
    }
    return 0;
}