class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (head->next == NULL) return head;

        ListNode* temp = head;
        ListNode* kf = nullptr;
        ListNode* kl = head;
        int len = 0;

        // Find length and kth from start
        while (temp != NULL) {
            len++;
            if (len == k) kf = temp;
            temp = temp->next;
        }

        //Move kl to kth from end
        for (int i = 0; i < len - k; i++) {
            kl = kl->next;
        }

        // Step 3: Swap values
        int t = kf->val;
        kf->val = kl->val;
        kl->val = t;

        return head;
    }
};
