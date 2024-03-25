
// to find the element that is exist in nums1 and nums2 => common element
// then to compress the nums1 and nums2 , because repeat element won't gives diffenent element
// so the repeat element is the first element that should be removed
// if the repeat elements are removed , then we need to remove the common=>element
// because the common element is removed from nums1 , it still has a same element in nums2

class Solution {
public:
    int maximumSetSize(vector<int>& num1, vector<int>& num2) {
        unordered_set<int> s1(num1.begin(),num1.end());
        unordered_set<int> s2(num2.begin(),num2.end());
        int common = 0;
        for(auto i:s1){
            if(s2.find(i)!=s2.end()) common++;
        }
        int l1=s1.size();
        int l2=s2.size();
        int ans = l1+l2 - common;
        int half = num1.size()/2;
        if(num1.size()-s1.size()<half){
            int tmp = half-(num1.size()-s1.size());
            if(tmp>common){
                ans=ans-(tmp-common);
                common=0;
            }
            else{
                common-=tmp;
            }
        }
        if(num2.size()-s2.size()<half){
            int tmp = half-(num2.size()-s2.size());
            if(tmp>common){
                ans=ans-(tmp-common);
            }
            else{
                common-=tmp;
            }
        }
        return ans;
    }
};