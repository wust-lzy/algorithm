#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int N = 1e5 + 10;


void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;
    while(i>=0&&nums[i]>=nums[i+1])
        i--;
    if(i>=0)
    {
        int j = n - 1;
        while(j>=0&&nums[i]>=nums[j])
            j--;
        swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
}
int main()
{
    cout<<123;
    return 0;
}