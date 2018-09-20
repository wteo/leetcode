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
 /*  
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> rst;
        if(!root) return rst;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> tmp;
            int n=q.size();
            while(n--){
                auto node=q.front();
                q.pop();
                tmp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            rst.push_back(tmp);
        }
        return rst;
    }
*/
    void levelOrder(vector<vector<int>>& rst,TreeNode* root,int level) {
        //vector<int> v;
        if(!root) return ;
        if(rst.size()==level)
            rst.push_back(vector<int>());
        rst[level].push_back(root->val);
        levelOrder(rst,root->left,level+1);
        levelOrder(rst,root->right,level+1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> rst;
        levelOrder(rst,root,0);
        return rst;
    }
};