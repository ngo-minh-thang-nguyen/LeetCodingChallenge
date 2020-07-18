class Solution {
    public int singleNumber(int[] nums) {
        HashMap<Integer, Integer> numAndFrequen = new HashMap<Integer, Integer>();
        for ( int i = 0; i < nums.length; i++ ) {
            if ( numAndFrequen.containsKey( nums[i] ) ) {
                int currFreq = numAndFrequen.get( nums[i] ) + 1;
                numAndFrequen.put( nums[i], currFreq );
            }
            else {
                numAndFrequen.put( nums[i], 1 );
            }
        }
        
        int result;
        
        for ( Map.Entry<Integer, Integer> entry : numAndFrequen.entrySet() ) {
            if ( entry.getValue() == 1 )
                return entry.getKey();
		}
        
        return -1;
    }
}
