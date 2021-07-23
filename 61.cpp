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
    
    int getLength(ListNode* head){
        if(head == NULL)return 0;
        return 1 + getLength(head->next);
    }
    
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n = getLength(head);
        if(n == 0 || n == 1 )return head;
        k = k%n;
        if(k == 0 || k == n)return head;
        
        int kk = k;
        
        ListNode* tail = head;
        
        while(k--){
            tail = tail->next;
        }
        
        ListNode* curr = head;
        while(tail->next){
            tail = tail->next;
            curr = curr->next;
        }
        
        ListNode *res = curr->next;
        curr->next = NULL;
        tail->next = head;
        return res;
    }
};