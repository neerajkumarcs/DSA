class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == NULL)
            return NULL;

        // Step 1: Create copy nodes
        Node* dummy = new Node(-1);
        Node* tempc = dummy;
        Node* temp = head;

        while (temp) {
            Node* newNode = new Node(temp->val);

            tempc->next = newNode;
            tempc = tempc->next;

            temp = temp->next;
        }

        Node* copyHead = dummy->next;

        // Step 2: Make alternate connections
        // Original -> Copy -> Original -> Copy

        Node* a = head;
        Node* b = copyHead;

        while (a) {

            Node* nextOriginal = a->next;
            Node* nextCopy = b->next;

            a->next = b;
            b->next = nextOriginal;

            a = nextOriginal;
            b = nextCopy;
        }

        // Step 3: Set random pointers

        a = head;

        while (a) {

            Node* copyNode = a->next;

            if (a->random != NULL)
                copyNode->random = a->random->next;

            a = copyNode->next;
        }

        // Step 4: Separate original and copied list

        a = head;
        b = copyHead;

        while (a) {

            a->next = b->next;

            if (b->next != NULL)
                b->next = b->next->next;
            else
                b->next = NULL;

            a = a->next;
            b = b->next;
        }

        return copyHead;
    }
};