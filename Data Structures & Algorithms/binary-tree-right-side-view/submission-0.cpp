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
            bool pushed = false;
            for(int x = 0;x<len;x++){
                TreeNode* curr = que.front();
                que.pop();
                if(curr->right){
                    que.push(curr->right);
                }
                if(curr->left){
                    que.push(curr->left);
                }
                if(!pushed){
                    arr.push_back(curr->val);
                    pushed = true;
                }
            }
        }
        return arr;
    }
};