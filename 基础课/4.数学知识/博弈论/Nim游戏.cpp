#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 100010;
//结论 ： 全部异或 结果不为0则必胜，否则必败
int main()
{
    int n, fir, x;
    cin >> n;
    scanf("%d", &fir);
    for (int i = 1; i < n;i++)
    {
        scanf("%d", &x);
        fir ^= x;
    }
    printf("%s", fir ? "Yes" : "No");
    return 0;
}