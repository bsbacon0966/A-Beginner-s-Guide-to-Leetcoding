// using set to record the element that is in the nums
// set only recond one time

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> list;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(list.find(nums[i])!=list.end()){
                ans.push_back(nums[i]);
            }
            else list.insert(nums[i]);
        }
        return ans;
    }
};