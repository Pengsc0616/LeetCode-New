class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for(int i=0; i<s.size(); i++) dp[i][i] = true;
        for(int i=0; i<s.size()-1; i++) if(s[i]==s[i+1]) dp[i][i+1] = true;
        for(int len=3; len<=s.size(); len++) {
            for(int i=0; i<=(s.size()-len); i++) {
                int j = i+len-1;
                if((s[i]==s[j]) && (dp[i+1][j-1])) dp[i][j] = true;
            }
        }
        vector<string> ans;
        dfs(dp, ans, 0, s);
        return answer;
    }
private:
    vector<vector<string>> answer;
    void dfs(vector<vector<bool>>& dp, vector<string> &ans, int pos, string& s) {
        if(pos == s.size()) {
            answer.push_back(ans);
            return;
        }
        for(int i=pos; i<s.size(); i++) {
            if(dp[pos][i]) {
                ans.push_back(s.substr(pos, i-pos+1));
                dfs(dp, ans, i+1, s);
                ans.pop_back();
            }
        }
    }
};