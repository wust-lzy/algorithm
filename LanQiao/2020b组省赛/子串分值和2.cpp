#include<bits/stdc++.h>
using namespace std;
int w[27];
int main()
{
    int i,j,ans=0,cnt=0;
    string s;
    cin>>s;
    for(i=0;i<s.length();i++)
    {
        for(j=i;j<s.length();j++)
        {
            int letter=s[j]-'a';
            if(!w[letter]) //判断当前子串这个字母出现没有出现过
            {
                cnt++;
                w[letter]=1;
            }
            ans+=cnt;
        }
        cnt=0;
        memset(w,0,sizeof(w));
    }
    cout<<ans;
    return 0;
}