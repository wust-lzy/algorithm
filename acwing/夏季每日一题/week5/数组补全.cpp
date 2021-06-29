#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1000;
int n, k, p, x, y;
int main()
{
    cin >> n >> k >> p >> x >> y;
    //令中位数为y  y左边的数有n/2个，右边的数有n/2+1个
    int l = 0, r = 0, sum = 0; 
    for (int i = 0; i < k;i++){
        int t;
        cin >> t;
        sum += t;
        if(t<y)
            l++;
        else
            r++;
    }
    int right = max(n / 2 + 1, r), left = n - r;
    if(l>left)
        puts("-1");
    else{
        sum += (left - l) + (right - r) * y;
        if(sum>x){
            puts("-1");
            return 0;
        }
        for (int i = 0; i < left - l;i++)
            cout << "1 ";
        for (int i = 0; i < right-r;i++)
            cout << y << " ";
    }
    return 0;
}