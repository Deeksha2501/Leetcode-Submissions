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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* curr;
        int kk = k;
        kk--;
        while(kk--){
            curr = curr->next;
        }
        ListNode* temp = curr->next;
        ListNode *n2=head;
        while(temp){
            n2 = n2->next;
            temp = temp->next;
        }
        swap(curr->val , n2->val);
        return head;
    }
};