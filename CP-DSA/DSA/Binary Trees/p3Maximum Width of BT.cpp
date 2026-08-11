#include <bits/stdc++.h>
using namespace std;

// Class definition for a binary tree node
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructor to initialize the node value
    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;

        long long maxWidth = 0;

        queue<pair<TreeNode *, long long>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            int size = q.size();

            long long minIndex = q.front().second;
            long long first = 0, last = 0;

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front().first;
                long long currIndex = q.front().second - minIndex;

                q.pop();

                if (i == 0)
                    first = currIndex;

                if (i == size - 1)
                    last = currIndex;

                if (node->left)
                    q.push({node->left, 2 * currIndex + 1});

                if (node->right)
                    q.push({node->right, 2 * currIndex + 2});
            }

            maxWidth = max(maxWidth, last - first + 1);
        }

        return maxWidth;
    }
};

int main()
    {

        // Create a sample tree
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(3);
        root->right = new TreeNode(2);
        root->left->left = new TreeNode(5);
        root->left->right = new TreeNode(3);
        root->right->right = new TreeNode(9);

        // Create solution object
        Solution sol;

        // Call the function and print the result
        cout << "Maximum width: " << sol.widthOfBinaryTree(root) << endl;

        return 0;
    }