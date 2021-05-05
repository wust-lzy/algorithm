#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
int f(string s)
{
    if(!m[s])//如果子串没有出现过
    {
        set<char>ss;
        for(int i=0;i<s.length();i++)
        ss.insert(s[i]);
        m[s]=ss.size();
    }
    return m[s];
    
}
int main()
{
    int i,j,ans=0;
    string s;
    cin>>s;
    for(i=0;i<s.length();i++)
    for(j=1;j<=s.length()-i;j++)
    {
        ans+=f(s.substr(i,j));
    }
    cout<<ans;
    return 0;
}