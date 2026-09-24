class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* tempa = head;
        ListNode* tempb = head->next;

        while(tempb) {

            while(tempb != NULL && tempa->val == tempb->val) {
                tempb = tempb->next;
            }

            tempa->next = tempb;
            tempa=tempb;
            if(tempb != NULL)
                tempb = tempb->next;
        }

        return head;
    }
};