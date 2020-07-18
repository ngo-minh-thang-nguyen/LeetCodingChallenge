class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        return findNonDuplicate( nums, 0, nums.size()-1 );
    }
    
    int findNonDuplicate(vector<int>& nums, int left, int right) {
        if ( left == right ) return nums[left];
        
        int middle = left + (right-left)/2;
        
        if ( (middle - left) % 2 == 0 ){
            if ( nums[middle] != nums[middle+1] )
                return findNonDuplicate( nums, left, middle );
            else 
                return findNonDuplicate( nums, middle+2, right );
        }
        else {
            if ( nums[middle] != nums[middle+1] )
                return findNonDuplicate( nums, middle+1, right );
            else 
                return findNonDuplicate( nums, left, middle-1 );
        }
    }
};
