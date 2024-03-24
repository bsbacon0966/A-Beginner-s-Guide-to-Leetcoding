// using stack to record the element
// if enconter the * then pop the stack element on the top
// [stack:abcc] and next element is * =>[stack:abc] pop c int the stack 

class Solution {
public:
    string removeStars(string s) {
        stack<char> ans;
        for(int i=0;i<s.length();i++){
            if(s[i]=='*'){
                ans.pop();
            }
            else{
                ans.push(s[i]);
            }
        }
        string a;
        while(!ans.empty()){
            a+=ans.top();
            ans.pop();
        }
        reverse(a.begin(),a.end());
        return a;
    }
};