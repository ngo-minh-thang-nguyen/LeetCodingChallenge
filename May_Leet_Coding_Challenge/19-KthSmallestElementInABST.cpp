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
    int kthSmallest( TreeNode* root, int k ) {
        int result = 0;
        traverseInorder( root, k, result );
        
        return result;
    }
    
    void traverseInorder( TreeNode* node, int& k, int& result ) {
        if ( node == NULL ) {
            return;
        }

        // first recur on left child
        traverseInorder( node->left, k, result );

        k--;
        // // then print the val of node
        // cout << node->val << endl;
        // cout << "pos : " << pos << endl;
        
        if ( k == 0 ) {
            result = node->val;
        }

        // now recur on right child
        traverseInorder( node->right, k, result );
    }
};
