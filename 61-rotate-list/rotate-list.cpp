  
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        int len=0;
        ListNode* temp=head;
        ListNode* tail;
        while(temp!=NULL){
            if(temp->next==NULL) tail=temp; // yaha maine tail ko last node pe setup kiya
            temp=temp->next;
            len++;
        }
        temp=head; // temp ko dubara initialise kiya
        k=k%len; // if k is very large used this technique to reduce no. of cycles
        if(k==0) return head;
        for(int i=1; i<len-k; i++){ // yaha mei temp ko just ek node pahle setup kiya jaha se mere ko rotation strt krni hai
            temp=temp->next;
        }
        tail->next=head; // last point to first 
        head=temp->next; //  first point at kth node from last 
        temp->next=NULL; // after rotation break the circular link list
        return head;
    }
};
