
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* tempA = list1;
        ListNode* tempB = list2;
        ListNode* first;
        ListNode* second;
        int lenA = 0;

        while (tempA != NULL) {
            if (lenA ==a-1) {
               first=tempA;
            }
            if (lenA == b) {
                second=tempA->next;
            }
            lenA++;
            tempA = tempA->next;
        }
        first->next=list2;
        while(tempB->next!=NULL){
            tempB=tempB->next;
        }
        tempB->next=second;
        return list1;
        
    }
};
