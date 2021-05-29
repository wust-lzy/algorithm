#include<bits/stdc++.h>
using namespace std;
int n, m, ans[105];
int main()
{
    int k, temp, cz, index = 1;
    cin >> n >> m;
    vector<int> v[n + 1];
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &k);
        for (int j = 0; j < k;j++)
        {
            scanf("%d", &temp);
            v[i].push_back(temp);
        }
    }
    // cout << n << " " << m;
    // for (int i = 1; i <= n;i++)
    //     cout << v[i].size() << endl;

    for (int i = 1; i <= m;i++)
    {
        scanf("%d %d", &temp, &cz);
        if(temp==0)
            index = v[index][cz-1];
        else if(temp==1)
        {
            printf("%d\n", index);
            ans[cz] = index;
        }
        else if(temp==2)
            index = ans[cz];
    }
    cout << index;
    return 0;
}

/*
10 11
3 2 3 4
1 6
3 4 7 5
1 3
1 9
2 3 5
3 1 8 5
1 9
2 8 10
0


1 1
0 3
0 1
1 2
0 2
0 2
2 2
0 3
0 1
1 1
0 2

*/