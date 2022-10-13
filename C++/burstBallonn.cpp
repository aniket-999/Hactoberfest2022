#include<bits/stdc++.h>
using namespace std;

int minn(vector<int> &nums) {
    int len = nums.size()-1;
    int min=1000000000;
    int ele=0;
    for(int i=1; i<len; i++) {
        if(nums[i] < min) {
            min = nums[i];
            ele = i;
        }
    }
    return ele;
}
    
vector<int> maxCoins(vector<int>& nums, int x, int y) {
    int  n=x;
    int i=y;
    vector<int> anss;
    anss.push_back(0);
    int ans;
    if(n > 2) {
        int min = minn(nums);
        ans = anss[i] + nums[min-1] * nums[min] * nums[min+1];
        anss.push_back(ans);
        nums.erase(nums.begin() + min);
        --n;
        ++i;
        maxCoins(nums, n, i);
    }
    else if(n==2) {
        int minimum =0;
        if(nums[0] < nums[1]) {
            minimum = 0;
        }
        else {
            minimum = 1;
        }
        ans = anss[i] + nums[0]*nums[1];
        anss.push_back(ans);
        nums.erase(nums.begin() + minimum);
        --n;
        ++i;
        // return n;
    }
    if(n == 1) {
        ans = anss[i] + nums[0];
        anss.push_back(ans);
        ++i;
        // return n;
    }
    int answer = anss[i-1];
    return anss;
}

int main() {
    vector<int> nums;
    int x;
    int y;
    vector<int> v;
    for(int i=0; i<4; i++) {
        cin >> x;
        nums.push_back(x);
    }

    nums.erase(nums.begin() + 1);
    
    nums.erase(nums.begin() + 1);
    cout << nums[1];
    
    // x= minn(nums);
    // cout << x << "\n";

    // nums.erase(nums.begin() + x);
    // // y = nums.size();
    // y = minn(nums);
    // cout << y << "\n";

    // v= maxCoins(nums, 4, 0);
    // for(int i=0; i<4; i++) {
    //     cout << v[i] << " ";
    // }
    // cout << "\n";

    
    return 0;
}


/*

3 1 5 8

3 5 8

*/