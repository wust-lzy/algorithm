#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[20];
int main()
{
    a[0] = 1;
    for (int i = 1; i < 20;i++){
        a[i] = a[i - 1] << 1;
        // cout << a[i] << " " << i << endl;
    }
    int n;
    while(cin>>n){
        int sum = n;
        while(sum){
            for (int i = 14; i >= 0;i--){
                if(sum>=a[i]){
                    cout << a[i] << " " << i << endl;
                    sum -= a[i];
                    break;
                }
            }
        }
    }
        return 0;
}