// class Solution {
// public:
//     int numDecodings(string s) {
// Unfinished
//         if(s[0] == 0) return 0;
//         // dp[i] ways of decoding from position i 
//         int size_S = s.size();
//         vector<int> dp(size_S, -1);
//         // dp[i] = dp[i-1](if s[i-1]!=0) + dp[i-2](if s[i-2]+s[i-1]<=26)
//         // dp[i] = dp[i+1](if s[i]!=0) + dp[i+2](if s[i]+s[i+1]<=26)
//         dp[0] = 1;
//         dp[1] = stoi(s.substr(0,2))<=26? 2:1;
//         if(s.size() <= 2) return dp[s.size()-1];
//         for(int i=3; i<s.size(); i++) {
//             int temp = s[i-1]!=0? dp[i-1]:0;
//             if(stoi(s.substr(0,2))<=26)
//         }
//     }
// };

class Solution {
public:
    int numDecodings(string s) {
        // dp[i] ways of decoding from position i 
        size_S = s.size();
        dp = vector<int>(size_S, -1);
        return dfs(0, s);
    }
private:
    vector<int> dp;
    int size_S;
    int dfs(int x, string & s) {
        if(x == size_S) return 1;
        if(dp[x] != -1) {
            return dp[x];
        }
        // if(x == size_S) return 1;
        int ret = 0;
        if(s[x] == '0') return 0;
        ret = dfs(x+1, s);
        if(x+2 > size_S) return ret;
        if(stoi(s.substr(x,2))>26) return ret;
        ret += dfs(x+2, s);
        dp[x] = ret;
        return ret;
    }
};