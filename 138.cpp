/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *curr = head;
        while(curr != NULL){
            Node *temp = new Node(curr->val);
            temp -> next = curr -> next ;
            curr -> next = temp;
            curr = temp->next;
        }
        curr = head;
        
        while(curr != NULL){
            curr -> next -> random = curr -> random ? curr -> random -> next : NULL;
            curr = curr -> next -> next;
        }
        
        curr = head;
        Node *head1;
        if(head)head1 = head -> next;
        Node *head2 = head1;
        
        while(curr && head1){
            // cout<<"\ncurr = "<<curr->val;
            // cout<<"\nhead = "<<head1->val;
            curr -> next = curr->next ? curr->next->next : NULL;
            head1 -> next = head1 ->next ? head1->next->next : NULL;
            curr = curr->next;
            head1 = head1->next;
        }
        return head2;
//         unordered_map<Node *, Node *> m;
//         Node *curr = head;
//         while(curr != NULL){
//             m[curr] = new Node(curr->val);
//             curr = curr ->next;
//         }
//         curr = head;
//         while(curr != NULL){
//             Node* cc = m[curr];
//             cc->next = m[curr->next];
//             cc->random = m[curr->random];
//             curr = curr->next;
//         }
        
//         Node *head2 = m[head];
//         return head2;
        
    }
};