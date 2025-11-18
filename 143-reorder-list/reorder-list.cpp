class Solution {
public:
ListNode* reverselist(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* a=head;
        ListNode* b=reverselist(slow->next);
        slow->next=NULL;
        ListNode* c=new ListNode(100);
        ListNode* tempc=c;
        while(a && b){
            tempc->next=a;
            a=a->next;
            tempc=tempc->next;


            tempc->next=b;
            b=b->next;
            tempc=tempc->next;
        }
        tempc->next=a;
        head=c->next;

    }
};