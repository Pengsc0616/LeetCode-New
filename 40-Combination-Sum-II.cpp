class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        /*
        [10,1,2,7,6,1,5]
        [1,1,2,5,6,7,10]
        */
        sort(candidates.begin(), candidates.end());
        vector<int> ans;
        for(int i=0; i<candidates.size(); i++) {
            if(i!=0 && candidates[i-1]==candidates[i]) continue;
            ans.push_back(candidates[i]);
            dfs(candidates, target, candidates[i], i, ans);
            ans.pop_back();
        }
        return answer;
    }
    vector<vector<int>> answer;
    void dfs(vector<int>& candidates, int target, int curr, int pos, vector<int> & ans) {
        if(target == curr) {
            answer.push_back(ans);
            return;
        }
        if(target < curr) return;
        for(int i=pos+1; i<candidates.size(); i++){
            if(i!=pos+1 && candidates[i-1]==candidates[i]) continue;
            ans.push_back(candidates[i]);
            dfs(candidates, target, curr+candidates[i], i, ans);
            ans.pop_back();
        }
    }
};

















