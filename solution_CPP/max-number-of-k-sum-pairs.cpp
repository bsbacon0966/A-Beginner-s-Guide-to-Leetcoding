// sort the vector 
// if left pointer element and right pointer element sum together equal to k , than ans++
// each elements are smaller than right , bigger than right ,   
// so, if bigger than k , then right pointer moves (because right element is too big, go ledt will get more smaller element)
// else if smaller than k , then left pointer moves (because left element is too small , go right will get more bigger element)

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
       int left=0;
       int right=nums.size()-1;
       int count=0;
       while(left<right){
           if(nums[left]+nums[right]==k) {
              count++;
              left++;
              right--;
           }
           else if(nums[left]+nums[right]>k) right--;
           else left++;
       } 
       return count;
    }
};