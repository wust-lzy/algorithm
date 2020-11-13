#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    string n;
    while(cin>>n){
        int sum=0;
        for(int i=0;i<n.length();i++){
            sum+=n[i]-'0';
        }
        while(sum>9){
            int t=0;
            while(sum){
                t+=sum%10;
                sum/=10;
            }
            sum=t;
        }
        cout<<sum<<endl;
    }
    return 0;
}