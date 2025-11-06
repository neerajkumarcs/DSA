class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* tempA=new ListNode(100);
        ListNode* tempB=new ListNode(100);
        ListNode* tl=tempA;
        ListNode* th=tempB;
        ListNode* temp=head;
        while(temp!=NULL){
            if(temp->val< x){
                tl->next=temp;
                tl=temp;
                temp=temp->next;
                tl->next=NULL;
            }
            else {
                th->next=temp;
                th=temp;
                temp=temp->next;
                th->next=NULL;

            }
        }
        tl->next=tempB->next;
        th->next=NULL;
        return tempA->next;
    }
};