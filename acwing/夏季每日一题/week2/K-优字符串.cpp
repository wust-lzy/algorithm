#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t;i++)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int cnt = 0;
        for (int j = 0; j < s.length()/2;j++){
            if(s[j]!=s[n-j-1])
                cnt++;
        }
        printf("Case #%d: %d\n", i, abs(cnt - k));
    }
        return 0;
}