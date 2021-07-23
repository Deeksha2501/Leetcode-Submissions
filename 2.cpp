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
    
    ListNode* reverseLL(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *res_head = reverseLL(head->next);
        ListNode *res_tail = head->next;
        res_tail->next = head;
        head->next = NULL;
        return res_head;
    }
    
    void print(ListNode *head){
        while(head != NULL){
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<endl;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // ListNode *ll1 = reverseLL(l1);
        ListNode *ll1 = l1;
        print(ll1);
        // ListNode *ll2 = reverseLL(l2);
        ListNode *ll2 = l2;
        print(ll2);
        ListNode *head = NULL;
        ListNode *prev = NULL;
        int carry = 0;
        
        while(ll1 || ll2){
            ListNode *temp = new ListNode(carry);
            if(ll1){
                temp->val += ll1->val;
                ll1 = ll1->next;
            }
            if(ll2){
                temp->val += ll2->val;
                ll2 = ll2->next;
            }
            
            if(temp->val>=10){
                carry = 1;
                temp->val = temp->val%10;
            }else{
                carry =0;
            }
            
            if(head == NULL){
                head = temp;
            }
            else{
                prev->next = temp;
            }
            prev = temp;
        }
        
        // print(head);
        
        if(carry){
            ListNode *temp = new ListNode(carry);
            prev->next = temp;
        }
        
        return head;
        
    }
};



