#include <iostream>
#include<algorithm>
using namespace std;

const int N = 100;
int a[N], b[N];
int t, n, x;
int main()
{
    cin >> t;
    while(t--){
        cin >> n >> x;
        bool flag = true;
        for (int i = 0; i < n;i++){
            cin >> a[i];
            if(a[i]>x)
                flag = false;
        }   
        for (int i = 0; i < n;i++)
        {
            cin >> b[i];
            if(b[i]>x)
                flag = false;
        }
        if(!flag)
        {
            cout << "No\n";
            continue;
        }
        for (int i = 0, j = n - 1; i < n;i++,j--){
            if(a[i]+b[j]>x)
                flag = false;
        }
        if(flag){
            cout << "Yes\n";
            continue;
        }
        flag = true;
        for (int i = 0, j = n - 1; i < n;i++,j--){
            if(b[i]+a[j]>x)
                flag = false;
        }
        if(flag){
            cout << "Yes\n";
            continue;
        }else
            cout << "No\n";
    }
    return 0;
}