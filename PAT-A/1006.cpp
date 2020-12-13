#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char t1[100] = "23:59:59";
char t2[100] = "00:00:00";
string ans1, ans2;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        char s[100],s1[100],s2[100];
        cin >> s >> s1 >> s2;
        if(strcmp(s1,t1)<0)
        {
            ans1 = s;
            strcpy(t1, s1);
        }
        if(strcmp(s2,t2)>0)
        {
            ans2 = s;
            strcpy(t2, s2);
        }
    }
    cout << ans1 << " " << ans2;
    return 0;
}