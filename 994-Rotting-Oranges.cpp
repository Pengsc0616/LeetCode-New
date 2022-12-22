class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid1) {
        vector<vector<int>> grid = grid1;
        queue<pair<int,int>> q;
        int M = grid.size();
        int N = grid[0].size();
        vector<pair<int, int>> t {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0; i<M; i++) for(int j=0; j<N; j++) if(grid[i][j]==2) q.push({i, j});
        int ans = -1;
        while(!q.empty()) {
            ans ++;
            int size_t = q.size();
            while(size_t--) {
                pair<int, int> p = q.front();
                q.pop();
                for(const auto & tt: t) {
                    int x1 = p.first + tt.first;
                    int y1 = p.second + tt.second;
                    if(x1<0 || x1>=M || y1<0 || y1>=N) continue;
                    if(grid[x1][y1] != 1) continue;
                    grid[x1][y1] = 2;
                    q.push({x1, y1});
                }
            }
        }
        for(int i=0; i<M; i++) for(int j=0; j<N; j++) if(grid[i][j]==1) return -1;
        return ans<0?0:ans; 
    }
};