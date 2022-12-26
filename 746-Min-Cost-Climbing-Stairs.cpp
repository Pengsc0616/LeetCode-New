class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // vector<int> dp(cost.size(), 0);
        // dp[0] = cost[0];
        // dp[1] = min(cost[0], cost[1]);
        // for(int i=2; i<cost.size(); i++) {
        //     dp[i] = min(dp[i-1], dp[i-2]+cost[i]);
        // }
        
        // // vector<int> cost = costt;
        // // cost.push_back(0);
        // vector<int> dp(cost.size(), 0);
        // int n = cost.size();
        // dp[n-1] = cost[n-1];
        // dp[n-2] = cost[n-2];

        // dp[i]: 如果"真的跳到"我的這格來，最小的cost是多少
        vector<int> dp(cost.size(), 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2; i<cost.size(); i++) {
            dp[i] = min(dp[i-1], dp[i-2]) +cost[i];

        }
        return min(dp[cost.size()-1], dp[cost.size()-2]);
    }
};