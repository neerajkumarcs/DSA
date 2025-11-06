class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode *pre=NULL, *curr=head, *nxt=head;
        while(curr!=NULL){
            nxt=curr->next;
            curr->next=pre;
            pre=curr;
            curr=nxt;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
       ListNode *c=new ListNode(100);
       ListNode *tempc=c;
       ListNode *temp=head;
       while(temp){ // creating copy of existing node 
        ListNode *t= new ListNode(temp->val);
        tempc->next=t;
        temp=temp->next;
        tempc=tempc->next;
       } // copy has created 
       c=c->next;
       // Now making a function which used to reverse the copied list
       c=reverse(c);
       while(head!=NULL){
        if(head->val!=c->val) return false;
        c=c->next;
        head=head->next;
       }
       return true;
    }
};