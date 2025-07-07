/*
https://www.youtube.com/watch?v=IFNibRVgFBo - Tushar Roy

Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. 
You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins.
Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.
Input: [3,1,5,8]
Output: 167 
*/

#include <bits/stdc++.h>
using namespace std;
int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    vector<vector<int>>dp(n+2, vector<int>(n+2,0));;
    for(int i = n; i>=1; i--){
        for(int j =1; j<=n; j++){
            if(i>j) continue;
            int ans = 0;
            int maxi = INT_MIN;
            for(int ind = i; ind<=j; ind++){
                ans = nums[i-1]*nums[ind]*nums[j+1] + dp[i][ind-1] + dp[ind+1][j];
                maxi = max(maxi, ans);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[1][n];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << maxCoins(A) << "\n";
    return 0;
}

