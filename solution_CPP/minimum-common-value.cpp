// if nums1 element is greater than nums2 element , them we need to believe nums2 might has the element in it , so push the num2 pointer
// otherwise , we need to push the num1 pointer to find the element might equal to num2 element

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int up = 0 ;
        int down = 0;
        while(up<nums1.size()&&down<nums2.size()){
            if(nums1[up]==nums2[down]) return nums1[up];
            else if(nums1[up]>nums2[down]) down++;
            else up++;
        }
        return -1;
    }
};