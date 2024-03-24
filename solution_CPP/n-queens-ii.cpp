// just like N-queen but record the possiable answer that queen con stand


class Solution {
public:
    int ans=0;
    void backtracking(vector<vector<int>> mp,int n,int now){
        if(now==n){
            ans++;
            return;
        }
        for(int i=0;i<n;i++){
            bool is_valid=true;
            int judge_90=0;
            while(now-judge_90>=0){
                if(mp[now-judge_90][i]==1) is_valid=false;
                judge_90++;
            }
            int judge_135=0;
            while(now-judge_135>=0&&i-judge_135>=0){
                if(mp[now-judge_135][i-judge_135]==1) is_valid=false;
                judge_135++;
            }
            int judge_45=0;
            while(now-judge_45>=0&&i+judge_45<n){
                if(mp[now-judge_45][i+judge_45]==1) is_valid=false;
                judge_45++;
            }
            if(is_valid){
                mp[now][i]=1;
                backtracking(mp,n,now+1);
                mp[now][i]=0;
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<int>> mp(n,vector<int>(n,0));
        backtracking(mp,n,0);
        return ans;
    }
};