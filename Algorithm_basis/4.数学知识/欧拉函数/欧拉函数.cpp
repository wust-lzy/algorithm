#include <bits/stdc++.h>
using namespace std;

int n;
int main()
{
    int x;
    cin >> n;
    while(n--)
    {
        cin >> x;
        int ans = x;
        for (int i = 2; i <= x / i;i++){
            if(x%i==0){
                ans = ans / i * (i - 1);
                while(x%i==0)
                    x /= i;
            }
        }
        if(x>1)
            ans = ans / x * (x - 1);
        cout << ans << endl;
    }
    return 0;
}