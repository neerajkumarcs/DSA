/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp=head;
        while(temp){
            Node* nxt=temp->next;
            if(temp->child!=nullptr){
                Node* c=temp->child;
                temp->child=NULL;
                c=flatten(c);
                temp->next=c;
                c->prev=temp;
                while(c->next!=NULL){
                    c=c->next;
                }
            c->next=nxt;
            if(nxt!=NULL)nxt->prev=c;
            }
            temp=temp->next;
        }
        return head;
    }
};