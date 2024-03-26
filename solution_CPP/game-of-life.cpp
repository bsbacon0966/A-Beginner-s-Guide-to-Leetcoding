// to look the 8 directions to determine which situation should be in next state
// using addtional space to remember the state
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dx[8]={-1,-1,-1,0,0,1,1,1};
        int dy[8]={-1,0,1,-1,1,-1,0,1};
        vector<int> ans; 
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==0){
                    int check=0;
                    for(int k=0;k<8;k++){
                        if(i+dx[k]<0 ||i+dx[k]>=board.size()) continue;
                        if(j+dy[k]<0 ||j+dy[k]>=board[0].size()) continue;
                        if(board[i+dx[k]][j+dy[k]]==1) check++;
                    }
                    if(check==3) ans.push_back(1);
                    else ans.push_back(0);
                }
                else{
                    int check=0;
                    for(int k=0;k<8;k++){
                        if(i+dx[k]<0 || i+dx[k]>=board.size()) continue;
                        if(j+dy[k]<0 ||j+dy[k]>=board[0].size()) continue;
                        if(board[i+dx[k]][j+dy[k]]==1) check++;
                    }
                    if(check<2) ans.push_back(0);
                    else if(check==2 || check==3) ans.push_back(1);
                    else ans.push_back(0);
                }
            }
        }
        int index=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                board[i][j]=ans[index];
                index++;
            }
        }
    }
};