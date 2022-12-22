class Solution {
public:
    void solve(vector<vector<char>>& board) {
        M = board.size();
        N = board[0].size();
        for(int i=0; i<M; i++) dfs(board, i, 0);
        for(int i=0; i<N; i++) dfs(board, 0, i);
        for(int i=0; i<M; i++) dfs(board, i, N-1);
        for(int i=0; i<N; i++) dfs(board, M-1, i);
        for(int i=0; i<M; i++) for(int j=0; j<N; j++) if(board[i][j]=='O') board[i][j] = 'X';
        for(int i=0; i<M; i++) for(int j=0; j<N; j++) if(board[i][j]=='-') board[i][j] = 'O';
    }
private:
    int M;
    int N;
    vector<pair<int, int>> t {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<char>>& board, int x, int y) {
        if(board[x][y] == 'X') return;
        board[x][y] = '-';
        for(const auto & tt: t) {
            int x1 = x + tt.first;
            int y1 = y + tt.second;
            if(x1<0 || x1>=M || y1<0 || y1>=N) continue;
            if(board[x1][y1] == '-') continue;
            dfs(board, x1, y1);
        }
    }
};