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
     ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode *ans = res;
        while(l1 && l2){
            if(l1->val < l2->val){
                res->next = l1;
                l1 = l1->next;
            }
            else{
                res->next = l2;
                l2 = l2->next;
            }
            res = res->next;
        }
        
        if(l1){
            res->next = l1;     
        }
        if(l2){
            res->next = l2;
        }
        return ans->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL|| head->next == NULL)return head;
        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* middle = slow;
        ListNode* nextt = middle->next;
        middle->next = NULL;
        
        head = sortList(head);
        nextt = sortList(nextt);
        head = merge(head , nextt);
        return head;
        
    }
    
    
};