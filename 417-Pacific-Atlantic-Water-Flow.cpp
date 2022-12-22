class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        M = heights.size();
        N = heights[0].size();
        pacific  = vector<vector<bool>>(M, vector<bool>(N, false));
        atlantic = vector<vector<bool>>(M, vector<bool>(N, false));
        for(int i=0; i<M; i++) dfs(heights, i, 0, pacific);
        for(int i=0; i<N; i++) dfs(heights, 0, i, pacific);
        for(int i=0; i<M; i++) dfs(heights, i, N-1, atlantic);
        for(int i=0; i<N; i++) dfs(heights, M-1, i, atlantic);
        vector<vector<int>> ans;
        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
private:
    int M;
    int N;
    // // 不能在unordered_set裡放pair
    // unordered_set<pair<int, int>> pacific;
    // unordered_set<pair<int, int>> atlantic;
    vector<vector<bool>> pacific;
    vector<vector<bool>> atlantic;
    vector<pair<int, int>> t {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<int>>& heights, int x, int y, vector<vector<bool>> &ocean) {
        ocean[x][y] = true;
        for(const auto & tt: t) {
            int x1 = x + tt.first;
            int y1 = y + tt.second;
            if(x1<0 || x1>=M || y1<0 || y1>=N) continue;
            if(ocean[x1][y1]) continue;
            if(heights[x1][y1] < heights[x][y]) continue;
            dfs(heights, x1, y1, ocean);
        }
    }
};


// class Solution {
// public:
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//         // dp[i][j] = if heights[i][j] can flow to both Pacific and Atlantic ocean
//         // dp[i][j] =    (dp[i-1][j] && heights[i][j]>=heights[i-1][j])
//         //             ||(dp[i+1][j] && heights[i][j]>=heights[i+1][j])
//         //             ||(dp[i][j-1] && heights[i][j]>=heights[i][j-1])
//         //             ||(dp[i][j+1] && heights[i][j]>=heights[i][j+1])
//         // not going to work
//         // int M = heights.size();
//         // int N = heights[0].size();
//         // vector<vector<int> dp(M, vector<int>(N, 0));
//         // for(int i=0; i<M; i++) dp[i][0]++;
//         // for(int i=0; i<N; i++) dp[0][i]++;
//         // for(int i=0; i<M; i++) dp[i][N-1]++;
//         // for(int i=0; i<N; i++) dp[0][M-1]++;
//         // for(int i=0; i<M; i++) {
//         //     for()
//         // }
//     }
// };









