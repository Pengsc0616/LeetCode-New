class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        for(int i=1; i<=amount; i++) {
            for(const auto & coin: coins) {
                if(i-coin >= 0 && i-coin<=amount && dp[i-coin]!=-1) {
                    if(dp[i] == -1) dp[i] = dp[i-coin]+1;
                    else dp[i] = min(dp[i], dp[i-coin]+1);
                }
            }
        }
        return dp[amount];
    }
};

/*

0 0
1 1
2 2
3 
4 
5 
*/