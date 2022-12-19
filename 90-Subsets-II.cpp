class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            if(i!=0 && nums[i-1]==nums[i]) continue;
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
        for(int i=pos+1; i<nums.size(); i++){
            if(i!=(pos+1) && nums[i-1]==nums[i]) continue;
            dfs(nums, ans, i);
        }

        ans.pop_back();
    }
};