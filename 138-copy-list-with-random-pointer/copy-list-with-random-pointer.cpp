class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr; // added safety

        // step 1: create the deep copy withoud random pointer
        Node* temp = head;
        Node *c = new Node(100);
        Node* tempc = c;
        while (temp) {
            Node* a = new Node(temp->val);
            tempc->next = a;
            temp = temp->next;
            tempc = tempc->next;
        }
        Node* dub = c->next;
        // step 2: merging alternage connections  both old and new lists 
        Node* a = head;
        Node* b = dub;
        Node* merge = new Node(100);
        Node* tempd = merge;
        while (a != nullptr && b != nullptr) {
            Node* nextA = a->next;
            Node* nextB = b->next;

            tempd->next = a;
            tempd = tempd->next;

            tempd->next = b;
            tempd = tempd->next;

            a = nextA;
            b = nextB;
        }
        if (a) tempd->next = a;
        if (b) tempd->next = b;
        merge = merge->next;
        // step 3: assinging random pointers to dublicate 
        Node* t1 = merge;
        while (t1 && t1->next) {
            Node* t2 = t1->next;
            if (t1->random) t2->random = t1->random->next;
            // move to next original node
            t1 = t1->next->next;
        }
        // step 4 separating  the merged node
        t1 = merge; // reset t1 to start of merged list
        Node* newhead = new Node(100);
        Node* final = newhead;
        while (t1 && t1->next) {
            Node* original = t1;
            Node* copy = t1->next;

            final->next = copy;
            final = final->next;

            // restore original next
            original->next = copy->next;

            // advance
            t1 = original->next;
        }
        final->next = nullptr;
        return newhead->next;
    }
};
