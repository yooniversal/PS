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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode ret = new ListNode();
        ListNode cur = ret;

        int carry = 0;
        while (l1 != null || l2 != null) {
            int valSum = 0;

            if (l1 != null && l2 != null) {
                valSum = l1.val + l2.val + carry;
            } else if (l1 != null) {
                valSum = l1.val + carry;
            } else {
                valSum = l2.val + carry;
            }

            carry = valSum >= 10 ? 1 : 0;
            cur.val = valSum % 10;
            cur.next = new ListNode();

            if (l1 != null) l1 = l1.next;
            if (l2 != null) l2 = l2.next;
            cur = cur.next;
        }

        if (carry > 0) {
            cur.val = 1;
            return ret;
        }

        ListNode st = ret;
        while (st.next != cur) {
            st = st.next;
        }
        st.next = null;

        return ret;
    }
}