/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    //  int len=0;
    //  ListNode* temp=head;
    //  while(temp!=NULL){
    //     temp=temp->next;
    //     len++;
    //  }
    //  if(n==len){
    //     head=head->next;
    //     return head;
    //  }
    //  int m=(len-n); // this is the formula to find just before node of  nth from end
    //  temp=head;
    //  for(int i=0; i<m-1;i++){
    //     temp=temp->next;
    //  }
    //  temp->next=temp->next->next;
    //  return head;




    // now doing the same question using slow and fast pointers
    ListNode* slow=head;
    ListNode* fast=head;
    for(int i=0;i<=n-1; i++){
        fast=fast->next;
    }
    if(fast==NULL){
        head=head->next;
        return head;
    }
    while(fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=slow->next->next;
     return head;

    }
};