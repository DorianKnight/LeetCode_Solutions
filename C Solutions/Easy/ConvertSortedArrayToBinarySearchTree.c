// Author: Dorian Knight
// Date: January 15th 2025
// Description: Convert Sorted Array to Binary Search Tree C solution
// Rank: Easy
// Topics: Array || Divide and Conquer || Tree || Binary Search Tree || Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    // Recursive function to choose middle node and split remaining array for further processing

    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    // Base case
    if (numsSize == 1) {
        node->val = nums[0];
        node->left = NULL;
        node->right = NULL;
        // Left and right branches already initialized to null
    }

    else {
        int nodeElemIdx = numsSize/2;  // index of Middle element of given list
        int nodeElem = nums[nodeElemIdx];

        node->val = nodeElem;
        node->left = sortedArrayToBST(nums, nodeElemIdx); // Pass same array but length goes just before middle index
        if (numsSize > 2) {
            node->right = sortedArrayToBST((nums+nodeElemIdx+1), numsSize-nodeElemIdx-1); // Pass pointer to right side of array
        }
        else {
            node->right = NULL;
        }
    }

    return node;
}
