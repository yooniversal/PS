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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode head = new ListNode();

        connect(head, list1, list2);
        head = head.next;
        return head;
    }

    public void connect(ListNode prev, ListNode a, ListNode b) {
        if (a == null && b == null) return;
        if (a == null) {
            prev.next = b;
            connect(prev.next, null, b.next);
            return;
        }
        if (b == null) {
            prev.next = a;
            connect(prev.next, a.next, null);
            return;
        }

        if (a.val <= b.val) {
            prev.next = a;
            connect(prev.next, a.next, b);
        } else {
            prev.next = b;
            connect(prev.next, a, b.next);
        }
    }
}
