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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL)return new TreeNode(head->val);
        ListNode *first = head, *sec=head , *prev=NULL;
        while(sec && sec->next ){
            prev = first;
            first = first->next;
            sec = sec->next->next;
        }
        TreeNode* root = new TreeNode(first->val);
        if(prev == NULL)root->left = NULL;
        else{
            prev->next = NULL;
            root->left = sortedListToBST(head);
        }
        if(first){
            root->right = sortedListToBST(first->next);
        }else{
            root->right = NULL;
        }
        return root;
    }
};