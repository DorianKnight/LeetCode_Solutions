/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */

/**
 * Solution description:
 *
 * Iterate through both lists at the same time, if both values are the same, put both values into the new list.
 * If the two values are different, place the lowest value in first and increment your position on that list.
 * Continue to inch along each array until they're both merged into one list
 */

public class Solution {
    public ListNode MergeTwoLists(ListNode list1, ListNode list2) {

        // HeadNode
        ListNode HeadMergedNode = new ListNode();
        ListNode CurrentNode = HeadMergedNode;
        
        while (list1.next != null && list2.next != null)  // Iterate until you reach the end of one of the lists
        {
            //Find lowest value and add it to the merged list
            
            if (list1.val < list2.val)
            {
                // Add list1 val into merged list
                // Move to next node on list1
                CurrentNode.val = list1.val;
                list1 = list1.next;
            }

            else
            {
                // Add list2 val into merged list
                // Move to next node on list2
                CurrentNode.val = list2.val;
                list2 = list2.next;
            }

            // Create new node in merged list
            CurrentNode.next = new ListNode();
            CurrentNode = CurrentNode.next; 
        }
        //return HeadMergedNode; 
        return CurrentNode;
    }
}