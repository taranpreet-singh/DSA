/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     if (!root) {
    //         return q;
    //     }

    //     if (p->val > q->val) {
    //         swap(p, q);
    //     }
    //     if (root->val >= p->val && root->val < q->val) {
    //         return root;
    //     }
    //     if (root->val > p->val && root->val > q->val)
    //         return lowestCommonAncestor(root->left, p, q);
    //     return lowestCommonAncestor(root->right, p, q);
    // }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;

        while (cur) {
            if (p->val > cur->val && q->val > cur->val) {
                cur = cur->right;
            } else if (p->val < cur->val && q->val < cur->val) {
                cur = cur->left;
            } else {
                return cur;
            }
        }
        return nullptr;
    }
};