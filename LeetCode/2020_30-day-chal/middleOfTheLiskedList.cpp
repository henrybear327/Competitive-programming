/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* first = head, *second = head;
        
        while(first != NULL) {
            if(second->next == NULL)
                return first;
            else if(second->next->next == NULL) {
                first = first->next;
                return first;
            } 
            
            second = second->next->next;
            first = first->next;
        }
        
        return first;
    }
};
