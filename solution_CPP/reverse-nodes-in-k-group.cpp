//25
// 1->2->3->4->5 => []->[]->3->4->5 stack = [1,2] => 2->1->3->4->5
// 2->1->3->4->5 => 2->1->[]->[]->5 stack = [3,4] => 2->1->4->3->5
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL|| k==1) return head;
        ListNode* ans_head = head;
        stack<int> st;
        while(head){
            ListNode* pre = ans_head;
            for(int i=0;i<k;i++){
                if(pre == NULL) return head;
                st.push(pre->val);
                pre = pre->next;
            }
            for(int i=0;i<k;i++){
                ans_head->val = st.top();
                st.pop();
                ans_head = ans_head->next;
            }
        }
        return ans_head;
    }
};