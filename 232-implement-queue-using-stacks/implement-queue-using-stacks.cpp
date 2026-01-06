// // push efficiant approach
// class MyQueue {
// public:
// stack<int> st;
// stack<int> helper;
//     MyQueue() {
        
//     }
    
//     void push(int x) { TC-> O(1)
//         st.push(x);
//     }
    
//     int pop() { // -> O(n)
//         while(st.size()>0){
//          helper.push(st.top());
//          st.pop();
//         }
//         int x=helper.top();
//         helper.pop();
//         while(helper.size()>0){
//            st.push(helper.top());
//            helper.pop();
//         }
//        return x; 
//     }
    
//     int peek() { // front -> O(n)
//     // retreive from bottom
//         while(st.size()>0){
//          helper.push(st.top());
//          st.pop();
//         }
//         int x=helper.top();
//         while(helper.size()>0){
//            st.push(helper.top());
//            helper.pop();
//         }
//        return x; 
//     }
    
//     bool empty() {
//         if(st.size()==0) return true;
//         else return false;
//     }
// };

// POP efficiant approach
// bs push o(n) mei hoga 
class MyQueue {
public:
stack<int> st;
stack<int> helper;
    MyQueue() {
        
    }
    
    void push(int x) { // TC-O(N)
    // push at bottom 
        if(st.size()==0){
            st.push(x);
            return;
        }
       else{
        while(st.size()>0){
            helper.push(st.top());
            st.pop();
        }
        st.push(x);
        while(helper.size()>0){
            st.push(helper.top());
            helper.pop();
        }
       }
    }
    
    int pop() { // -> O(1)
        int x=st.top();
        st.pop();
       return x; 
    }
    
    int peek() { // front -> O(1)
    // retreive from bottom
        return st.top();
    }
    
    bool empty() {
        if(st.size()==0) return true;
        else return false;
    }
};

