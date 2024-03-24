// let robot go all possible path
// if the robot is arrive the goal , to detect all pixel to see that if robit has go through all of the pixel that can walk
// need to change the pixel that robot has gone through to avoid infinite loop

class Solution {
public:
    int ans=0;
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    void backtracking(vector<vector<int>>& map,int x,int y){
        if(x<0 || x>=map.size() || y<0 || y>=map[0].size()) return;
        if(map[x][y]==-1) return;
        if(map[x][y]==2){
            for(int i=0;i<map.size();i++){
                for(int j=0;j<map[0].size();j++){
                    if(map[i][j]==0) return;
                }
            }
            ans++;
            return;
        }
        map[x][y]=-1;
        for(int i=0;i<4;i++){
            backtracking(map,x+dx[i],y+dy[i]);
        }
        map[x][y]=0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int sx;
        int sy;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    sx=i;
                    sy=j;
                }
            }
        }
        backtracking(grid,sx,sy);
        return ans;
    }
};