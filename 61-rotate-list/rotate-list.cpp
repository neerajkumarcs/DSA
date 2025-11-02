  
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        int len=0;
        ListNode* temp=head;
        ListNode* tail;
        while(temp!=NULL){
            if(temp->next==NULL) tail=temp;
            temp=temp->next;
            len++;
        }
        ListNode *t=head;
        k=k%len;
        if(k==0) return head;
        for(int i=1; i<len-k; i++){
            t=t->next;
        }
        tail->next=head;
        head=t->next;
        t->next=NULL;
        return head;
    }
};
