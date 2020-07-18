class Solution {
    public int[] plusOne(int[] digits) {
        for (int i = digits.length - 1; i >=0; i--) {
            if (digits[i] != 9) {
                digits[i]++;
                break;
            } else {
                digits[i] = 0;
            }
        }
        if (digits[0] == 0) {
            int[] res = new int[digits.length+1];
            res[0] = 1;
            return res;
        }
        return digits;
        
        
//         long originalNb = 0;
        
//         for ( int i = digits.length - 1; i >= 0; i-- ) {
//             originalNb += digits[i] * (int) Math.pow(10, digits.length - i - 1);
//         }
        
//         long result = originalNb + 1;
        
//         int nbDigits = 0;
        
//         while ( result >= Math.pow(10, nbDigits ) )
//             nbDigits++;
        
//         int[] digitsResult = new int[nbDigits];
        
//         for ( int i = nbDigits - 1; i >= 0; i-- ) {
//             digitsResult[i] = (int) (result % 10);
//             result = (long) ((result - digitsResult[i]) / 10);
//         }
        
//         return digitsResult;
    }
}
