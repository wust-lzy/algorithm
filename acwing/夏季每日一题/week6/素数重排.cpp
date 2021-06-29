#include <iostream>
#include<string.h>
using namespace std;

int main()
{
    int n, t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n;i++){
            for (int j = 0; j < n;j++){
                if(i==j||j==(i+1)%n)
                    cout << 1;
                else
                    cout << 0;
                cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}