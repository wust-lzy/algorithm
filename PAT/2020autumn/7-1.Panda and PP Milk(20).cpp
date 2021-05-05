#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n), milk(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    milk[0] = 200;
    for (int i = 1; i < n; i++)
    {
        if (v[i] == v[i - 1])
            milk[i] = milk[i - 1];
        else if (v[i] > v[i - 1])
            milk[i] = milk[i - 1] + 100;
        else //v[i]<v[i-1]
        {
            milk[i] = 200;
            for (int j = i - 1; j >= 0; j--)
            {
                if(v[j]>=v[j+1]&&milk[j]<=milk[j+1])
                milk[j] += 100;
                else
                    break;
            }
        }
    }
    int sum = 0;
    for (int e : milk)
        sum += e;
    cout << sum;
    return 0;
}