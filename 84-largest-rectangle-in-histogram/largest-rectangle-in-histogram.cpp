class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
     // step -> find next smalllest element 
     int n=heights.size();
     stack<int> st;
     vector<int> nsi(n,0);
     vector<int> psi(n,0);
     for(int i=n-1; i>=0; i-- ){
        while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
        nsi[i]=st.empty()? n:st.top();
        st.push(i);
     }
     while(!st.empty()) st.pop();
     // step 2-> find previous smallest element 
     for(int i=0; i<n; i++){
        while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
        psi[i]=st.empty()? -1:st.top();
        st.push(i);
     }
     // step 3 now calculating the ans 
     int ans=0;
     for(int i=0; i<n; i++){
        int width=nsi[i]-psi[i]-1;
        int lenght=heights[i];
        ans=max(ans,width*lenght);
     }
        return ans;
    }
};