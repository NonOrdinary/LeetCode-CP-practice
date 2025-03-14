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
    int postorder(TreeNode*root,int &result){
        if(root==NULL){
            return 0;
        }
        int left=postorder(root->left,result);
        int right=postorder(root->right,result);
        result=max(result,left+right+root->val);

        int nodeResult=max({left,right})+root->val;
        return max(nodeResult,0);
    }
    int maxPathSum(TreeNode* root) {
        /***/
        /**
             * Intuition
             * 1.The problem seems complicated as hell because we
             * need to consider all paths from each node
             * 2.But do we really neeed to ?
             * 3.Say there is a CBT of height(2 including root),the what 
             * will be the maximum sum at root ? 
             * 3a) max(left,right)+node
             * 3b) left+right+node
             * the maximum of above
             * 
             * 4.So for each node idea is to find the maximum sum including the node
             * and only considering the subtree
             * 5.We do not need to bother about the nodes above our root because
             * if it can be included in maxPath then it will be included as soon as
             * we process that node because we will use results of point 3
             * 
             * 5.Say a path is from (u,v) including root where u is on left of root,and v is on 
             * right of v,then if uv is maxpath,as we process the root we will get the 
             * maxpath value at root cause if u-r-v is max the u-r and r-v will be maximums too
             * in left and right subtree rooted at root' 
             */
        int result=INT_MIN;
        postorder(root,result);
        return result;      
    }
};