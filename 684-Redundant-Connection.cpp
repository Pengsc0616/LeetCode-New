class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(const auto & edge: edges) {
            int x = edge[0];
            int y = edge[1];
            if(parents.find(x) == parents.end()) parents[x] = x;
            if(parents.find(y) == parents.end()) parents[y] = y;
            int parentX = findFather(x);
            int parentY = findFather(y);
            if(parentX == parentY) return edge;
            parents[parentX] = parentY;
        }
        return {};
    }
private:
    unordered_map<int, int> parents;
    int findFather(int x) {
        if(parents[x] != x) parents[x] = findFather(parents[x]);
        return parents[x];
        // Cannot return "x" because x hasn't been updated
        // return x;
    }
};