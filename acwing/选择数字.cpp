#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 205;
int a[N], b[N];
unordered_map<int, int> vis1;
unordered_map<int, int> vis2;
int main()
{
    int n, m;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> a[i];
        vis1[a[i]] = 1;
    }
    cin >> m;
    for (int i = 0; i < m;i++)
    {
        cin >> b[i];
        vis2[b[i]] = 1;
    }
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            int temp = a[i] + b[j];
            if(!vis1[temp]&&!vis2[temp]){
                cout << a[i] << " " << b[j] << endl;
                return 0;
            }
        }
    }
        return 0;
}