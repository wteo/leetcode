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
    void binaryTreePaths(vector<string>&rst,TreeNode* root,string s){
        if(!root->left && !root->right){
            rst.push_back(s);
            return ;
        }
        if(root->left) binaryTreePaths(rst,root->left,s+"->"+to_string(root->left->val));
        if(root->right) binaryTreePaths(rst,root->right,s+"->"+to_string(root->right->val));
    }  
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>rst;
        if(!root) return rst;
        binaryTreePaths(rst,root,to_string(root->val));
        return rst;
    }
    
};