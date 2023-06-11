class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node *next=NULL;
    Node *pre=NULL;
    void addnext(Node *root){
        if(root){
            addnext(root->right);
            root->right=next;
            next=root;
            addnext(root->left);
        }
    }
    Node *addpre(Node *root){
        while(root->left!=NULL){
            root=root->left;
        }
        Node *head=root;
        while(root!=NULL){
            root->left=pre;
            pre=root;
            root=root->right;
        }
        return head;
    }
    Node * bToDLL(Node *root)
    {
        addnext(root);
        Node *h=addpre(root);
        return h;
    }
};
