/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *cur = head, *prev = NULL;
        while(cur != NULL) {
            if(cur->val == val) {
                if(cur == head)
                    head = cur = head->next;
                else {
                    ListNode* tmp = cur;
                    prev->next = cur->next;
                    cur = cur->next;
                    delete tmp; // don't forget to free!
                }
            } else {
                prev = cur;
                cur = cur->next;   
            }
        }   
        
        return head;
        
//         ListNode* ret = NULL, *cur = NULL;
//         // instead of removing, we only add the ok nodes to the list to return
        
//         while(head != NULL) {
//             if(head->val != val) {
//                 if(ret == NULL)
//                     ret = cur = head;
//                 else {
//                     cur->next = head; 
//                     cur = head;
//                 }
//             }
//             head = head->next;
//         }
//         if(cur != NULL)
//             cur->next = NULL;
        
//         return ret;
    }
};
