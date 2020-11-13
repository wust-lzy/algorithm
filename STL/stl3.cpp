#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<functional>
using namespace std;
int main()
{
    const int n=5;
    vector <int>s(n);
    for(int i=0;i<n;i++)
        cin>>s[i];
    transform(s.begin(),s.end(),ostream_iterator<int>(cout," "),negate<int>());
    cout<<endl;
    return 0;
}
