// detect the operation , if we detected it , we should carclate the number using the top of the two element


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                int a=num.top();
                num.pop();
                int b=num.top();
                num.pop();
                num.push(a+b);
            }
            else if(tokens[i]=="-"){
                int a=num.top();
                num.pop();
                int b=num.top();
                num.pop();
                num.push(b-a);
            }
            else if(tokens[i]=="*"){
                int a=num.top();
                num.pop();
                int b=num.top();
                num.pop();
                num.push(a*b);
            }
            else if(tokens[i]=="/"){
                int a=num.top();
                num.pop();
                int b=num.top();
                num.pop();
                num.push(b/a);
            }
            else{
                num.push(stoi(tokens[i]));
            }
        }
        return num.top();
    }
};