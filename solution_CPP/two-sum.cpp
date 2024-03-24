// two-sum
// hash all possible num 
// using hashtable to find the value that can combine the target value
//hashtable record the value and it's index
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashTable;
        for(int i=0;i<nums.size();i++){
            if(hashTable.find(target-nums[i])!=hashTable.end()){
                return {hashTable[target-nums[i]],i};
            }
            hashTable[nums[i]] = i;
        }
        return {};
    }
};