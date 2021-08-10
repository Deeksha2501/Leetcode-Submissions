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
    bool isPalindrome(ListNode* head) {
        if(head ==NULL || head->next == NULL)return true;
        ListNode* slow = head;
        ListNode* fast = head;
        stack<int> s;
        while(fast != NULL && fast->next != NULL){
            s.push(slow->val);
            cout<<"\ninserting = "<<slow->val;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast != NULL)slow = slow->next;
        
        while(slow != NULL){
            if(slow->val != s.top())return false;
            s.pop();
            slow = slow->next;
        }
        return true;
    }
};



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
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL)return head;
        ListNode* next = head->next;
        ListNode* res_head = reverse(head->next);
        
        next->next = head;
        head->next = NULL;
        
        return res_head;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head, *fast=head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        
        ListNode* rev;
        if(fast == NULL)rev = reverse(slow);
        else rev = reverse(slow->next);
        
        
        while(rev&&head){
            if(rev->val != head->val)return false;
            rev = rev->next;
            head = head->next;
        }
        return true;
    }
};