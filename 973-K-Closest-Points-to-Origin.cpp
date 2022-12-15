class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        typedef pair<int, float> Node;
        auto comp = [](const auto& a, const auto & b) {
            return a.second > b.second;
        };
        priority_queue<Node, vector<Node>, decltype(comp)> pq(comp);
        for(int i=0; i<points.size(); i++) {
            float distance = sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            pq.push({i, distance});
        }
        vector<vector<int>> ans;
        while(k--) {
            vector<int> temp = {points[pq.top().first][0], points[pq.top().first][1]};
            ans.push_back(temp);
            pq.pop();
        }
        return ans;
    }
};