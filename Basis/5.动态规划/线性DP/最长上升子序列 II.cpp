#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;
/*由最长上升子序列性质可以知道，子序列越长，结尾的数越大
所以枚举每个数，二分找到小于这个数的最大的数
把它接到后面，判断是否能形成更长的序列
*/
const int N = 1e6 + 10;
int a[N], q[N];//q[i]记录长度为i的元素的最小值
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n;i++)
        scanf("%d", &a[i]);
    int len = 0;
    q[0] = -2e9;
    for (int i = 0; i < n; i++) //枚举每个数
    {
        int l = 0, r = len;
        while(l<r){
            int mid = l + r + 1 >> 1;
            if(q[mid]<a[i])
                l = mid;
            else
                r = mid - 1;
        }
        len = max(len, r + 1);
        q[r + 1] = a[i];
    }
    cout << len;
    return 0;
}
