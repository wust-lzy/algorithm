#include<iostream>
using namespace std;

int lowbit(int x){
    return x & (-x);
}
int main()
{
    int t;
    cin >> t;
    while(t--){
        int x, res = 0;
        scanf("%d", &x);
        while(x)
        {
            res++;
            x -= lowbit(x);
        }
        printf("%d", res);
    }
    return 0;
}