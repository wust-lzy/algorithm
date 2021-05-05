#include<bits/stdc++.h>
using namespace std;
int n, m, smax;
int main()
{
    cin >> n >> m >> smax;
    queue<char> q[n+1];
    stack<char> ss;
    string ans = "";
    for (int i = 1; i <= n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            char c;
            // scanf("%c", &c);
            cin >> c;
            q[i].push(c);
        }
    }
    int cz;
    while(cin>>cz)
    {
        if(cz==-1)
            break;
        if(cz)
        {
            if(!q[cz].empty())
            {
                char c = q[cz].front();
                q[cz].pop();
                if(ss.size()<smax)
                    ss.push(c);
                else
                {
                    ans += ss.top();
                    ss.pop();
                    ss.push(c);
                }
            }
        }
        else
        {
            if(!ss.empty())
            {
                ans += ss.top();
                ss.pop();
            }
        }
    }
    cout << ans;
    return 0;
}