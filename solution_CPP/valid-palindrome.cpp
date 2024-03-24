// tidy the string
// left pointer point to the leftmost element , right pointer point to the rightmost element
// if left pointer element is same to the right pointer element , than it is Palindrome
// doing pointer until left pointer equal to right pointer 

class Solution {
public:
    bool isPalindrome(string s) {
        vector<int> a;
        for(auto x:s){
            if(isalnum(x)){//確認是否為數字或字母
                a.push_back(tolower(x));
            }
        }
        int start=0;
        int tail=a.size()-1;
        while(start<=tail){
            if(a[start]!=a[tail]){
                return false;
            }
            start++;
            tail--;
        }
        return true;
    }
};