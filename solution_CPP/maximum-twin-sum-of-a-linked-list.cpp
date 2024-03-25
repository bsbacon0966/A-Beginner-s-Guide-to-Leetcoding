// we need to run the whole linkedlist to know the size of the linkedlist
// using vector to store the every element of the linkedlist
// and using middle to find the max combination

class Solution {
public:
    int pairSum(ListNode* head) {
        int count=0;
        ListNode* run=head;
        vector<int> tmp;
        while(run){
            tmp.push_back(run->val);
            run=run->next;
        }
        int middle=tmp.size()/2;
        int max=0;
        for(int i=0;i<middle;i++){
            tmp[i]+=tmp[tmp.size()-1-i];
            if(tmp[i]>max) max=tmp[i];
        }
        return max;
    }
};