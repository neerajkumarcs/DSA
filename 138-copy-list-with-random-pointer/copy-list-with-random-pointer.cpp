/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        // step-> create a new list without random pointer
        Node* dummy=new Node(0);
        Node* tempC=dummy;
        Node* temp=head;
        while(temp){
            Node* a=new Node(temp->val);
            tempC->next=a;
            temp=temp->next;
            tempC=a;
        }
        Node* b=dummy->next;
        Node* a=head;
        Node* tempa=a;
        Node* tempb=b;
        // step 2-> To make a map of <originalnode,dummynode>
        unordered_map<Node*, Node*>m;
        while(tempa){
            m[tempa]=tempb;
            tempa=tempa->next;
            tempb=tempb->next;
        }
        // step 3-> now connect randrom pointers of dummy node with help of map
        for(auto x : m){
            Node* o =x.first;
            Node* d= x.second;
           if(o->random){
            Node* drandom=m[o->random];
            d->random=drandom;
           }
        }
        return b;
    }
};