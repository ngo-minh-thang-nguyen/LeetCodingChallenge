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
    TreeNode* invertTree( TreeNode* root ) {
        doInvertTree( root );
        
        return root;
    }
    
    void doInvertTree( TreeNode* aNode ) {
        if ( aNode == NULL ) {
            return;
        }
        
        TreeNode* temp = aNode->left;
        aNode->left = aNode->right;
        aNode->right = temp;

        doInvertTree( aNode->left );
        doInvertTree( aNode->right );
    }
};
