#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int q;
    cin >> q;
    unordered_map<int, int> vis;
    int l = 0, r = 0;
    while(q--){
        char c;
        int tmp;
        cin >> c >> tmp;
        if(c=='L'){
            vis[tmp] = l--;
        }
        else if(c=='R'){
            vis[tmp] = ++r;
        }
        else if(c=='?'){
            int x = vis[tmp] - (l+1), y = r  - vis[tmp];
            cout << min(x, y) << endl;
        }
    }
    return 0;
}