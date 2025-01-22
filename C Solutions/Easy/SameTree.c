// Author: Dorian Knight
// Date: January 22nd 2025
// Description: Same Tree C solution
// Rank: Easy
// Topics: Tree || Depth-First Search || Breadth-First Search || Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // Base case
    if (p == NULL && q == NULL) {
        return true; // Both nodes are the same
    }

    if (p == NULL || q == NULL) {
        // Didn't fall into the if statement above meaning one is null but the other isn't
        return false;
    }

    if (p->val != q->val) {
        return false; // Values of both nodes are different
    }

    // Tree nodes have the same value and are non null
    bool lftSame = isSameTree(p->left, q->left);
    bool rhtSame = isSameTree(p->right, q->right);
    if (lftSame == false || rhtSame == false) {
        return false;
    }

    return true; // Both left and right side of the tree from this point on are the same
}
