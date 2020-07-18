class Solution {
    public int findDuplicate(int[] nums) {
        HashMap<Integer, Integer> frequency = new HashMap<Integer, Integer>();
        
        for ( int nb : nums ) {
            if ( frequency.containsKey( nb ) ) {
                if ( frequency.get( nb ) == 1 )
                    return nb;
            }
            else
                frequency.put( nb, 1 );
        }
        
        return -1;
    }
}
