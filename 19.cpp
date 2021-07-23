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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL)return NULL;
        ListNode* init = head;
        ListNode* curr = NULL;
        int t = n-1;
        while(t--){
            init = init->next;
        }
        
        while(init != NULL && init->next != NULL){
            if(curr == NULL)
                curr = head;
            else
                curr = curr->next;
            init = init->next;
        }
        if(curr == NULL){
            head = head->next;
            return head;
        }
        ListNode* d = curr->next;
        curr->next = curr->next->next;
        delete(d);
        return head;
    }
};