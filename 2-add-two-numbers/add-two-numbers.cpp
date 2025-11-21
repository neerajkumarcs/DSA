class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum=new ListNode(100);
        ListNode* temp=sum;
        int carry=0;
        while(l1 || l2 || carry){
            int a=0, b=0;
            if(l1!=NULL){ // check kro list one null toh nhi hua
             a=l1->val;
             l1=l1->next;
            }
            if(l2!=NULL){ // check kro list 2 toh null nhi hua 
             b=l2->val;
             l2=l2->next;
            }
            int n=a+b+carry; // dono list ke values with previous carry ka sum
            carry=n/10;  // caryy for next round
            int digit=n%10; // total sum with removal of first digit 
            temp->next=new ListNode(digit);
            temp=temp->next;
            
        }
        return sum->next;
    }
};
// Note* : this code may fail if total sum of two nodes is in three digit 