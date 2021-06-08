#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        bool flag = false;
        for (int x = 0;x<=340&&!flag;x++){
            for (int y = 0;y<=200&&!flag;y++){
                for (int z = 0;z<=170&&!flag;z++){
                    if(3*x+5*y+7*z==n){
                        flag = true;
                        cout << x << " " << y << " " << z << endl;
                    }
                }
            }
        }
        if(!flag)
            cout << -1 << endl;
    }
    return 0;
}