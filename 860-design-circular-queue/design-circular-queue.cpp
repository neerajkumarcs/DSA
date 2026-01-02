class MyCircularQueue {
public:
    int f,b,s,c;
    vector<int>arr;
    MyCircularQueue(int k) {
        f=0;
        b=0; 
        s=0;
        c=k;
        vector<int> v(k);
        arr=v; 
    }
    
    bool enQueue(int value) { // push data at back/ rear 
        if(s==c) return false;
        else {
            if(b==c) b=0;
            arr[b]=value;
            b++;
            s++;
            return true;
        }
    }
    
    bool deQueue() { // Reoving element from front end
        if(s==0) return false;
        else {
           f++;
           if(f==c) f=0;
           s--; 
           return true;
        }
    }
    
    int Front() {
        if(s==0) return -1;
        else return arr[f];
    }
    
    int Rear() {
        if(s==0) return -1;
        if(b==0) return arr[c-1];
        else return arr[b-1];
    }
    
    bool isEmpty() {
        if(s==0) return true;
        else return false;
    }
    
    bool isFull() {
        if(s==c) return true;
        else return false ;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */