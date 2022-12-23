class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n == 0) return true;
        for(int i=0; i<n; i++) parents.push_back(i);
        for(const auto & edge: edges) {
            int x = edge[0];
            int y = edge[1];
            int parentX = findFather(x);
            int parentY = findFather(y);
            if(parentX == parentY) return false;
            parents[parentX] = parentY;
        }
        int root = findFather(0);
        // check if there happens to be multiple trees
        for(int i=0; i<n; i++) if(findFather(i) != root) return false;
        return true;
    }
private:
    vector<int> parents;
    int findFather(int x) {
        if(parents[x] != x) parents[x] = findFather(parents[x]);
        return parents[x];
    }
};