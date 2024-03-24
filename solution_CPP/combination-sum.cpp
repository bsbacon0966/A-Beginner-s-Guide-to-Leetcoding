// to find the nnumber that is good to combine
// if we don't want this element , we can just pick out the element
// keep "go" and "back" to go all the possible combinations 

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
            tmp.push_back(candidates[i]);
            backtracking(candidates, target - candidates[i], i);  // 注意递归传参时，起始位置为当前位置 i，允许重复使用当前元素
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0);
        return ans;
    }
};