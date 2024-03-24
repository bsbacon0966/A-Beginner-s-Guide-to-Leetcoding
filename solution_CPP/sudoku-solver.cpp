// if the pixel is empty , then judge the number 1 to 9 to find the possible answer
// if the pixel is run out of 1 to 9 , then we "back" to the previous pixel to run the number possible answer again
// if it always runs out , then we can say this sudoku is invalid (because it is has no possible answer)

class Solution {
public:
    bool isvalid(int row,int col,char number , vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[row][i]==number) return false;
            if(board[i][col]==number) return false;
        }
        int sr=(row/3)*3;
        int sc=(col/3)*3;
        for(int i=sr;i<sr+3;i++){
            for(int j=sc;j<sc+3;j++){
                if(board[i][j]==number) return false;
            }
        }
        return true;
    }
    bool backtracking(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.') continue;
                for(char k='1';k<='9';k++){
                    if(isvalid(i,j,k,board)){
                        board[i][j]=k;
                        if(backtracking(board)) return true;
                        board[i][j]='.';
                    }
                }
                return false;//九個數字都燒光，跳回上一步
            }
        }
        return true;//都填滿了
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};