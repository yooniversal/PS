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

    private static ListNode lastNode;

    public ListNode reverseList(ListNode head) {
        lastNode = null;
        reverse(null, head);
        return lastNode;
    }

    public void reverse(ListNode prev, ListNode cur) {
        if (cur == null) {
            lastNode = prev;
            return;
        }
        reverse(cur, cur.next);
        cur.next = prev;
    }
}
