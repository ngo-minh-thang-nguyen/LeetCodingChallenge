class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> ourMap = new HashMap();
        for ( int i = 0; i < nums.length; i++ ) {
            if ( ourMap.containsKey( nums[i] ) ) {
                int freq = (int) ourMap.get( nums[i] );
                ourMap.put( nums[i], freq + 1 );
            }
            else
                ourMap.put( nums[i], 1 );
        }
        
        List<Integer> aList = new ArrayList<Integer>();
        for ( Map.Entry<Integer, Integer> entry : ourMap.entrySet() ) {
            aList.add( entry.getValue() );
		}
        
        Collections.sort( aList );
        
        List<Integer> kFrequentList = new ArrayList<Integer>();
        
        for ( int i = aList.size() - 1; i >= aList.size() - k; i-- )
            kFrequentList.add( aList.get(i) );
        
        // System.out.println( kFrequentList.size() );
        
        // for ( int i = 0; i < kFrequentList.size(); i++ )
        //     System.out.println( kFrequentList.get(i) );
        
        int[] result = new int[k];
        for ( int i = 0; i < kFrequentList.size(); i++ ) {
            for ( Map.Entry<Integer, Integer> entry : ourMap.entrySet() ) {
                if ( entry.getValue() == kFrequentList.get(i) ) {
                    result[i] = entry.getKey();
                    ourMap.remove( entry.getKey() );
                    break;
                }
            }
        }
        
        return result;
    }
}
