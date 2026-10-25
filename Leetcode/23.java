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
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> pq = new PriorityQueue<>((a, b) -> Integer.compare(a.val, b.val));

        for (ListNode node : lists) {
            if (node != null) {
                pq.add(node);
            }
        }

        ListNode head = new ListNode();
        ListNode tail = head;

        while (!pq.isEmpty()) {
            ListNode node = pq.poll();
            
            if (node.next != null) {
                pq.add(node.next);
            }

            tail.next = node;
            tail = node;
        }

        return head.next;
    }
}
