class Solution {
public:
    Node* copyRandomList(Node* head) {
    // previous method
    // step 1-> create a deep copy wihtout random pointer 
    // step 2-> alternate linking 
    // step 3-> mark pointers
    // step 4-> remove connctions

    // now using hashmaps
    Node* dummy=new Node(0);
    Node* tempc=dummy;
    Node* temp=head;
    while(temp){
        Node* a=new Node(temp->val);
        tempc->next=a;
        tempc=tempc->next;
        temp=temp->next;
    }
    Node* b = dummy->next;
    Node* a = head;
    // step 2 : make a map of <original,dublicate> 
    unordered_map<Node*, Node*> m;
    Node* tempa=a;
    Node* tempb=b;
    while(tempa){
        m[tempa]=tempb;
        tempa=tempa->next;
        tempb=tempb->next;
    }
    for(auto x: m){
        Node* o=x.first;
        Node* d=x.second;
        if(o->random!=NULL){
            Node* orandom=o->random;
            Node* drandom=m[o->random];
            d->random=drandom;
        }
    }

    return b;
    }
};