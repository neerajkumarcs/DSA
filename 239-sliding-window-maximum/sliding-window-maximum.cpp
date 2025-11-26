class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();            
        if (k == 1) return arr;
        if (k > n) k = n;

        vector<int> ngi(n);     
        stack<int> st;

        // step1-> first to find next greater index
        ngi[n-1] = n;
        st.push(n-1);
        for (int i = n-2; i >= 0; i--) {
            while (st.size()>0 && arr[st.top()] <= arr[i]) { 
                st.pop();
            }
            if (st.size()==0) ngi[i] = n;
            else ngi[i] = st.top();
            st.push(i);
        }

        // step2-> now traveling in window and find next greatest element
        vector<int> ans;
        int j = 0;
        for (int i = 0; i < n - k + 1; i++) {
            if (j < i) j = i;
            int mx = arr[j];
            while (j < i + k) {
                mx = arr[j];
                if (ngi[j] >= i + k) break;
                j = ngi[j];
            }
            ans.push_back(mx);
        }
        return ans;
    }
};
