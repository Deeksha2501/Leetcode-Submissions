/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* dfs(Node *head){
        if(head->next == NULL && head->child == NULL)return head;
        if(head->next == NULL && head->child != NULL){
            Node *child = head->child;
            head->next = child;
            child->prev = head;
            head->child = NULL;
            return dfs(child);
        }
        if(head->child == NULL)return dfs(head->next);
        Node *child = head->child;
        child->prev = head;
        Node* next = head->next;
        head->next = child;
        Node *tail = dfs(head->child);
        head->child = NULL;
        tail->next = next;
        next->prev = tail;
        return dfs(next);
    }
    
    Node* flatten(Node* head) {
        if(head == NULL)return NULL;
        
        dfs(head);
        return head;
        
    }
};