#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen ("C:\\Users\\Zzy\\Desktop\\text.txt","r",stdin);
    string str;
    int ans=0;
    while(getline(cin,str))
    {
        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='A')
            {
                if(str[i+2]=='='&&str[i+4]=='A'&&str[i+6]=='+')
                {
                    ans+=str[i+8]-'0';
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}