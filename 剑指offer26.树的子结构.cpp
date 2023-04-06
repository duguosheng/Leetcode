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
    bool recur(TreeNode* A, TreeNode* B) {
        if (B == nullptr)
            return true;
        if (A == nullptr)
            return false;
        if (A->val != B->val)
            return false;
        return recur(A->left, B->left) && recur(A->right, B->right);
    }
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B)
            return false;
        return recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};
