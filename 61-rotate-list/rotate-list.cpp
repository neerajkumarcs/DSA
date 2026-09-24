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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        int len=0;
        ListNode* temp=head;
        ListNode* tail;
        while(temp){
            if(temp->next==NULL) tail=temp;
            temp=temp->next;
            len++;
        }
        k=k%len;
        if(k==0) return head;
        temp=head;
        ListNode* b=head;
        while(k){
            b=b->next;
            k--;
        }
        while(b->next){
            temp=temp->next;
            b=b->next;
        }
        b->next=head;
        ListNode* newhead=temp->next;
        temp->next=NULL;
        return newhead;
    }
};