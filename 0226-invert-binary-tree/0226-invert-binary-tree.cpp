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
    void BFS(TreeNode* root) {
        if (!root)
            return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            swap(node->left, node->right);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }

    void DFSRecurrsive(TreeNode* root) {
        if (!root)
            return;

        swap(root->left, root->right);
        DFSRecurrsive(root->left);
        DFSRecurrsive(root->right);
    }

    void DFSIterative(TreeNode* root) {
        if (!root)
            return;
        stack<TreeNode*> stack;
        stack.push(root);
        while (!stack.empty()) {
            TreeNode* node = stack.top();
            stack.pop();
            swap(node->left, node->right);
            if (node->left)
                stack.push(node->left);
            if (node->right)
                stack.push(node->right);
        }
    }

public:
    TreeNode* invertTree(TreeNode* root) {
        // BFS(root);
        // DFSRecurrsive(root);
        DFSIterative(root);
        return root;
    }
};