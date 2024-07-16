// Subarray Product Less Than K
// sliding window
// if this window's value is less than k , then every contiguous subarrays in window is still less than k
// so , if this window is valid , then "right-left+1" to add the possible answer
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1)return 0;
        int left = 0;
        int right = 0;
        int product = 1;
        int ans = 0;
        while(right<nums.size()){
            product*=nums[right];
            while(product>=k){
                product/=nums[left];
                left++;
            }
            ans+=right-left+1;
            right++;
        }
        return ans;
    }
};