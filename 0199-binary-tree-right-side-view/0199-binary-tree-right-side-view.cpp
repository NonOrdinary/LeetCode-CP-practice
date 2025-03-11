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
        vector<int>result;
        if(root==NULL){
            return result;
        }

        queue<TreeNode*>qu;
        qu.push(root);
        int level=1;
        while(!qu.empty()){
            int size=qu.size();
            while(size--){
                TreeNode *node=qu.front();
                qu.pop();
                if(result.size()<level){
                    result.push_back(node->val);
                }

                if(node->right!=NULL){
                    qu.push(node->right);
                }

                if(node->left!=NULL){
                    qu.push(node->left);
                }
            }
            level++;
        }
        return result;
    }
};