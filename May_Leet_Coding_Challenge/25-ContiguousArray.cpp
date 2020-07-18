class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hashMap;

        int sum = 0;
        int maxLength = 0;

        for ( int i = 0; i < nums.size(); i++ ) 
            nums[i] = ( nums[i] == 0 )? -1: 1; 

        for ( int i = 0; i < nums.size(); i++ ) 
        {
            sum += nums[i];

            if (sum == 0)
            {
                maxLength = i + 1;
            }

            if ( hashMap.find( sum + nums.size() ) != hashMap.end() )
            {
                if ( maxLength < i - hashMap[sum + nums.size()] )
                {
                    maxLength = i - hashMap[sum + nums.size()];
                }
            }
            else {
                hashMap[ sum + nums.size() ] = i;
            }
        }
        
        return maxLength;
    }
    
};
