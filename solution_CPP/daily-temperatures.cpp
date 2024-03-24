// using index to remember the temperture and using the index to calculate the answer
// 32 31 30 33 => 33 higher than 30 and 31，so the 30 has answer = 1 , 31 has answer = 2

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
        stack<int> tmp;
        vector<int> ans(tem.size(),0);
        for(int i=0;i<tem.size();i++){
            if(tmp.empty()){
                tmp.push(i);
                continue;
            }
            while(!tmp.empty()&&tem[i]>tem[tmp.top()]){
                ans[tmp.top()] = i-tmp.top();
                tmp.pop();
            }
            tmp.push(i);
        }
        return ans;
    }
};