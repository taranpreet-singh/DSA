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
    int DFSRec(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return 1 + max(DFSRec(root->left), DFSRec(root->right));
    }

    int DFSIter(TreeNode* root) {
        stack<pair<TreeNode*, int>> stack;
        int res = 0;
        stack.push({root, 1});
        while (!stack.empty()) {
            pair<TreeNode*, int> top = stack.top();
            stack.pop();
            TreeNode* node = top.first;
            int depth = top.second;
            if (node) {
                res = max(res, depth);
                stack.push({node->left, depth++});
                stack.push({node->right, depth++});
            }
        }
        return res;
    }

    int BFS(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            level++;
        }
        return level;
    }

public:
    int maxDepth(TreeNode* root) { return BFS(root); }
};