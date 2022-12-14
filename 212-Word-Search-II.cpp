class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TreeNode();
        for(const auto word: words) {
            TreeNode* node = root;
            for(const auto w: word) {
                if(node->next[w-'a'] == NULL) node->next[w-'a'] = new TreeNode();
                node = node->next[w-'a'];
                node->count ++;
            }
            node->isEnd = true;
        }
        n = board.size();
        m = board[0].size();
        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                dfs(board, i, j, root, "");
            }
        }
        return ans;
    }
private:
    class TreeNode{
    public:
        TreeNode() {
            for(int i=0; i<26; i++) next[i] = NULL;
            isEnd = false;
            count = 0;
        }
        TreeNode* next[26];
        bool isEnd;
        int count;
    };
    TreeNode* root;
    int n;
    int m;
    vector<vector<bool>> visited;
    vector<string> ans;
    vector<pair<int,int>> it {{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(vector<vector<char>>& board, int x, int y, TreeNode* node, string word) {
        if(node->next[board[x][y]-'a'] == NULL) return;
        if(node->next[board[x][y]-'a']->count == 0) return;
        node = node->next[board[x][y]-'a'];
        visited[x][y] = true;
        // if(node->isEnd && !rets.count((word+board[x][y]))) {
        if(node->isEnd) {
            ans.push_back(word+board[x][y]);
            trim(word+board[x][y]);
        }
        // vector<vector<int>> it {{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0; i<4; i++) {
            int newX = x+it[i].first;
            int newY = y+it[i].second;
            if(newX<0 || newX>=n || newY<0 || newY>=m) continue;
            if(visited[newX][newY]) continue;
            dfs(board, newX, newY, node, word+board[x][y]);
        }
        visited[x][y] = false;
    }
    void trim(string word) {
        TreeNode* node = root;
        for(const auto & w: word) {
            node = node->next[w-'a'];
            node->count --;
        }
        // node->isEnd = false;
        node->isEnd = false;
    }
};
