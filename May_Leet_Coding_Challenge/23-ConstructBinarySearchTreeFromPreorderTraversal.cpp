/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder( vector<int>& preorder ) {
        int preIndex = 0;  
        return constructTree( preorder, 0, preorder.size() - 1 );
    }
    
    TreeNode* constructTree( vector<int>& preorder, int left, int right )
    {
        // Basic case  
        if ( left >=  preorder.size() || left > right )  
            return NULL;

        // Create a new root node corresponding to preorder[left]
        TreeNode* root = new TreeNode( preorder[left] );
        
        // If the current subarray has only one element, we return this element
        if ( left == right )  
            return root;
        
        // We increment left by 1 to consider the next elements in the actual subarray
        left = left + 1;

        // Looking for the first element greater than value of the root node
        int i;  
        for ( i = left; i <= right; i++ )  
            if ( preorder[i] > root->val )  
                break;  

        // Divide the subarray into two parties based on the index i found above :
        // Left part and right part
        // Left part contains all elements belong to left subtree
        // Right part contains all elements belong to right subtree
        root->left = constructTree( preorder, left, i - 1 );  
        root->right = constructTree( preorder, i, right );  

        return root; 
    }
    
    
    
    
//     // Create a new node  
//     TreeNode* newNode (int val)  
//     {
//         TreeNode* temp = new TreeNode(val);

//         temp->left = temp->right = NULL;

//         return temp;  
//     }
    
//     void constructTree(vector<int>& preorder, TreeNode* node, int& i) {
//         TreeNode aNode(preorder[i]);
        
//         for (std::vector<int>::iterator it = preorder.begin() ; it != preorder.end(); ++it)
//             std::cout << ' ' << *it;
        
//         if ( aNode.val > node->val ) node->right = &aNode;
//         else if ( aNode.val < node->val ) node->left = &aNode;
        
//         i++;
//     }
};
