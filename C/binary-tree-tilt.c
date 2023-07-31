
 // Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
 };

class Solution {
public:
    int findTilt(TreeNode* root)
    {
        if (root == NULL)
            return 0;

        int sum = 0;
        int leftSum = 0;
        int rightSum = 0;

        if (root->left != NULL)
        {
            sum += findTilt(root->left);
            leftSum = sumNode(root->left);
        }


        if (root->right != NULL)
        {
            sum += findTilt(root->right);
            rightSum = sumNode(root->right);
        }

        return sum + abs(leftSum - rightSum);
    }

    int sumNode(TreeNode* node)
    {
        if (node == NULL)
            return 0;

        int sum = node->val;

        if (node->left != NULL)
            sum += sumNode(node->left);

        if (node->right != NULL)
            sum += sumNode(node->right);

        return sum;
    }
};
