#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int n,a,b,c;
        cin>>n>>a>>b>>c;
        string s;
        cin>>s;
        int ans=0;
        if(a+c<b)
            b=a+c;
        else if(b+c<a)
            a=b+c;
        for(int i=0;i<n;i++){
            if(s[i]=='0')
                ans+=a;
            else 
                ans+=b;
        }
        cout<<ans<<endl;
    }
    return 0;
}