#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
               };
string aa[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
bool isLeap(int year)
{
    return year % 4 == 0 && year % 100 !=0 || year % 400 == 0;
}
int getMonth(int y, int m)
{
    return a[isLeap(y)][m];
}
int main()
{
    unordered_map<string, int> map;
    map["January"] = 1;
    map["February"] = 2;
    map["March"] = 3;
    map["April"] = 4;
    map["May"] = 5;
    map["June"] = 6;
    map["July"] = 7;
    map["August"] = 8;
    map["September"] = 9;
    map["October"] = 10;
    map["November"] = 11;
    map["December"] = 12;
    int d, y;
    string m;
    while (cin >> d)
    {
        cin >> m >> y;
        int mm = map[m];
        int temp = 0;
        for (int i = 1; i < y; i++)
        {
            if (isLeap(i))
                temp += 366;
            else
                temp += 365;
        }
        for (int i = 1; i < mm; i++)
            temp += a[isLeap(y)][i];
        temp += d;
        temp--;
        temp %= 7;
        cout << aa[temp] << endl;
    }
    return 0;
}
