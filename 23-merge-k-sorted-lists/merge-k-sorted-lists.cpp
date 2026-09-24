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
    ListNode* merge(ListNode* a,ListNode* b){
        ListNode* tempa=a;
        ListNode* tempb=b;
        ListNode* c=new ListNode(-1);
        ListNode* temp=c;
        while(tempa && tempb){
            if(tempa->val<tempb->val){
            temp->next=tempa;
            temp=tempa;
            tempa=tempa->next;
            }
            else{
            temp->next=tempb;
            temp=tempb;
            tempb=tempb->next;
            }
        }
        if(tempa==NULL) temp->next=tempb;
        else temp->next=tempa;
        return c->next;

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size()==0) return NULL;
    while(lists.size()>1){
        ListNode* a= lists[0];
        lists.erase(lists.begin());
        ListNode* b=lists[0];
        lists.erase(lists.begin());
        ListNode* c=merge(a,b);
        lists.push_back(c);
        
    }
    return lists[0];

    }
};