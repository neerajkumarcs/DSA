  class Solution {
public:
    // Full list reverse (helper)
    ListNode* reverselist(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* curr = head;
        ListNode* nxt = nullptr;
        while (curr) {
            nxt = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nxt;
        }
        return pre;
    }

    // 92. Reverse Linked List II (index based)
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* a = nullptr; // node before left
        ListNode* b = nullptr; // left node
        ListNode* c = nullptr; // right node
        ListNode* d = nullptr; // node after right

        ListNode* temp = head;
        int n = 1;

        while (temp != nullptr) {
            if (n == left - 1) a = temp;
            if (n == left)     b = temp;
            if (n == right)    c = temp;
            if (n == right + 1)d = temp;
            temp = temp->next;
            n++;
        }

        if (!b || !c) return head; // safety, though normally given constraints valid hote hain

        if (a) a->next = nullptr;
        c->next = nullptr;

        // reverse middle part [b..c]
        ListNode* newMidHead = reverselist(b);

        if (a) a->next = newMidHead;
        b->next = d; // b ab tail ban chuka hai

        if (a) return head;
        return newMidHead;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroupEnd = &dummy;
        ListNode* curr = head;
        int groupSize = 1;

        while (curr) {
            // group start
            ListNode* groupStart = curr;
            int cnt = 0;

            // current group ki actual length count karo
            while (cnt < groupSize && curr) {
                curr = curr->next;
                cnt++;
            }
            // ab:
            // groupStart = start of group
            // cnt = group length
            // curr = next group ka start

            if (cnt % 2 == 0) {
                // EVEN length group -> reverse karna hai
                ListNode* prev = curr;    // reverse ke baad tail ka next ye hoga
                ListNode* node = groupStart;

                for (int i = 0; i < cnt; ++i) {
                    ListNode* nxt = node->next;
                    node->next = prev;
                    prev = node;
                    node = nxt;
                }

                // prev ab is group ka new head hai
                prevGroupEnd->next = prev;
                // old head (groupStart) ab tail ban gaya
                prevGroupEnd = groupStart;
            } else {
                // ODD length group -> as-is chhodna hai
                prevGroupEnd = groupStart;
                for (int i = 1; i < cnt; ++i) {
                    prevGroupEnd = prevGroupEnd->next;
                }
            }

            groupSize++;
        }

        return dummy.next;
    }
};