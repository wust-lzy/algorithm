#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int N = 110;
int a[4][N];
int main()
{
    int t;
    cin >> t;
    while(t--)//简单模拟
    {
        int n;
        cin >> n;
        for (int i = 0; i < n;i++)
            cin >> a[0][i];
        for (int i = 0; i < n;i++)
            cin >> a[1][i];
        for (int i = 0; i < n;i++)
            cin >> a[2][i];
        a[3][0] = a[0][0];
        for (int i = 1; i < n;i++)
        {
            if(i!=n-1)
            {
                for (int j = 0; j < 3;j++){
                    if(a[j][i]!=a[3][i-1])
                    {
                        a[3][i] = a[j][i];
                        break;
                    }
                }
            }
            else{
                for (int j = 0; j < 3;j++){
                    if(a[j][i]!=a[3][i-1]&&a[j][i]!=a[3][0])
                    {
                        a[3][i] = a[j][i];
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
            cout << a[3][i] << " ";
        cout << endl;
    }
    return 0;
}