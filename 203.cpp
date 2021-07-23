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
        if(head == NULL)return NULL;
        ListNode* prev = head;
        while(head && head->val == val){
            ListNode* temp = head;
            head = head->next;
            delete(temp);
        }
        
        if(head == NULL || head->next == NULL)return head;
        
        prev = head;
        ListNode* curr = head->next;
        
        while(prev && curr){
            if(curr->val == val){
                ListNode *temp = curr;
                prev->next = curr->next;
                delete(temp);
            }else{
                prev = curr;
            }
            curr = prev->next;
        }
        return head;
    }
};
