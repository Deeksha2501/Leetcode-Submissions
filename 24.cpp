/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head==null)return head;
        ListNode prev=null;
        ListNode current =head;
        
        while(current!=null && current.next!=null){
            ListNode first=current;
            ListNode second=current.next;
            ListNode temp=current.next.next;
            
            if(prev == null){
                head = second;
            }else{
                prev.next=second;
            }
            second.next=first;
            first.next=temp;
            current=temp;
            prev = first;
        }
        return head;
    }
}