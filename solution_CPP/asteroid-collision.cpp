// if we enconter the negative value , we need to compare the negative value and the top element in the stack


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> tmp;
        vector<int> ans;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]<0){
                bool survive = true;
                while(!tmp.empty()){
                    if(abs(asteroids[i])<tmp.top()){
                        survive = false;
                        break;
                    }
                    else if(abs(asteroids[i])==tmp.top()){
                        survive = false;
                        tmp.pop();
                        break;
                    }
                    else tmp.pop();
                }
                if(survive) ans.push_back(asteroids[i]);
            }
            else{
                tmp.push(asteroids[i]);
            }
        }
        vector<int> sp;
        while(!tmp.empty()){
            sp.push_back(tmp.top());
            tmp.pop();
        }
        reverse(sp.begin(),sp.end());
        for(auto i:sp){
            ans.push_back(i);
        }
        return ans;
    }
};