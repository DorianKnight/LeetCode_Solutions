// Author: Dorian Knight
// Date: January 13th 2025
// Description: Copy list with random pointer C solution
// Rank: Medium
// Topics: Hash table || Linked list

/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

import java.util.Hashtable;

class Solution {
    public Node copyRandomList(Node head) {
        // Create a hash table to store the pointers in order of appearance as well as the index they appear at
        Hashtable<Node, Integer> originalLinkedList = new Hashtable<Node, Integer>();
        Hashtable<Integer, Node> copiedLinkedList   = new Hashtable<Integer, Node>();

        Node currNode = head;
        int iterator = 0;

        if (currNode == null) {
            return null;
        }

        Node copyNode = new Node(0);
        Node copyNodeHead = copyNode;
        // Iterate through linked list, store both original and copied nodes in hash table with their indices
        while (currNode != null) {
            copyNode.val = currNode.val;

            // Put nodes into hash table
            originalLinkedList.put(currNode, iterator);
            copiedLinkedList.put(iterator, copyNode);

            // Move original list to next value
            currNode = currNode.next;
            iterator++;

            if (currNode != null) {
                // Make the next copied node
                Node nextCopyNode = new Node(0);
                copyNode.next = nextCopyNode;

                // Move copied list to next value
                copyNode = copyNode.next;
            }
        }

        // Assign the random pointers to the copied list
        currNode = head;
        int index = 0;
        copyNode = copyNodeHead;

        while (currNode != null) {
            // Find the index position of the random node
            if (currNode.random == null) {
                // Random points to null
                copyNode.random = null;
            }

            else {
                // The random pointer should point back to indexth node
                index = originalLinkedList.get(currNode.random);
                copyNode.random = copiedLinkedList.get(index);
            }

            // Advance both original and copied linked list
            currNode = currNode.next;
            copyNode = copyNode.next;
        }

        return copyNodeHead;
    }
}
