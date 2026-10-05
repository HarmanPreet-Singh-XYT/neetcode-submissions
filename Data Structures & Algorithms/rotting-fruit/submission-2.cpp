class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size(),COLS = grid[0].size();
        queue<pair<int,int>> que;
        vector<vector<int>> visit(ROWS,vector<int>(COLS));
        int fresh = 0;
        for(int i = 0;i<ROWS;i++){
            for(int j = 0;j<COLS;j++){
                if(grid[i][j]==2){
                    que.push(pair<int,int>(i,j));
                    visit[i][j] = 1;
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        int minute = 0;
        while(!que.empty() && fresh>0){
            int size = que.size();
            for(int i = 0;i<size;i++){
                pair<int,int> curPair = que.front();
                que.pop();
                int r = curPair.first,c = curPair.second;
                
                int neighbors[4][2] = {{r+1,c},{r-1,c},{r,c+1},{r,c-1}};
                for(int j =0; j<4; j++){
                    int newR = neighbors[j][0],newC = neighbors[j][1];
                    if(min(newR,newC) < 0 || newR >= ROWS || newC >= COLS || visit[newR][newC] || grid[newR][newC]!=1){
                        continue;
                    }
                    que.push(pair<int,int>(newR,newC));
                    fresh--;
                    visit[newR][newC] = 1;
                }
            }
            minute++;
        }
        return fresh==0 ? minute : -1;
    }
};
