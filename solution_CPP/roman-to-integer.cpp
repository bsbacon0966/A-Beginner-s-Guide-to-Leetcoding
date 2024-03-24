//Record the relationship between Roman and number

// notifying that if the right Roman is greater than left， then this number is combination need to handle 

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> hp{
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
        };
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(hp[s[i]]<hp[s[i+1]]){
                ans-=hp[s[i]];
            }
            else{
                ans+=hp[s[i]];
            }
        }
        return ans;
    }
};