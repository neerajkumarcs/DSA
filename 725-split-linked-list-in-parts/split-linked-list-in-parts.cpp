class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
       // first to calculate the size of list
       ListNode* temp=head;
       int n=0;
       while(temp){
        temp=temp->next;
        n++;
       } 
       // vector 
       vector<ListNode*> ans;
       // now find the partial list size
       temp=head; // reset
       int size=n/k;
       int rem=n%k;
       // breaking the list
       while(temp!=NULL){
        ListNode*c =new ListNode();
        ListNode* tempc=c;
        int s=size;
        if(rem>0){ // in case of unequal division 
            s++;
            rem--;
        }
        for(int i=1;i<=s; i++){
            tempc->next=temp;
            temp=temp->next;
            tempc=tempc->next;
        }
        tempc->next=NULL;
        ans.push_back(c->next);
       }
       // when k is more than lenght of list 
       if(k>n){
        int extra=k-ans.size();
        for(int i=1; i<=extra; i++){
            ans.push_back(NULL);
        }
       }
       return ans;

// total time complexity
// O(n)-> traversal
// O(k)-> again traveral for breaking 
// total=O(n+k)~=O(n)
// space com=O(k)
    }
};