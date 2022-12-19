class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            dfs(nums, ans, i);
        }
        answer.push_back({});
        return answer;
    }
private:
    vector<vector<int>> answer;
    void dfs(vector<int>& nums, vector<int> & ans, int pos) {
        if(pos == nums.size()) return;
        ans.push_back(nums[pos]);

        answer.push_back(ans);
        // if(pos == nums.size()-1) return;
        for(int i=pos+1; i<nums.size(); i++){
            dfs(nums, ans, i);
        }

        ans.pop_back();
    }
};