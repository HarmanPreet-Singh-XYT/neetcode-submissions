class Solution {
public:
    int shortestPath(vector<vector<int>>& grid) {
        int ROWS = grid.size(),COLS=grid[0].size();
        if (grid[0][0] == 1) return -1;
        queue<pair<int,int>> que;
        vector<vector<int>> visit(ROWS,vector<int>(COLS));
        que.push(pair<int,int>(0,0));
        visit[0][0] = 1;

        int length = 0;
        while(que.size()){
            int size = que.size();
            for(int i = 0;i<size;i++){
                pair<int,int> curPair = que.front();
                que.pop();
                int r = curPair.first, c = curPair.second;
                if(r==ROWS-1 && c==COLS-1){
                    return length;
                }

                int pre[4][2] = {{r,c-1},{r,c+1},{r+1,c},{r-1,c}};
                for(int j = 0; j<4;j++){
                    int newR = pre[j][0],newC = pre[j][1];
                    if(min(newR,newC) < 0 || newR == ROWS || newC == COLS || grid[newR][newC] || visit[newR][newC]){
                        continue;
                    }
                    que.push(pair<int,int>(newR,newC));
                    visit[newR][newC] = 1;
                }


            }
            length++;
        }
        return -1;
    }
};
