// if nums[] is negative or 0 , just skip
// if nums[] == counter , then the [counter]'s positive number exist , counter++
// when counter < nums[] , then the [counter]'s positive is missing
// [0,1,1,2,2] => when counter is 1 and nums[1]=1 => exist => counter++ => counter is two but nums[2] = 1 => don't care


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int num = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<num) continue;
            else if(nums[i]==num) num++;
            else return num;
        }
        return num;
    }
};