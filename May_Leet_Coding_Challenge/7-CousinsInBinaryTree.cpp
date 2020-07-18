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
    bool isCousins( TreeNode* root, int x, int y ) {
        // mapping between a node and its parent: key is the node itself, value is its parent
        // since a node has only one node parent
        map<int, int> mapNodeAndParent;
        
        // find height of x
        int heightOfX;
        findHeightAndParent( root, x, 0, mapNodeAndParent, heightOfX );
        
        // find height of y
        int heightOfY;
        findHeightAndParent( root, y, 0, mapNodeAndParent, heightOfY );
        
        // check if they are cousins
        if ( heightOfX == heightOfY ) {
            // if x and y share same parent, return false
            if ( mapNodeAndParent[ x ] == mapNodeAndParent[ y ] ) return false;
            else return true;
        }
        else return false;
        
        return false;
    }
    
    void findHeightAndParent( TreeNode* aNode, int search, int height, map<int, int>& mapNodeAndParent, int& heightOfSearch ) {
        // basic case
        if ( aNode == NULL ) {
            return;
        }
        
        if ( aNode->val == search ) {
            heightOfSearch = height;
        }

        height = height + 1;

        if ( aNode->left != NULL )
            mapNodeAndParent[ aNode->left->val ] = aNode->val;
        if ( aNode->right != NULL )
            mapNodeAndParent[ aNode->right->val ] = aNode->val;

        findHeightAndParent( aNode->left, search, height, mapNodeAndParent, heightOfSearch );
        findHeightAndParent( aNode->right, search, height, mapNodeAndParent, heightOfSearch );
    }
};
