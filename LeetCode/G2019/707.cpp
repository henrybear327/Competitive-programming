struct Node {
    int val;
    Node *next;

    Node(int val) : val(val), next(NULL) {}
};

class MyLinkedList
{
private:
    Node *head, *tail;

public:
    /** Initialize your data structure here. */
    MyLinkedList()
    {
        head = tail = NULL;
    }

    /** Get the value of the index-th node in the linked list. If the index is
     * invalid, return -1. */
    int get(int index)
    {
        Node *cur = head;
        for (int i = 0; i < index; i++) {
            if (cur == NULL)
                return -1;
            cur = cur->next;
        }
        return cur == NULL ? -1 : cur->val;
    }

    /** Add a node of value val before the first element of the linked list. After
     * the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (tail == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    /** Add a node of value val before the index-th node in the linked list. If
     * index equals to the length of linked list, the node will be appended to the
     * end of linked list. If index is greater than the length, the node will not
     * be inserted. */
    void addAtIndex(int index, int val)
    {
        int i = 0;
        Node *cur = head, *prev = NULL;
        while (cur != NULL) {
            if (i == index) {
                if (cur == NULL) {
                    // insert head
                    addAtHead(val);
                } else {
                    // insert body
                    Node *newNode = new Node(val);
                    newNode->next = prev->next;
                    prev->next = newNode;

                    if (newNode->next == NULL)
                        tail = newNode;
                }
                return;
            }

            prev = cur;
            cur = cur->next;
            i++;
        }

        if (cur == NULL && i == index) {
            // insert tail
            addAtTail(val);
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        int i = 0;
        Node *cur = head, *prev = NULL;
        while (cur != NULL) {
            if (i == index) {
                prev->next = cur->next;
                if (prev == NULL)
                    head = cur->next;
                if (tail == cur)
                    tail = prev;

                delete cur;
                return;
            }
            prev = cur;
            cur = cur->next;
            i++;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
