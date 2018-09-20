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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> rst;
        if(!root) return rst;
        queue<TreeNode*> q;
        
        q.push(root);
        while(!q.empty()){
            int len=q.size();
            vector<int> tmp;
            while(len--){
                auto node=q.front();
                q.pop();
                tmp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            rst.push_back(tmp);
        }
        reverse(rst.begin(),rst.end());
        return rst;
    }
/*
vector<vector<int>> rst;
    
    void dfs(TreeNode* root,int level){
       if(!root) return;
       if(level==rst.size())
            rst.push_back(vector<int>());
       rst[level].push_back(root->val);
       dfs(root->left,level+1);
       dfs(root->right,level+1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        dfs(root,0);
        reverse(rst.begin(),rst.end());
        return rst;
    }
*/

};