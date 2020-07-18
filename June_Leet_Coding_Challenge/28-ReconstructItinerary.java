public class Solution {
    public List<String> findItinerary(List<List<String>> tickets) {
        List<String> result = new ArrayList();
        
        if ( tickets == null || tickets.size() == 0 ) 
            return result;
        
        Map<String, TreeMap<String, Integer>> map = new HashMap();
        
        for ( List<String> pair : tickets ) {
            if ( !map.containsKey( pair.get(0) ) ) 
                map.put( pair.get(0), new TreeMap() );
            
            TreeMap<String, Integer> cache = map.get( pair.get(0) );
            cache.put( pair.get(1), cache.containsKey(pair.get(1)) ? cache.get(pair.get(1)) + 1 : 1 );
        }
        dfs("JFK", map, result, tickets.size() + 1);
        return result;
    }
    
    private boolean dfs( String curr, Map<String, TreeMap<String, Integer>> map, List<String> result, int size ) {
        result.add(curr);
        
        if ( result.size() == size ) 
            return true;
        
        if ( map.containsKey(curr) ) {
            TreeMap<String, Integer> children = map.get(curr);

            for ( String next : children.keySet() ) {
                if ( children.get(next) > 0 ) {
                    children.put( next, children.get(next) - 1 );
                    boolean res = dfs(next, map, result, size);
                    
                    if (res) 
                        return true;
                    
                    children.put( next, children.get(next) + 1 );
                }
            }
        }
        result.remove( result.size() - 1 );
        
        return false;
    }
}


// class Solution {
//     public List<String> findItinerary(List<List<String>> tickets) {
//         List<String> itinerary = new ArrayList<String>();
//         String departure = "JFK";
//         itinerary.add( departure );
//         HashMap<String, Set<String>> ourMap = new HashMap<String, Set<String>>();
        
//         // Construct hashmap of flights
//         for ( List<String> aFlight : tickets ) {
//             if ( ourMap.containsKey( aFlight.get(0) ) ) {
//                 Set<String> listDes = ourMap.get( aFlight.get(0) );
//                 listDes.add( aFlight.get(1) );
//                 ourMap.put( aFlight.get(0), listDes );
//             }
//             else {
//                 Set<String> listDes = new TreeSet<String>();
//                 listDes.add( aFlight.get(1) );
//                 ourMap.put( aFlight.get(0), listDes );
//             }
//         }
        
//         // Iterate this hashmap
//         for (Map.Entry<String, Set<String>> entry : ourMap.entrySet()) {
//             String key = entry.getKey();
//             System.out.println( "key : " + key );
//             Set<String> listDes = entry.getValue();
            
//             for ( String aDest : listDes )
//                 System.out.println( "aDest : " + aDest );
//             System.out.println( "-------------------------" );
//         }
        
//         constructItinerary( ourMap, itinerary, departure );
        
//         return itinerary;
//     }
    
//     public void constructItinerary( HashMap<String, Set<String>> ourMap, List<String> itinerary, String departure ) {
//         for ( Map.Entry<String, Set<String>> entry : ourMap.entrySet() ) {
//             if ( entry.getKey().equals( departure ) ) {
//                 if ( !entry.getValue().isEmpty() ) {
//                     // System.out.println( "entry.getValue().size() BF : " + entry.getValue().size() );
//                     itinerary.add( entry.getValue().iterator().next() );
//                     departure = entry.getValue().iterator().next();
//                     entry.getValue().remove( entry.getValue().iterator().next() );
//                     // System.out.println( "entry.getValue().size() AT : " + entry.getValue().size() );

//                     constructItinerary( ourMap, itinerary, departure );
//                 }
//             }
//         }
//     }
// }
