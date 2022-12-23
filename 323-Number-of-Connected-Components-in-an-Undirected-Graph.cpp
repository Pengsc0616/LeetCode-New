class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        for(const auto & edge: edges) {
            int x = edge[0];
            int y = edge[1];
            if(fathers.find(x) == fathers.end()) fathers[x] = x;
            if(fathers.find(y) == fathers.end()) fathers[y] = y;
            int fatherX = findFather(x);
            int fatherY = findFather(y);
            if(fatherX > fatherY) fathers[fatherX] = fatherY;
            else fathers[fatherY] = fatherX;
        }
        unordered_set<int> Set;
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(fathers.find(i) == fathers.end()) {
                Set.insert(i);
                ans ++;
                continue;
            }
            int father = findFather(i);
            if(!Set.count(father)) {
                Set.insert(father);
                ans ++;
            }
        }
        return ans;
            
    }
private:
    unordered_map<int, int> fathers;
    int findFather(int x) {
        if(fathers[x] != x) fathers[x] = findFather(fathers[x]);
        return fathers[x];
    }
};