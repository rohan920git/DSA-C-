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
    int solve(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftAns = 1+solve(root->left);
        int rightAns = 1+solve(root->right);
        return max(leftAns, rightAns);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root == NULL){
            return NULL;
            
        }
        int leftAns = 1+solve(root ->left);
        int rightAns = 1+solve(root->right);
        if(leftAns == rightAns){
            return root;
        }
        else if( leftAns > rightAns){
            return subtreeWithAllDeepest(root -> left);
        }
        else {
            return subtreeWithAllDeepest(root -> right);
        }
    }
};
