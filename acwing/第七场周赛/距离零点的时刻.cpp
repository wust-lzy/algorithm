#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 100010;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int h,m;
        cin>>h>>m;
        cout<<24*60-h*60-m<<endl;
    }
    return 0;
}