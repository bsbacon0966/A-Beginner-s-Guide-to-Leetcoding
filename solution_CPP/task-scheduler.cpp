621

// using queue to schedule the elements to implement
// if cycle time is 2 => queue open 3 space
// AAABBB => queue[AB] => implement A and B and idle and idle(if cycle time is 3)
// ABCDAB => queue[ABCD] => implement A and B (if cycle time is 1) => queue[CDAB] =>implement C and D =>queue[AB] 
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<int,int> mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]-'a']++;
        }
        queue<char> list;
        for(auto i:mp){
            if(i.second>0){
                list.push(i.first);
                mp[i.first]--;
            }
        }
        int time = 0;
        while(!list.empty()){
            int cycle = n+1;
            while(cycle&&!list.empty()){
                list.pop();
                time++;
                cycle--;
            }
            for(auto i:mp){
                if(i.second>0){
                    list.push(i.first);
                    mp[i.first]--;
                }
            }
            if(!list.empty()) time+=cycle;
        }
        return time;
    }
};