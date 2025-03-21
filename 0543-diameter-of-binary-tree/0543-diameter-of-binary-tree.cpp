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
    int depth(TreeNode*root,int &diameter){
        if(root==NULL){
            return 0;
        }
        int left=depth(root->left,diameter);
        int right=depth(root->right,diameter);

        diameter=max(diameter,(left+right));//diameter is of subtree rooted at node
        //we didn't do left+right+1 because we need to count edges and not nodes
        return 1+max(left,right);//we return maxDepth branch for diameter
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int result=0;
        depth(root,result);
        return result;
    }
};