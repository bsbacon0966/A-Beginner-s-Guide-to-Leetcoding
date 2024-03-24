// 1->2->3->4->5  => 1->[]->[]->[]->5 stack = [2,3,4]
// stack = [2,3,4] => 1->4->3->2->5 

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* tmp = head;
        for(int i=1;i<left;i++){
            tmp = tmp->next;
        }
        stack<int> num_store;
        ListNode* pre = tmp;
        for(int i=0;i<=right-left;i++){
            num_store.push(pre->val);
            pre = pre->next;
        }
        for(int i=0;i<=right-left;i++){
            tmp->val = num_store.top();
            num_store.pop();
            tmp = tmp->next;
        }
        return head;
    }
};