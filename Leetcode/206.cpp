/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
class Solution {
    val a = arrayListOf<ListNode?>()

    fun init(cur: ListNode?) {
        cur?.let {
            a.add(cur)
            init(cur.next)
        }
    }

    fun reverseList(head: ListNode?): ListNode? {
        init(head)
        val reversedArray = a.toList().reversed().also { arr ->
            arr.forEachIndexed { i, cur ->
                if (i < (a.size - 1)) {
                    cur?.next = arr[i+1]
                } else {
                    cur?.next = null
                }
            }
        }
        return reversedArray.firstOrNull()
    }
}