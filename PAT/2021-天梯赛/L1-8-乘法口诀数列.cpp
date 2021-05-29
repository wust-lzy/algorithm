#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
    int n;
    cin >> a[1] >> a[2] >> n;
    int cnt = 2,index=1;
    while(1)
    {
        string temp = to_string((a[index] * a[index+1]));
        index++;
        for (int i = 0; i < temp.length();i++)
            a[++cnt] = temp[i] - '0';
        if(cnt>=n)
        {
            for (int i = 1; i <= n;i++)
            {
                printf("%d", a[i]);
                if(i!=n)
                    printf(" ");
            }
            break;
        }
    }
    return 0;
}