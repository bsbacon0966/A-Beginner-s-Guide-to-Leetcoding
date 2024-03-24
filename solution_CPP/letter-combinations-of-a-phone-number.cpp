// "go" and "back" to find all possible combinations
class Solution {
private:
    const string letter[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    vector<string> ans;
    string tmp;
    void backtracking(string digit,int index){
        if(index==digit.size()){
            ans.push_back(tmp);
            return;
        }
        string now_number_represent_letter=letter[digit[index]-'0'];
        for(int i=0;i<now_number_represent_letter.length();i++){
            tmp+=now_number_represent_letter[i];
            backtracking(digit,index+1);
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return {};
        backtracking(digits,0);
        return ans;
    }
};