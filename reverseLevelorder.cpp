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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
   vector<vector<int>>ans;
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        
        vector<int> temp;
        while(!q.empty()){
           TreeNode* tempnode = q.front();
            q.pop();
            temp.push_back(tempnode->val);
            if(tempnode->left){
                q.push(tempnode-> left);
            }
            if(tempnode->right){
                q.push(tempnode->right);
            }
            if(q.front()== NULL){
               q.pop();
              
                if(q.size())
                q.push(NULL);
                
            ans.push_back(temp);
                temp.clear();
            }
        }
    reverse(ans.begin(), ans.end());
        return ans;
    }
};
