#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    double temp;
    for (int i = 0; i < n;i++)
    {
        cin >> temp;
        if(temp<m)
            printf("On Sale! %.1f\n", temp);
    }
    return 0;
}
/*
4 99
98.0
97.0
100.2
98.9

On Sale! 98.0
On Sale! 97.0
On Sale! 98.9
*/