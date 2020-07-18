class Solution {
public:
    int searchInsert( vector<int>& nums, int target ) {
        int left = 0, right = nums.size() - 1;
        return findTarget( nums, target, left,  right );
    }
    
    int findTarget( vector<int>& nums, int target, int left,  int right ) {
        if ( left == right ) {
            if ( target > nums[left] )
                return left + 1;
            else
                return left;
        }
        
        int mid = left + (right - left) / 2;
        
        if ( target <= nums[mid] )
            return findTarget( nums, target, left,  mid );
        else
            return findTarget( nums, target, mid + 1,  right );
    }
};
