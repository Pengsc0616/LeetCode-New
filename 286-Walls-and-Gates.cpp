class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int,int>> q;
        int M = rooms.size();
        int N = rooms[0].size();
        vector<pair<int, int>> t {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0; i<M; i++) for(int j=0; j<N; j++) if(rooms[i][j]==0) q.push({i, j});
        int num = 0;
        while(!q.empty()) {
            int size_t = q.size();
            num ++;
            while(size_t--) {
                pair<int, int> p = q.front();
                q.pop();
                for(const auto & tt: t) {
                    int x1 = p.first + tt.first;
                    int y1 = p.second + tt.second;
                    if(x1<0 || x1>=M || y1<0 || y1>=N) continue;
                    if(rooms[x1][y1] != 2147483647) continue;
                    rooms[x1][y1] = num;
                    q.push({x1, y1});
                }
            }
        }
    }
};