class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ROWS = grid.size(),COLS = grid[0].size();
        if(grid[0][0]) return -1;
        vector<vector<int>> visit(ROWS,vector<int>(COLS));
        queue<pair<int,int>> que;
        que.push(pair<int,int>(0,0));
        visit[0][0] = 1;
        int length = 0;
        while(!que.empty()){
            int size = que.size();
            for(int i = 0;i<size;i++){
                pair<int,int> curPair = que.front();
                que.pop();
                int r = curPair.first, c = curPair.second;
                if(r == ROWS-1 && c == COLS-1) return length+1;
                int neighbors[8][2] = {{r+1,c},{r-1,c},{r,c+1},{r,c-1},{r+1,c+1},{r-1,c-1},{r+1,c-1},{r-1,c+1}};
                for(int j = 0;j<8;j++){
                    int newR = neighbors[j][0],newC=neighbors[j][1];
                    if(min(newR,newC) < 0 || newR >= ROWS || newC >= COLS || grid[newR][newC] || visit[newR][newC]){
                        continue;
                    }
                    visit[newR][newC] = 1;
                    que.push(pair<int,int>(newR,newC));
                }
            }
            length++;
        }
        return -1;
    }
};