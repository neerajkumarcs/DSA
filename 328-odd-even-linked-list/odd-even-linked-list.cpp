class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
       ListNode* temp=head;
       ListNode* a=new ListNode(100);
       ListNode* tempa=a;
       ListNode* b=new ListNode(100);
       ListNode* tempb=b;
       int n=0; 
       while(temp){
        if(n%2==0){
            tempa->next=temp;
            tempa=tempa->next;
            temp=temp->next;
           tempa->next=nullptr;
        }
        else {
            tempb->next=temp;
            tempb=tempb->next;
            temp=temp->next;
            tempb->next=nullptr;
        }
        n++;
       } 
       tempa->next=b->next;
       return a->next;
    }
};