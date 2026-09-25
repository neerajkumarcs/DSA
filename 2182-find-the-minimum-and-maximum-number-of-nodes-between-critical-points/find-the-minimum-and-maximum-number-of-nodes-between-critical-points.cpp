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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    int n=1;
    ListNode* temp=head;
    while(temp){
        temp=temp->next;
        n++;
    }
    ListNode* a=head;
    ListNode* b=head->next;
    ListNode* c=head->next->next;
    if(c==NULL) return {-1,-1};
    int idx=1;
    temp=head;
    int fidx=-1,sidx=-1; // for finding maximum distaces between critical points 
    int f=-1,s=-1; // for finding minimum distance between critical points
    int mind=INT_MAX;
    while(c){
        if((b->val>a->val && b->val>c->val) ||( b->val<a->val && b->val<c->val)){
            // for max 
            if(fidx==-1) fidx=idx;
            else sidx=idx;

            // for min
            f=s;
            s=idx;
            if(f!=-1){
                int d=s-f;
                mind=min(mind,d);
            }
        }
        a=a->next;
        b=b->next;
        c=c->next;
        idx++;
    }
    if(sidx==-1) return {-1,-1};
    int maxd=sidx-fidx;
    return {mind,maxd};

    }
};