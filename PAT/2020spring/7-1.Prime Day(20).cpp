#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isprime(int x)
{
    if(x<=1)
        return 0;
    for (int i = 2; i * i <= x;i++)
    if(x%i==0)
        return 0;
    return 1;
}
int main()
{
    string s;
    cin >> s;
    bool ans = true;
    for (int i = 0; i < s.length();i++)
    {
        string temp = s.substr(i);
        bool flag = isprime(stoi(temp));
        printf("%s %s\n", temp.c_str(), flag? "Yes" : "No");
        if(flag==false)
            ans = false;
    }
    if(ans)
        cout << "All Prime!" << endl;
    return 0;
}