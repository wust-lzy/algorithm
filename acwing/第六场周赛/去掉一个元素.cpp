#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e5+5;
int a[N];
int main()
{
    int n, cnt = 0, sum = 0;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> a[i];
        if(a[i]&1)
            cnt++;
        sum += a[i];
    }
    if(sum&1)
        cout << cnt;
    else
        cout << n - cnt;
    return 0;
}