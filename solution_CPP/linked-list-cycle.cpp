// using fast and slow pointer to find if there is a cycle
// 1->2->3 is a cycle => than the pointer will like:1,2,3,1,2,3... infinite cycle
// so the slow pointer and the fast pointer will encounter in some where if this linked list has a cycle

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow) return true;
        }
        return false;
    }
};