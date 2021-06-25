#include <iostream>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int l, r;
        cin >> l >> r;
        printf("%s\n",l*2>r?"YES":"NO");
    }
    return 0;
}