// Author: Dorian Knight
// Date: January 2nd 2025
// Description: Linked list cycle C solution
// Rank: Easy

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    // Tortoise and hare algorithm
    struct ListNode *fast;
    struct ListNode *slow;
    if (head != NULL && head->next != NULL && head->next->next != NULL) {
        fast = head->next->next;
        slow = head->next;
    }

    else {
        return false; // List has end therefore no cycle
    }

    while (fast != slow) {
        if (fast == NULL || slow == NULL) {
            return false; // Reached end of list therefore no cycle
        }

        if (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
        }

        else {
            // Either the next falue or the value after is null therefore the list ends
            return false;
        }

        if (slow->next != NULL) {
            slow = slow->next;
        }
    }

    // There is a point where the fast pointer overlapped with the slow pointer therefore there is a cycle
    return true;
}