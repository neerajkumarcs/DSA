class Solution {
public:
    int largestarea(vector<int>& heights){
        int n=heights.size();
        int ans=0;
        vector<int>nsi(n);
        vector<int> psi(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            nsi[i]=st.empty()? n: st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            psi[i]=st.empty()? -1: st.top();
            st.push(i);
        }
        for(int i=0; i<n; i++){
            int width=nsi[i]-psi[i]-1;
            ans=max(ans,heights[i]*width);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
    //if(matrix.empty() || matrix[0].empty())  return 0;
    int m=matrix.size();
    int n=matrix[0].size();
    int ans=0;
    vector<int> heights(n,0);
    for(int i=0; i<m ; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j]=='1') heights[j]++;
            else heights[j]=0;
        }
        ans=max(ans,largestarea(heights));
    }  

    return ans;
    }
};