// sort the nums
// if encounter the same number just skip 
// if the number is different than the previous one , that means it is still Consecutive


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int now=nums[0];
        int ans=0;
        int n=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==now) continue;
            if(nums[i]==now+1){
                n++;
                now=now+1;
            }
            else{
                ans=max(ans,n);
                n=1;
                now=nums[i];
            }
        }   
        ans=max(ans,n);
        return ans;
    }
};