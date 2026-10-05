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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> arr;
        queue<TreeNode*> que;
        if(root){
            que.push(root);
        }
        while(que.size()>0){
            int len = que.size();
            TreeNode* rightSide = nullptr;
            for(int x = 0;x<len;x++){
                TreeNode* curr = que.front();
                que.pop();
                if(curr){
                    rightSide = curr;
                    que.push(curr->left);
                    que.push(curr->right);
                }
            }
            if(rightSide){
                arr.push_back(rightSide->val);
            }
        }
        return arr;
    }
};