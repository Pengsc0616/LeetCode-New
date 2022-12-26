class Solution {
public:
    int climbStairs(int n) {
        // dp[i]: total i steps, how many ways to climb to the top
        // dp[i] = dp[i-1] + dp[i-2]

        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};