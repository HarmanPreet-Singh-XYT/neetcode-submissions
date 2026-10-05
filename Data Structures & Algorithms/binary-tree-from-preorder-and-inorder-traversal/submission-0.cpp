/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size() || !inorder.size()){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        int mid;
        for(int x = 0;x<inorder.size();x++){
            if(preorder[0]==inorder[x]){
                mid = x;
                break;
            }
        }
        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + 1 + mid);
        vector<int> rightPre(preorder.begin() + 1 + mid, preorder.end());

        vector<int> leftIn(inorder.begin(), inorder.begin() + mid);
        vector<int> rightIn(inorder.begin() + mid + 1, inorder.end());

        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);
        return root;
    }
};
