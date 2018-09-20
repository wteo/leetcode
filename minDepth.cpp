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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left) return minDepth(root->right)+1;
        if(!root->right) return minDepth(root->left)+1;
        return min(minDepth(root->left),minDepth(root->right))+1;
    }

    int minDepth(TreeNode* root) {
        if(!root) return 0;
        
        stack<pair<TreeNode*,int>> s;
        int rst=INT_MAX;
        s.push(make_pair(root,1));
        
        while(!s.empty()){
             auto p=s.top().first;
             auto depth=s.top().second;
             s.pop();
             
             if(!p->left && !p->right)
                rst=min(rst,depth);
             if(p->left && depth<rst)
                s.push(make_pair(p->left,depth+1));
             if(p->right && depth<rst)
                s.push(make_pair(p->right,depth+1));
        }
        return rst;
    }
};