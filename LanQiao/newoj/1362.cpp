#include<bits/stdc++.h>
using namespace std;
const int num[3]={3,5,7};
typedef long long ll;
int main()
{
    priority_queue<ll,vector<ll>,greater<ll>>q;
    set<ll> s;
    q.push(1);
    s.insert(1);
    for(int i=1;;i++)
    {
        ll x=q.top();
        q.pop();
        if(x!=59084709587505)//59084709587505
        {
            for(int j=0;j<3;j++)
            {
                ll t=x*num[j];
                if(!s.count(t))
                {
                    s.insert(t);
                    q.push(t);
                }
            }
        }
        else
        {
            cout<<i-1;
            break;
        }
    }
    return 0;
}

