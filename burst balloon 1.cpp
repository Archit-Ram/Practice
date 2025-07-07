/*
There are n balloons and n bullets and each balloon is assigned with a particular number (point).
Whenever a particular balloon is shot the no of points increases by
1.the multiplication of point assigned to balloon on left and that of right side.
2.point assigned to left if no right exists
3.point assigned to right if no left exists.
4.the point assigned to itself if no other balloon exists.
 
You have to output the maximum no of points possible.
 
Input
1 2 3 4
 
Output
20
*/

/*
5
1 2 3 5 4
*/

#include <bits/stdc++.h>
using namespace std;

int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    vector<vector<int>> dp(n+2, vector<int>(n+2,0));
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= n; j++) {
            if (i > j) continue;
            int maxi = INT_MIN;
            for(int ind = i; ind <= j; ind++) {
                int gain;
                if (i==1 && j==n) {
                    gain = nums[ind];
                } else {
                    gain = nums[i-1] * nums[j+1];
                }
                
                int cand = gain 
                         + dp[i][ind-1] 
                         + dp[ind+1][j];
                maxi = max(maxi, cand);
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
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << maxCoins(A) << "\n";
    return 0;
}
