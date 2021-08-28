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
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL)return head;
        ListNode* curr = head, *prev = NULL;
        while(left > 1){
            left--;
            prev = curr;
            curr = curr->next;
            right--;
        }
        ListNode* first = prev , *second = curr;
        while(right--){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        if(first)first->next = prev;
        else head = prev;
        second->next = curr;
        return head;
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
    ListNode* reverseList(ListNode* head , int c){
        // cout<<"GG";
        if(head == NULL)return head;
        if(c == 0)return head;
        ListNode* next = head->next;
        c--;
        ListNode* tail = reverseList(head->next , c);
        next->next = head;
        head->next = NULL;
        return tail;
    }
    
    void print(ListNode* head){
        if(head == NULL)return;
        cout<<head->val<<" ";
        print(head->next);
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL)return head;
        ListNode *curr = head , *prev=NULL;
        int count = right-left;
        left--;
        while(left--){
            curr = curr->next;
            if(prev == NULL)prev = head;
            else prev = prev->next;
        }
        
        ListNode *n = head;
        // right--;
        while(right--){
            n = n->next;
        }
        
        ListNode* tail = reverseList(curr, count);
        
        // print(tail);
        
        
        ListNode* rev_tail = NULL;
        if(prev)rev_tail = prev->next;
        else rev_tail = head;
        
        if(prev)prev->next = tail;
        else head = tail;
        
        rev_tail->next = n;
        
        
        
        return head;
    }
};