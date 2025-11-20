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
        ListNode* temp=head;
        int gap=1;
        while(temp  && temp->next){
               if(gap%2!=0) reverseBetween(temp, gap, gap+2);
               for(int i=1; i<=gap; i++){
                temp=temp->next;
               }
               gap++;
        }
        return head;
    }
};