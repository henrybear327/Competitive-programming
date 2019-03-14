/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> mapping;

        Node *newHead = NULL;
        Node *cur = head, *prev = NULL;
        while (cur != NULL) {
            Node *newNode = new Node{cur->val, NULL, NULL};
            if (newHead == NULL)
                newHead = newNode;
            mapping[cur] = newNode;
            if (prev != NULL) {
                prev->next = newNode;
            }
            prev = newNode;

            cur = cur->next;
        }

        cur = head;
        while (cur != NULL) {
            mapping[cur]->random = mapping[cur->random];

            cur = cur->next;
        }

        return newHead;
    }
};
