// 1->2->3
// need a pointer to the 1 and 3 , and we set 1 -> next = 3 , so we can skip the element 2


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp=head;
        int l = 0;
        while(tmp){
            tmp = tmp->next;
            l++;
        }
        if(n==l) return head->next;
        n = l-n;
        ListNode* t = head;
        for(int i=0;i<n-1;i++){
            t = t->next;
        }
        t->next = t->next->next;
        return head;
    }
};