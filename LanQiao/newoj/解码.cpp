#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(isalpha(s[i]))
        {
            cout<<s[i];
        }
        else
        {
            int j=s[i]-'0'-1;
            while(j--)
            {
                cout<<s[i-1];
            }
        }
        
    }
    return 0;
}