
class Solution {
public:
ListNode* merge(ListNode* list1, ListNode* list2) {
    ListNode* tempA=list1;
        ListNode* tempB=list2;
        ListNode* list3=new ListNode(100);
        ListNode* tempC=list3;
        while(tempA!=NULL && tempB!=NULL){
            if(tempA->val<=tempB->val){
                tempC->next=tempA;
                tempC=tempA;
                tempA=tempA->next;
            }
            else{
                tempC->next=tempB;
                tempC=tempB;
                tempB=tempB->next;
            }
        }
            if(tempA==NULL){
                tempC->next=tempB;
            }
            else{
                tempC->next=tempA;
            }
        return list3->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        while(lists.size()>1){
            ListNode* a=lists[0];
            lists.erase(lists.begin()); // yaha pe main pahle list ko vector se out krke erase kr rha hu
            ListNode* b=lists[0];
            lists.erase(lists.begin());// yaha pe main pahle list ko vector se out krke erase kr rha hu
            ListNode* c=merge(a,b); 
            lists.push_back(c);
        }
        return lists[0];
    }
};