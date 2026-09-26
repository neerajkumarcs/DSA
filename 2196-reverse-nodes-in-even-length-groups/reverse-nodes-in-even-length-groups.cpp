class Solution {
public:
    ListNode* rev(ListNode* head) {
        ListNode *pre = NULL;
        ListNode *curr = head;

        while (curr) {
            ListNode* Next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = Next;
        }

        return pre;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (head == NULL || left == right)
            return head;

        // Dummy node helps when left = 1
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // prev points to node just before left
        ListNode* prev = dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // slow = first node of the part to reverse
        ListNode* slow = prev->next;

        // Find the node just after right
        ListNode* fast = slow;
        for (int i = left; i < right; i++) {
            fast = fast->next;
        }

        ListNode* after = fast->next;

        // Disconnect the part
        fast->next = NULL;

        // Reverse [left, right]
        ListNode* newhead = rev(slow);

        // Connect reversed part
        prev->next = newhead;
        slow->next = after;

        return dummy->next;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
    ListNode* temp=head;
    int gap=1;
    while(temp && temp->next){
        int rem=0;
        ListNode* t=temp->next;
        for(int i=1; i<=gap+1 && t!=NULL; i++){
            t=t->next;
            rem++;
        }
        if(rem<gap+1) gap=rem-1;
        if(gap%2!=0) reverseBetween(temp,2,gap+2);
        gap++;
        for(int i=1;temp!=NULL &&  i<=gap; i++){
            temp=temp->next;
        }
    }
    return head;
    
    }
};