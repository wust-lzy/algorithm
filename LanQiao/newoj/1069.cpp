#include<bits/stdc++.h>
using namespace std;
int w[26];
int main()
{
    string s;
    char ch='A';
    while(getline(cin,s))
    {
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
            w[s[i]-'A']++;
        }
    }
    int m=-1;
    for(int i=0;i<26;i++)
    m=max(m,w[i]);
    //cout<<m<<endl;
    //for(int j=0;j<26;j++)
    //cout<<w[j]<<" ";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<26;j++)
        {
            if((m-i-1)<w[j])
            cout<<'*';
            else
            {
                cout<<' ';
            }
            if(j!=25)
            cout<<' '; 
        }
        cout<<endl;
    }
    for(int j=0;j<26;j++)
    {
        cout<<ch++;
        if(j!=25)
            cout<<' ';
    }
    return 0;
}