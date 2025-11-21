class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
       ListNode* temp=head;
       ListNode* newhead=new ListNode(-1);
       ListNode* dummy=newhead;
       while(temp && temp->next){
            if(temp->val!=temp->next->val){
                dummy->next=temp;
                dummy=dummy->next;
                temp=temp->next;
            }
            else {
                // skiping for entire duplicate block
                while(temp && temp->next&& temp->val==temp->next->val){
                    temp=temp->next;
                }
                temp=temp->next;
            }
       }
       if(temp){
        dummy->next=temp;
        dummy=dummy->next;
       }
       dummy->next=NULL;
       return newhead->next;
    }
};