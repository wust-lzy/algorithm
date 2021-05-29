#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    string s;
    while(cin>>s)
    {
        string temp = s;
        reverse(temp.begin(), temp.end());
        int len = s.length();
        int dp[len + 1][len + 1];
        for (int i = 0; i < len;i++)
        {
            dp[i][0] = dp[0][i] = 0;
        }
        for (int i = 1; i <= len;i++){
            for (int j = 1; j <= len;j++)
            {
                if(s[i-1]==temp[j-1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        cout << len - dp[len][len] << endl;
    }
    return 0;
}