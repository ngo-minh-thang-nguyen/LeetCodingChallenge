class Solution {
public List<List<Integer>> threeSum(int[] nums) {
    List<List<Integer>> res = new ArrayList<>();
    Arrays.sort(nums);
    for (int i = 0; i + 2 < nums.length; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {              // skip same result
            continue;
        }
        int j = i + 1, k = nums.length - 1;  
        int target = -nums[i];
        while (j < k) {
            if (nums[j] + nums[k] == target) {
                res.add(Arrays.asList(nums[i], nums[j], nums[k]));
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1]) j++;  // skip same result
                while (j < k && nums[k] == nums[k + 1]) k--;  // skip same result
            } else if (nums[j] + nums[k] > target) {
                k--;
            } else {
                j++;
            }
        }
    }
    return res;
//     List<List<Integer>> result = new ArrayList<List<Integer>>();
//     ArrayList aTriple;
//     HashMap aMap;

//     for ( int i = 0; i < nums.length; i++ ) {
//         aMap = new HashMap();
//         for ( int j = 0; j < nums.length; j++ ) {
//             if ( j != i )
//                 aMap.put( nums[j], j );
//         }

//         for ( int j = 0; j < nums.length; j++ ) {
//             // System.out.println( "remain : " + remain );
//             if ( j != i ) {
//                 if ( aMap.containsKey( 0 - nums[i] - nums[j] ) && (int) aMap.get( 0 - nums[i] - nums[j] ) != j ) {
//                     aTriple = new ArrayList<>( List.of( nums[i], nums[j], 0 - nums[i] - nums[j] ) );
//                     Collections.sort( aTriple );
//                     if ( !result.contains( aTriple ) )
//                         result.add( aTriple );
//                 }
//             }
//         }
//     }

//     return result;
}
}
