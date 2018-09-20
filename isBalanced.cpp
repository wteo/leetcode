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
    bool isBalanced(TreeNode* root) {
        return balanceness(root)!=-1;
    }
    
    int balanceness(TreeNode* root){
        if(!root) return 0;
        int left=balanceness(root->left);
        int right=balanceness(root->right);
        if(left>-1 && right>-1 && abs(left-right)<2) 
            return max(left,right)+1;
        else return -1;
    }
};