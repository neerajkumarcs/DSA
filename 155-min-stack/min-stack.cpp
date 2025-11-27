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
            st.push((long long)(2LL*val - mn));  
            mn=val;
        }
    }
    
    void pop() {
       if(st.top()>= mn){
        st.pop();
       } 
       else {
        long long oldmin = 2LL*mn - st.top();    
        mn=oldmin;
        st.pop();
       }
    }
    
    int top() {
       if(st.top()>=mn) return (int)st.top();
       else return mn;                       
    }
    
    int getMin() {
        return mn;
    }
};
