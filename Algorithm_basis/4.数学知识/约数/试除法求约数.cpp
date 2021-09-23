#include <iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

void func(int x)
{
    vector<int> ans;
    for (int i = 1; i <= x / i; i++)//等效于根号x
    {
        if(x%i==0)//x被i整除
        {
            ans.emplace_back(i);
            if (i !=x/i) //判断连个因数是否相等
                ans.emplace_back(x / i);
        }
    }
    sort(ans.begin(), ans.end());//排序
    for(int e:ans)
        cout << e << " ";
    puts("");
}
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        func(x);
    }
    return 0;
}