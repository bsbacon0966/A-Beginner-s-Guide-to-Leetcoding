// count the  number of 'a' and 'b'
// using left and right to count , left count the difference element('b') , right count the difference element('a')
// because we want most of the 'a' on the left and 'b' on the right

// aaababb  when we count to index = 2 , we get left = 0 and right = 2 (because if we set all of the element are 'b' after index = 2)
// when we count to index = 3 , we get left = 0 and right = 1 (because we set all of the element are 'b' after index = 3)
// when we count to index = 4 , we get left = 1 and right = 0 (because we set all of the element are 'b' after index = 4 and all of the element are 'a' before index = 4)
class Solution {
public:
    int minimumDeletions(string s) {
        int right=0;
        int left=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a') right++;
        }
        if(right==0||right==s.length()) return 0;
        int ans=right;
        for(int i=0;i<s.length();i++){
            if(s[i]=='b'){
                left++;
            }
            else right--;
            ans=min(ans,left+right);
        }
        return ans;
    }
};