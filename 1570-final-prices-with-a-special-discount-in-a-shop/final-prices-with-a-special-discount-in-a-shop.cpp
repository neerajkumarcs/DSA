class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;

        for(int i = prices.size() - 1; i >= 0; i--) {

            int val = prices[i];

            while(!st.empty() && st.top() > val) {
                st.pop();
            }

            if(!st.empty()) {
                prices[i] = val - st.top();
            }

            st.push(val);
        }

        return prices;
    }
};