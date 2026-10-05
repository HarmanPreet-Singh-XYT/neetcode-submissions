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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> arr;
        queue<TreeNode*> que;
        if(root){
            que.push(root);
        }
        while(que.size() > 0){
            vector<int> temp;
            int len = que.size();
            for(int x = 0;x<len;x++){
                TreeNode* curr = que.front();
                que.pop();
                temp.push_back(curr->val);
                if(curr->left){
                    que.push(curr->left);
                }
                if(curr->right){
                    que.push(curr->right);
                }
            }
            arr.push_back(temp);
        }
        return arr;
    }
};
