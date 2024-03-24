// using backtracking to find the pixel that queen can place
// if queen can not place then "back" to the previous queen to adjust the place
// queen : can go 8 direction => to find the pixel that queen can place without touching other queen 8 directions

class Solution {
public:
    vector<vector<string>> ans;
    vector<string> mp;
    void backtracking(vector<string>& now_mp, int n, int now){
        if(now == n){
            ans.push_back(now_mp);
            return;
        }
        for(int i=0; i<n; i++){
            bool is_valid = true;
            int judge_90 = 0;
            while(now-judge_90 >= 0){
                if(now_mp[now-judge_90][i] == 'Q') is_valid = false;
                judge_90++;
            }
            int judge_135 = 0;
            while(now-judge_135 >= 0 && i-judge_135 >= 0){
                if(now_mp[now-judge_135][i-judge_135] == 'Q') is_valid = false;
                judge_135++;
            }
            int judge_45 = 0;
            while(now-judge_45 >= 0 && i+judge_45 < n){
                if(now_mp[now-judge_45][i+judge_45] == 'Q') is_valid = false;
                judge_45++;
            }
            if(is_valid){
                now_mp[now][i] = 'Q';
                backtracking(now_mp, n, now+1);
                now_mp[now][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        for(int i=0; i<n; i++){
            mp.push_back("");
            for(int j=0; j<n; j++){
                mp[i].push_back('.');
            }
        }
        backtracking(mp, n, 0);
        return ans;
    }
};

