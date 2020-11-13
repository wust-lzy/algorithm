#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j,data[105][105];
    cin>>n>>m;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        cin>>data[i][j];
    for(i=0;i<m;i++)
        {
            for(j=n-1;j>=0;j--)
    {
        cout<<data[j][i];
        if(j) cout<<" ";
    }
    cout<<endl;
        }
    return 0;
}



