#include<bits/stdc++.h>
using namespace std;
long long p(int a,int n){
    long long ans=1;
    while(n--){
        ans*=a;
    }
    return ans;
}
int main()
{
    string s="LANQIAO";
    long long sum=0;
    for(int i=0;i<s.length();i++)
    {
        long long a=(s[i]-'A'+1)*p(26,s.length()-i-1);
        //cout<<a<<endl;
        sum+=a;
    }
    cout<<sum<<endl;
    //cout<<3725573269;
    return 0;
}