#include<iostream>
#include<algorithm>

using namespace std;

const int N = 110;
int a[N];
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for (int i = 0; i < n;i++)
            cin >> a[i];
        sort(a, a + n, greater<int>());
        for (int i = 0; i < n;i++)
            cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}