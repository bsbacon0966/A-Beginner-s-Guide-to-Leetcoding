// different than combinationSum , input will have same elements
//  We want to avoid redundant computation, like [1(0),1(1),1(2)], we just need [1(0)], [1(0),1(1)], [1(0),1(1),1(2)], and don't need [1(0),1(2)], since it is redundant. 
// if(i>start && candidates[i] == candidates[i-1]) continue; key line , this line will avoid like [1(0),1(2)]

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    void backtracking(vector<int>& candidates, int target, int start) {
        if (target < 0) {
            return;
        } else if (target == 0) {
            ans.push_back(tmp);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if(i>start && candidates[i] == candidates[i-1]) continue; //關鍵句子，避免鬼長重複元素
            tmp.push_back(candidates[i]);
            backtracking(candidates, target - candidates[i], i+1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtracking(candidates , target , 0);
        return ans;
    }
};