class Solution {    
public:
    vector<string> findItinerary(vector<vector<string>> tickets) 
    {
        sort(tickets.begin(),tickets.end());
        for (auto ticket: tickets)
            Map[ticket[0]].push(ticket[1]);
                
        vector<string> ans;
        dfs("JFK", ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
private:
    unordered_map<string,queue<string>>Map;
    void dfs(string curr, vector<string> & ans) {
        while(!Map[curr].empty()) {
            // 拿出最小的
            string next = Map[curr].front();
            Map[curr].pop();
            dfs(next, ans);
        }
        ans.push_back(curr);
    }
};

// class Solution {    
// public:
//     vector<string> findItinerary(vector<vector<string>> tickets) 
//     {
//         sort(tickets.begin(),tickets.end());
//         for (auto ticket: tickets)
//             Map[ticket[0]].push(ticket[1]);
                
//         vector<string> ans = dfs("JFK");
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// private:
//     unordered_map<string,queue<string>>Map;
//     vector<string> dfs(string curr) {
//         vector<string> ans;
//         while(!Map[curr].empty()) {
//             // 拿出最小的
//             string next = Map[curr].front();
//             Map[curr].pop();
//             vector<string> ret = dfs(next);
//             ans.insert(ans.end(), ret.begin(), ret.end());
//         }
//         ans.push_back(curr);
//         return ans;
//     }
// };


// class Solution {
// public:
//     vector<string> findItinerary(vector<vector<string>>& tickets) {
//         // sort and reverse the WHOLE 2d array
//         sort(tickets.begin(), tickets.end());
//         reverse(tickets.begin(), tickets.end());
//         unordered_map<string, vector<string>> dict;
//         for(const auto & ticket: tickets) {
//             dict[ticket[0]].push_back(ticket[1]);
//         }
//         return dfs("JFK", dict);
//     }
// private:
//     vector<string> dfs(string curr, unordered_map<string, vector<string>>& dict) {
        
//         vector<string> nexts = dict[curr];
//         for(const auto & next: nexts) {

//         }
//     }
// };