#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    if (s.length() == 4)
    {
        string temp = s.substr(0, 2);
        int t;
        if (stoi(temp) < 22)
            t = 20;
        else
            t = 19;
        cout << t << temp << "-" << s.substr(2, 2);
    }
    else
        cout << s.substr(0, 4) << "-" << s.substr(4, 2);
    return 0;
}