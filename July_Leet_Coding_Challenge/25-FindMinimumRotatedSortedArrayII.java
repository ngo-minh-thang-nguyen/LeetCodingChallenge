class Solution {
    public int findMin(int[] nums) {
        if ( nums.length == 1 )
            return nums[0];
        else {
            int idx;
            for ( idx = 0; idx < nums.length; idx++ ) {
                if ( idx + 1 < nums.length ) {
                    if ( nums[idx + 1] < nums[idx] ) {
                        idx = idx + 1;
                        break;
                    }
                }

                if ( idx + 1 == nums.length - 1 )
                    return nums[0];
            }

            return nums[idx];
        }
    }
}
