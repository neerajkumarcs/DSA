class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
    ListNode* dummy= new ListNode(0);
    ListNode* temp=dummy;
    ListNode* curr=head;
    ListNode* nxt=NULL;
    while(curr){
        nxt=curr->next;
        temp=dummy;
        while(temp->next && temp->next-> val < curr->val) temp=temp->next;
        curr->next=temp->next;
        temp->next=curr;
        curr=nxt;
    }
    return dummy->next;
    }
};