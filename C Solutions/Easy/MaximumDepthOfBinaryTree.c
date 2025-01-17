// Author: Dorian Knight
// Date: January 17th 2025
// Description: Maximum depth of binary tree C solution
// Rank: Easy
// Topics: Binary Tree || Tree || Depth-First Search || Breadth-First Search

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Prototype declaration
int findTreeDepth(struct TreeNode* node, int height);

int maxDepth(struct TreeNode* root) {
    // Use recursion to traverse entire tree

    int height = 0;
    return findTreeDepth(root, height);
}

int findTreeDepth(struct TreeNode* node, int height) {
    // Base case
    if (node == NULL) {
        return height;
    }

    // Node proven to be valid, increase height to current level
    height++;
    int lftHeight = findTreeDepth(node->left, height);
    int rhtHeight = findTreeDepth(node->right, height);
    int retHeight = 0;

    if (lftHeight > rhtHeight) {
        retHeight = lftHeight;
    }
    else {
        retHeight = rhtHeight;
    }
    return retHeight;
}
