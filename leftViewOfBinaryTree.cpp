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
    void solve(TreeNode* root , map<int,TreeNode*> &m, int lvl){
    if(root == NULL){
        return;
        
    }
    if(m.find(lvl) == m.end()){
        m[lvl]=root;
    }
        solve(root->right ,m ,lvl+1);
    solve(root->left , m , lvl+1);
    
}
    vector<int> rightSideView(TreeNode* root) {
         map<int, TreeNode*>level;
   solve(root, level , 0);
   vector<int>ans;
   if(level.empty()){
       return ans;
   }
   for(auto i : level){
       ans.push_back(i.second->val);
   }
   return ans;
    }
};
