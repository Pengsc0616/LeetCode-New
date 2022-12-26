class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // Prim Algorithm
        unordered_map<int, vector<pair<int,int>>> M;
        for(int i=0; i<points.size()-1; i++) {
            for(int j=i+1; j<points.size(); j++) {
                M[i].push_back({j, abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])});
                M[j].push_back({i, abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])});
            }
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0,0});
        int target = points.size();
        int cost = 0;
        set<int> Set;
        while(!pq.empty()) {
            // curr = {dis, j}
            pair<int,int> curr = pq.top();
            pq.pop();
            if(Set.count(curr.second)) continue;
            int next = curr.second;
            Set.insert(next);
            cost += curr.first;
            if(Set.size() == target) return cost;
            for(const auto & neighbor: M[next]) {
                pq.push({neighbor.second, neighbor.first});
            }
        }
        return 0;
    }
};