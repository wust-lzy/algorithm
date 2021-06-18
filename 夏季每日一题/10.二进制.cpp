#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while(t--){
        vector<int> t1, t2;
        string s;
        cin >> s;
        for (int i = 31; i >= 0;i--){
            t1.push_back(s[i] - '0');
            t2.push_back(s[i] - '0');
        }
        t1[0] += 1, t2[0] += 1, t2[1] += 1;
        for (int i = 0; i <31;i++){
            if(t1[i]==2){
                t1[i] = 0;
                t1[i + 1]++;
            }
            if(t2[i]>=2){
                t2[i] -= 2;
                t2[i + 1]++;
            }
        }
        if(t1[31]==2){
            t1[31] = 0;
            t1.push_back(1);
        }
        if(t2[31]>=2){
            t2[31] -= 2;
            t2.push_back(1);
        }

        for (int i = t1.size()-1; i >= 0;i--)
            cout << t1[i];
        cout << endl;
        for (int i = t2.size()-1; i >= 0;i--)
            cout << t2[i];
        cout << endl;
    }
    return 0;
}