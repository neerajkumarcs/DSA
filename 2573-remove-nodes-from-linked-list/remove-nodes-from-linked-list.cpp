
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (!head) return NULL;

        stack<ListNode*> s;
        ListNode* temp = head;

        // Step 1: Push all nodes into the stack
        while (temp) {
            s.push(temp);
            temp = temp->next;
        }

        // Step 2: Create a dummy node
        ListNode* newhead = new ListNode(-1);

        // Step 3: Process nodes from right to left
        while (!s.empty()) {
            ListNode* curr = s.top();
            s.pop();
            // First node from the right is always included
            if (newhead->next == NULL) {
                curr->next = NULL;
                newhead->next = curr;
            }
            // Include curr if its value is >= the current largest
            else if (curr->val >= newhead->next->val) {
                curr->next = newhead->next;
                newhead->next = curr;
            }
        }

        return newhead->next;
    }
};
