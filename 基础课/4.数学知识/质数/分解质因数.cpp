#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

void divide(int x)
{
    for (int i = 2; i <= x/i;i++){
        if(x%i==0)
        {
            int cnt = 0;
            while(x%i==0)
            {
                x /= i;
                cnt++;
            }
            cout << i << " " << cnt << endl;
        }
    }
    if(x>1)
        printf("%d %d\n", x, 1);
    puts("");
}
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int x;
        cin>>x;
        divide(x);
    }
    return 0;
}