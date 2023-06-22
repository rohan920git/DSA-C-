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
    string solve(TreeNode* root ,vector<TreeNode*> &ans, unordered_map<string,int>  &m){
        if(root == NULL){
            return "#";
            
        }
        string s = solve(root->left,ans,m)+ ',' + solve(root->right,ans,m) + "," + to_string(root->val);
        m[s]++;
        if(m[s] == 2){
            ans.push_back(root);
        }
        cout<<s<<endl;
        return s; 
        }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> m;
        vector<TreeNode*>ans;
        solve( root , ans, m);
        return ans;
    }
};
