// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        unsigned int min = 1;
        unsigned int max = n;
        
        int result = findFirstBadVersion( min, max );
        return result;
    }
    
    // create new function to search for first bad version
    int findFirstBadVersion(unsigned int min, unsigned int max) {
        // basic case: if min is max, that means it is the first bad version
        if ( min == max ) return min;
        
        // determine the middle element between min and max
        unsigned mid = (min+max)/2;
        
        // divide the range [min, max] to two sub-ranges: [min, mid] and [mid+1, max]:
        // If mid is a bad version, the first bad one must be in the range [min, mid]
        if ( isBadVersion( mid ) ) return findFirstBadVersion( min, mid );
        // Otherwise, the first bad version must be in the range [mid+1, max]
        else return findFirstBadVersion( mid+1, max );
    }
};
