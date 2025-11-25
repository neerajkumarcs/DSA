class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        // approach last greatest element 
        int n=heights.size();
        vector<int> ans(n);
        stack<int>st;
        // step-> usig next greatst elemen approach
        ans[n-1]=0;
        st.push(heights[n-1]);
        for(int i=n-2; i>=0; i--){
            int count=0;
            while(st.size()>0 && heights[i]>=st.top()){
                st.pop();
                count++;
            }
            if(st.size()!=0) count++;
            ans[i]=count;
            st.push(heights[i]);
        }
        return ans;
    }
};