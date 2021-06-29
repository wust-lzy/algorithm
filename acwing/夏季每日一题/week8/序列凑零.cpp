#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 110;
int a[N], b[N];
int main()
{
    int t;
    cin >> t;
    while(t--)//思维构造题  两两一对和为零即可
    {
        int n;
        cin >> n;
        for (int i = 0; i < n;i++)
            cin >> a[i];
        for (int i = 0; i < n;i+=2)
        {
            b[i] = -a[i + 1];
            b[i + 1] = a[i];
        }
        for (int i = 0; i < n;i++)
            cout << b[i] << " ";
        puts("");
    }
    return 0;
}