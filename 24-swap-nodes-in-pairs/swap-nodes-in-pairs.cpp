class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        // dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = dummy;

        while (curr->next != NULL && curr->next->next != NULL) {
            ListNode* first = curr->next;
            ListNode* second = curr->next->next;

            // swapping
            first->next = second->next;
            second->next = first;
            curr->next = second;

            // move current pointer for next swap
            curr = first;
        }

        return dummy->next;
    }
};
