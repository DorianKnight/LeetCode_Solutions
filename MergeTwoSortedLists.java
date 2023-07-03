/**
  * Solution description
  * Iterate through both lists, check to see which node is lowest.
  * Add the lowest node to the list. Continue iterating until one list reaches the end
  * Once one list ends, just add the remainder of the leftover list to the new list
  */

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
        ListNode headNode = new ListNode();
        ListNode currentNode = headNode;

        while (list1 != null && list2 != null)
        {
            // Iterate through both lists and add the lowest value to the merged list
            // Do this until one of the lists run out
            if (list1.val < list2.val)
            {
                currentNode.val = list1.val;
                list1 = list1.next;
            }

            else
            {
                currentNode.val = list2.val;
                list2 = list2.next;
            }
            
            currentNode.next = new ListNode();
            currentNode = currentNode.next;
        }

        if (list1 != null)
        {
            // List 1 still has leftover values
            currentNode.val = list1.val;
            currentNode.next = list1.next;
        }
        else if (list2 != null)
        {
            // List 2 still has leftover values
            currentNode.val = list2.val;
            currentNode.next = list2.next;
        }
        else
        {
            // The only way for list 1 and list 2 to both be null is for them to both be empty.
            // In this case, returning null as the headNode is the desired action
            headNode = null;
        }

        return headNode;
    }
}