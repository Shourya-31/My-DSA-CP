#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class SOlution
{
public:
    // FUnction to update the value of nodes to make the tree a children sum tree.
    void changeTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        // To calc sum of children of a node

        int child = 0;
        if (root->left)
        {
            child += root->left->val;
        }
        if (root->right)
        {
            child += root->right->val;
        }

        // Comparision
        if (child >= root->val)
        {
            root->val = child;
        }
        else
        {
            // If the sum is smaller, update the
            // child with the current node's value.
            if (root->left)
            {
                root->left->val = root->val;
            }
            else if (root->right)
            {
                root->right->val = root->val;
            }
        }

        changeTree(root->left);
        changeTree(root->right); // Recursion call

        // Calculate the total sum of the
        // values of the left and right

        int total = 0;
        if (root->left)
        {
            total += root->left->val;
        }
        if (root->right)
        {
            total += root->right->val;
        }

        if (root->left || root->right)
        {
            root->val = total;
            // If either left or right child
            // exists, update the current node's
            // value with the total sum.
        }
    }
};

void inorder(TreeNode *root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

inorder(root);
SOlution sol;
sol.changeTree(root);
cout<<endl;

inorder(root);
cout<<endl;
return 0;
}