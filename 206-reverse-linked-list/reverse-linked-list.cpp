class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      // iterated method without use of recurssion
    //   ListNode *pre=NULL, *curr=head,*nxt=head;
    //   while(curr){
    //     nxt=curr->next;
    //     curr->next=pre;
    //     pre=curr;
    //     curr=nxt;
    //   }  
    //   return pre;



    // now do reverse through recurssion 
    if(head==NULL || head->next==NULL) return head;
    ListNode* newhead=reverseList(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
    }
};