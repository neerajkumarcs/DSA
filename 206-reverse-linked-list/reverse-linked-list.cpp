class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      // iterated method without use of recurssion
      ListNode *pre=NULL, *curr=head,*nxt=head;
      while(curr){
        nxt=curr->next;
        curr->next=pre;
        pre=curr;
        curr=nxt;
      }  
      return pre;
    }
};