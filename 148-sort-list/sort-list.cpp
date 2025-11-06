class Solution {
public:
ListNode* mergelist(ListNode* list1, ListNode* list2) {
    ListNode* tempA=list1;
        ListNode* tempB=list2;
        ListNode* list3=new ListNode(100);
        ListNode* tempC=list3;
        while(tempA!=NULL && tempB!=NULL){
            if(tempA->val<=tempB->val){
                tempC->next=tempA;
                tempC=tempA;
                tempA=tempA->next;
            }
            else{
                tempC->next=tempB;
                tempC=tempB;
                tempB=tempB->next;
            }
        }
            if(tempA==NULL){
                tempC->next=tempB;
            }
            else{
                tempC->next=tempA;
            }
        return list3->next;
    }
    ListNode* sortList(ListNode* head) {
        // basecase 
        if(head==NULL || head->next==NULL) return head;
        // to find left middle of linklist
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        }
        // now slow at left of linklist
        ListNode* a=head;
        ListNode* b=slow->next;
        slow->next=NULL;
        a=sortList(a);
        b=sortList(b);
        ListNode* c=mergelist(a,b);
        return c;
    }
};