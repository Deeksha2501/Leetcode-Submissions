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
    int getDecimalValue(ListNode* head , int parent_val = 0) {
         head->val += parent_val*2;
        if(head->next == NULL){
            return head->val;
        }
        return getDecimalValue(head->next , head->val);
    }
};