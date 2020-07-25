class Solution {
    public int[] singleNumber(int[] nums) {
        HashMap<Integer, Integer> ourMap = new HashMap();
        
        for ( int aNb : nums ) {
            if ( ourMap.containsKey( aNb ) ) {
                int freq = ourMap.get( aNb );
                ourMap.put( aNb, freq + 1 );
            }
            else {
                ourMap.put( aNb, 1 );
            }
        }
        
        int[] result = new int[2];
        int idx = 0;
        for ( Map.Entry<Integer, Integer> entry : ourMap.entrySet() ) {
            if ( entry.getValue() == 1 ) {
                result[idx] = entry.getKey();
                idx++;
            }
		}
        
        return result;
    }
}
