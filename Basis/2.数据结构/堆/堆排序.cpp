#include <iostream>
#include<algorithm>
using namespace std;

const int N = 1e5+10;
int heap[N];//小根堆
void downjust(int low,int high)
{
    int i = low, j = i * 2;
    while(j<=high)
    {
        if(j+1<=high&&heap[j+1]<heap[j])//右孩子小于左孩子
            j++;
        if(heap[j]<heap[i])//最小的子结点小于父结点，交换
        {
            swap(heap[j], heap[i]);
            i = j;
            j = i * 2;
        }else
            break;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        scanf("%d", &heap[i]);
    for (int i = n / 2; i >= 1; i--)
        downjust(i,n);
    while(m--){
        printf("%d ", heap[1]);
        heap[1] = heap[n--];//删除堆顶元素
        downjust(1,n);//向下调整
    }
    return 0;
}