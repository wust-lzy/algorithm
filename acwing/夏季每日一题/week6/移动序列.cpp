#include <iostream>
using namespace std;
const int N = 100;
int t;
int a[N];
int main()
{
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n;i++)
            cin >> a[i];
        int i = 0, j = n - 1;//统计所有相邻1中间0的个数
        while(a[i]==0)
            i++;
        while(a[j]==0)
            j--;
        int cnt = 0;
        while(i<j){
            if(a[i]==0)
                cnt++;
            i++;
        }
        cout << cnt << endl;
    }
    return 0;
}