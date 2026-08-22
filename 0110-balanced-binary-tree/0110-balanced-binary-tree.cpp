/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {

private:
    int dfs(TreeNode* root) {
        if (!root)
            return 0;

        int left = dfs(root->left);
        if (left == -1)
            return -1;

        int right = dfs(root->right);
        if (right == -1)
            return -1;

        if (abs(left - right) > 1)
            return -1;

        return 1 + max(left, right);
    }

public:
    bool isBalanced(TreeNode* root) { return dfs(root) != -1; }

    // O(n^2)

    // private:
    //     int depth(TreeNode* root) {
    //         if (!root)
    //             return 0;
    //         return 1 + max(depth(root->right), depth(root->left));
    //     }

    // public:
    //     bool isBalanced(TreeNode* root) {
    //         if (!root)
    //             return true;

    //         queue<TreeNode*> q;
    //         q.push(root);
    //         while (!q.empty()) {
    //             TreeNode* node = q.front();
    //             q.pop();

    //             int leftDepth = depth(node->left);
    //             int rightDepth = depth(node->right);
    //             if (abs(leftDepth - rightDepth) > 1)
    //                 return false;

    //             if (node->left)
    //                 q.push(node->left);
    //             if (node->right)
    //                 q.push(node->right);
    //         }
    //         return true;
    //     }
};