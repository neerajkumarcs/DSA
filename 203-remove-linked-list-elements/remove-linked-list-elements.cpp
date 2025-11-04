class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    if(head==NULL) return NULL;
    while(head!=NULL && head->val==val){
        ListNode* todelete=head;
        head=head->next;
        delete(todelete);
    }
    // If list became empty after removing leading nodes
        if (head == NULL) return NULL;

    ListNode* pre=head;
    ListNode* temp=head->next;
    while(temp!=NULL){
        if(temp->val==val){
            pre->next=temp->next;
            delete(temp);
            temp=pre->next;
        }
        else{
            pre=temp;
            temp=temp->next;
        }
    }
    return head;
    }
};