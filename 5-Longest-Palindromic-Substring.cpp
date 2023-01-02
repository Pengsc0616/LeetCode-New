class Solution {
public:
    string longestPalindrome(string s) {
        // dp[i][j] = center i, width j
        // dp[i][j] = dp[i][j-1] && (s[i-j] == s[i+j]) 

        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for(int i=0; i<s.size(); i++) {
            dp[i][0] = true;
        }
        int ansL = -1;
        int ansR = -1;
        for(int j=1; j<s.size(); j++) {
            for(int i=0; i<s.size(); i++) {
                if(i-j>=0 && i+j<s.size() && i+j>=0 && i-j<s.size()){
                    dp[i][j] = dp[i][j-1] && (s[i-j] == s[i+j]);
                    if(dp[i][j]) {
                        ansL = i-j;
                        ansR = i+j;
                    }
                }
            }
        }
        string ret1 = "";
        if(ansL != -1)  ret1 = s.substr(ansL, ansR-ansL+1);
        
        ansL = -1;
        ansR = -1;
        dp = vector<vector<bool>>(s.size(), vector<bool>(s.size(), false));
        for(int i=0; i<s.size()-1; i++) {
            dp[i][0] = s[i]==s[i+1];
            if(dp[i][0]) {
                ansL = i;
                ansR = i+1;
            }
        }
        for(int j=1; j<s.size(); j++) {
            for(int i=0; i<s.size(); i++) {
                int left = i-j;
                int right = i+1+j;
                if(left>=0 && right<s.size() && right>=0 && left<s.size()){
                    dp[i][j] = dp[i][j-1] && (s[left] == s[right]);
                    if(dp[i][j]) {
                        ansL = left;
                        ansR = right;
                    }
                }
            }
        }
        cout << ansL << ansR;
        if(ansL != -1 && ret1.size()<(ansR-ansL+1))  ret1 = s.substr(ansL, ansR-ansL+1);
        if(ret1 == "") return s.substr(0,1);
        return ret1;
    }
};