#include<bits/stdc++.h>
using namespace std;
map<char,int> m;
int main()
{
    string s;
    while (cin>>s)
    {
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++;
        }
        char c='a';
        int Min=1e4,Max=-1e4;
        for(int i=0;i<26;i++)
        {
            if(m[c]){
                Min=min(Min,m[c]);
                Max=max(Max,m[c]);
            }
            c=c+1;
        }
        cout<<Max-Min<<endl;
        m.clear();
    }
    
    return 0;
}