class Solution {
    public int addDigits( int num ) {
        while ( num >= 10 ) {
            num = findSumDigits(num);
        }
            
        return num;
    }
    
    public int findSumDigits( int num ) {
        int sum = 0;
        
        while ( num > 0 ) {
            sum += num % 10;
            num = (int) (num - num % 10) / 10;
        }
        
        return sum;
    }
}
