//649
// Remember, R or D's goal is to vote off people from the other team, so in addition to remembering which team you are on, also remember to vote +1 if someone is from your team, if you voted to remove someone, that means there will be an open slot, so you need to see which team the next person is on. 
// He would like to be a circular queue 
//RRDD -> RR will get two times to Ban the senator's right , so we need to judge how many same camp
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<char> q;
        int r=0;
        int d = 0;
        for(int i=0;i<senate.length();i++){
            q.push(senate[i]);
            if(senate[i]=='R')r++;
            else d++;
        }
        int judge = 0;
        while(r!=0&&d!=0){
            if(judge==0){
                if(q.front()=='R'){
                    judge=1;
                }
                else judge = -1;
                q.push(q.front());
                q.pop();
            }
            else if(judge>0){
                if(q.front()=='D'){
                    d--;
                    q.pop();
                    judge--;
                }
                else{
                    judge++;
                    q.push(q.front());
                    q.pop();
                }
            }
            else if(judge<0){
                if(q.front()=='R'){
                    r--;
                    q.pop();
                    judge++;
                }
                else{
                    judge--;
                    q.push(q.front());
                    q.pop();
                }
            }
        }
        if(r>0)return "Radiant";
        else return "Dire";
    }
};