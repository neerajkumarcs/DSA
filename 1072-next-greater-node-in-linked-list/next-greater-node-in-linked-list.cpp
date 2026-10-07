class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
    if(!head) return {};
    if(!head->next) return {0};
    vector<int> res;
    stack<int> st;

    // step 1 assiginig value into vector
    while(head){
        res.push_back(head->val);
        head=head->next;
    }  
    // step 2: by using stack create next larger node 
    for(int i=res.size()-1; i>=0; i--){
        int val=res[i];
        while(!st.empty() && st.top()<=val) st.pop();
            if(st.empty()){
                st.push(val);
                res[i]=0;
            }
            else{
                res[i]=st.top();
                st.push(val);
            }
    }
    return res;

    }
};