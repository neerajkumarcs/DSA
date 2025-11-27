class MinStack {
public:
    stack<long long> st;
    long long mn;
    MinStack() {
        mn=LLONG_MAX;
    }
    
    void push(int val) {
        if(st.size()==0) {
            mn=val;
            st.push((long long)val);
        }
        else if(val>=mn){
            st.push((long long)val);
        }
        else {
            st.push((long long)(2LL*val - mn));   // FIX 1
            mn=val;
        }
    }
    
    void pop() {
       if(st.top()>= mn){
        st.pop();
       } 
       else {
        long long oldmin = 2LL*mn - st.top();     // FIX 2
        mn=oldmin;
        st.pop();
       }
    }
    
    int top() {
       if(st.top()>=mn) return (int)st.top();
       else return (int)mn;                       // FIX 3
    }
    
    int getMin() {
        return (int)mn;
    }
};
