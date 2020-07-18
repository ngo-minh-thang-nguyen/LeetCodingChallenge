class Solution {
public:
    void sortColors(vector<int>& nums) {
        int j = 0;
        int n = nums.size();
        
        for ( int i = 0; i < n; i++ ) {
            if ( nums[i] == 0 ) {
                swap( nums[j], nums[i] );
                j++;
            }
            else if ( nums[i] == 2 ) {
                n--;
                swap( nums[n], nums[i] );
                i--;
            }
        }
    }
};
