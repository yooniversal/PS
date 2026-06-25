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

    private static Set<ListNode> set;
    private static boolean ret;

    public boolean hasCycle(ListNode head) {
        set = new HashSet<>();
        ret = false;

        doNext(head);

        return ret;
    }

    public void doNext(ListNode cur) {
        if (cur == null) {
            return;
        }
        if (set.contains(cur)) {
            ret = true;
            return;
        }
        set.add(cur);
        
        doNext(cur.next);
    }
}
