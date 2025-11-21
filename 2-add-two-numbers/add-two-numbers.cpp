class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum=new ListNode(100);
        ListNode* temp=sum;
        int carry=0;
        while(l1 || l2 || carry){
            int a=0, b=0;
            if(l1!=NULL){
             a=l1->val;
             l1=l1->next;
            }
            if(l2!=NULL){
             b=l2->val;
             l2=l2->next;
            }
            int n=a+b+carry;
            carry=n/10;
            int digit=n%10;
            temp->next=new ListNode(digit);
            temp=temp->next;
            
        }
        return sum->next;
    }
};