class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        /* dp[i][j] = (s[i]==s[j] && dp[i+1][j-1]) */
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i=0; i<n; i++) dp[i][i] = true;
        ans += n;
        for(int i=0; i<n-1; i++) 
        {
            if(s[i]==s[i+1]) 
            {
                dp[i][i+1] = true;
                ans++;
            }
        }
        
        for(int l=3; l<=n; l++)
        {
            for(int i=0; i<n; i++)
            {
                if((i+l-1 < n) && (s[i] == s[i+l-1]) && dp[i+1][i+l-2])
                {
                    dp[i][i+l-1] = true;
                    ans ++;
                }   
            }
        }
        return ans;
    }
};

class Solution {
public:
    int countSubstrings(string s) {
        // dp[i][j] = center i, width j
        // dp[i][j] = dp[i][j-1] && (s[i-j] == s[i+j]) 

        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int ans = 0;
        for(int i=0; i<s.size(); i++) {
            dp[i][0] = true;
            ans++;
        }
        for(int j=1; j<s.size(); j++) {
            for(int i=0; i<s.size(); i++) {
                if(i-j>=0 && i+j<s.size() && i+j>=0 && i-j<s.size()){
                    dp[i][j] = dp[i][j-1] && (s[i-j] == s[i+j]);
                    if(dp[i][j]) {
                        ans++;
                    }
                }
            }
        }

        dp = vector<vector<bool>>(s.size(), vector<bool>(s.size(), false));
        for(int i=0; i<s.size()-1; i++) {
            dp[i][0] = s[i]==s[i+1];
            if(dp[i][0]) {
                ans++;
            }
        }
        for(int j=1; j<s.size(); j++) {
            for(int i=0; i<s.size(); i++) {
                int left = i-j;
                int right = i+1+j;
                if(left>=0 && right<s.size() && right>=0 && left<s.size()){
                    dp[i][j] = dp[i][j-1] && (s[left] == s[right]);
                    if(dp[i][j]) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};